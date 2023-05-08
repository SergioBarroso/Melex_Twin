#!/usr/bin/python3
# -*- coding: utf-8 -*-
#
#    Copyright (C) 2022 by YOUR NAME HERE
#
#    This file is part of RoboComp
#
#    RoboComp is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    RoboComp is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with RoboComp.  If not, see <http://www.gnu.org/licenses/>.
#
from transformers.models.time_series_transformer.modeling_time_series_transformer import weighted_average

import interfaces as ifaces
import numpy as np
from numpy.linalg import inv
import time
import scipy.stats as scp
import datetime as dt
#import matplotlib.pyplot as plt
#import matplotlib.animation as animation
from PySide2.QtCore import QTimer
from PySide2.QtWidgets import QApplication
from rich.console import Console
from genericworker import *
import matplotlib
import matplotlib.pyplot as plt
matplotlib.use("TkAgg")
plt.style.use('seaborn-whitegrid')
import numpy as np
from pydsr import *
import csv
sys.path.append('/opt/robocomp/lib')
console = Console(highlight=False)
from shapely.geometry import Point, Polygon
import random
from numpy.random import randn
# If RoboComp was compiled with Python bindings you can use InnerModel in Python
# import librobocomp_qmat
# import librobocomp_osgviewer
# import librobocomp_innermodel


class SpecificWorker(GenericWorker):
    def __init__(self, proxy_map, startup_check=False):
        super(SpecificWorker, self).__init__(proxy_map)
        self.Period = 1
        
        # YOU MUST SET AN UNIQUE ID FOR THIS AGENT IN YOUR DEPLOYMENT. "_CHANGE_THIS_ID_" for a valid unique integer
        self.agent_id = 20
        self.g = DSRGraph(0, "Monitor_simulation", self.agent_id)
        self.rt_api = rt_api(self.g)
        self.robot = self.g.get_node('robot_1')
        self.current_speed_person = 0
        self.direction_to_carla = 0
        self.angle_dispersion = 360
        self.std_to_car = 1
        self.distance_dispersion = 3
        self.sensor_std_error = .1

        ##TRANSFORM MATRIX#################
        carla_init = np.array([0, 0])
        carla_fin = np.array([0, 100])
        mundo_init = np.array([-52.43419857889414, 95.23013579559326])
        mundo_fin = np.array([-25.01282223534584, -0.6501019811630249])
        v1 = carla_fin - carla_init
        v2 = mundo_fin -mundo_init

        self.angle = -np.arccos(np.dot(v1 / np.linalg.norm(v1), v2 / np.linalg.norm(v2)))
        self.R = np.array(np.array([[np.cos(self.angle), np.sin(self.angle), 0],
                                    [-np.sin(self.angle), np.cos(self.angle), 0],
                                    [0, 0, 1]]))
        self.T = np.array(np.array([[1, 0, -mundo_init[0]],
                                    [0, 1, -mundo_init[1]],
                                    [0, 0, 1]]))
        #############
        self.current_time = 0.0
        #PARA SIMULAR EN AREA RESTRINGIDA####
        # self.critical_area = Polygon([(-5927, 23791), (-5887, 14939), (14659, 15060),(14939, 23591)])
        # self.test_point=Point(9038, 20437)
        # self.person_point = Point()
        # print("TEST IN AREA:", self.critical_area.contains(self.test_point))
        self.results = {
            'valid': False,
            'fullResult': [],
            'time': 0
        }

        self.valid_result = []
        self.i = 1
        self.init_time = time.time()
        self.simulation_time = 8.0
        self.revision_time = 0.95
        self.indice = 0

        self.cond_env = {
            'indice': self.indice,
            'duration': self.simulation_time,
            'actorList': []
        }
        print("COND ENV:", self.cond_env)
        self.actor_list = []
        self.actor_id = 0
        #Obtenemos actores del DSR
        self.get_actor_from_dsr()
        self.personin = True
        #Generamos condiciones iniciales de simulación
        self.load_simulation()
        print("INICIADAS SIMULACIONES")


        # Get map TO PRINT ON MATPLOT
        self.x_path = []
        self.y_path = []
        self.get_map()
        # CARGAMOS PRIMERA RONDA SIMULACIONES
        self.carla_proxy.setSimulationParam(self.agent2interface(self.cond_env))
        if startup_check:
            self.startup_check()
        else:
            self.timer.timeout.connect(self.compute)
            self.timer.start(self.Period)
            
    def __del__(self):
        """Destructor"""

    def get_map(self):
        with open('etc/rutacompleta.csv', mode='r') as csv_file:
            csv_reader = csv.DictReader(csv_file)
            line_count = 0
            for row in csv_reader:
                if line_count == 0:
                    print(f'Column names are {", ".join(row)}')
                    line_count += 1
                #print(row["x"], row["y"])
                carla_path_point =self.world_to_carla(int(float(row["x"])), int(float(row["y"])), 0)
                self.x_path.append(carla_path_point[0])
                self.y_path.append(carla_path_point[1])
                # print("PATH", self.x_path, self.y_path)
                line_count += 1
    def setParams(self, params):
        return True


    @QtCore.Slot()
    def compute(self):
        self.current_time = time.time() - self.init_time
        if self.results['valid']:
            if self.current_time >= self.i * self.revision_time:
                self.robot = self.g.get_node('robot_1')
                self.processing()
                self.decision_making()
                self.add_pose_from_dsr()
                self.i += 1
                self.indice += 1
                self.results['valid'] = False
                self.load_simulation()
                self.personin = True
                self.carla_proxy.setSimulationParam(self.agent2interface(self.cond_env))

        else:
            self.results = self.interface2agent(self.carla_proxy.getState())
        return True


    def startup_check(self):
        QTimer.singleShot(200, QApplication.instance().quit)

    def load_simulation(self):
        self.cond_env = {
            'indice': self.indice,
            'duration': self.simulation_time,
            'actorList': self.actor_list
        }

    def get_actor_from_dsr(self):
        # Read and store people from dsr
            self.actor_list = []
            fullpose = []
            edge_rt = self.rt_api.get_edge_RT(self.g.get_node('world'), self.robot.id)
            pos = edge_rt.attrs['rt_translation'].value
            rot = edge_rt.attrs['rt_rotation_euler_xyz'].value
            carla_pose = self.world_to_carla(pos[0], pos[1], rot[2])
            fullpose.append(carla_pose)
            actor = {
                'id': self.robot.id,
                'carlaID': 0,
                'initPose': fullpose,
                'fullPose': [],
                'rol': 'ego_vehicle'
            }
            self.actor_list.append(actor)
            vehicles_nodes = self.g.get_nodes_by_type('vehicle')
            for vehicle_node in vehicles_nodes:
                fullpose = []
                edge_rt = self.rt_api.get_edge_RT(self.g.get_node("world"), vehicle_node.id)
                pos = edge_rt.attrs['rt_translation'].value
                rot = edge_rt.attrs['rt_rotation_euler_xyz'].value
                carla_pose = self.world_to_carla(pos[0], pos[1], rot[2])
                fullpose.append(carla_pose)
                actor = {
                    'id': vehicle_node.id,
                    'carlaID': 0,
                    'initPose': fullpose,
                    'fullPose': [],
                    'rol': 'vehicle'
                }
                self.actor_list.append(actor)
            people_nodes = self.g.get_nodes_by_type('person')
            for person_node in people_nodes:
                fullpose = []
                edge_rt = self.rt_api.get_edge_RT(self.g.get_node("world"), person_node.id)
                pos = edge_rt.attrs['rt_translation'].value
                self.person_point = Point(pos[0], pos[1])
                rot = edge_rt.attrs['rt_rotation_euler_xyz'].value
                carla_pose = self.world_to_carla(pos[0], pos[1], rot[2])
                fullpose.append(carla_pose)
                actor = {
                    'id': person_node.id,
                    'carlaID': 0,
                    'initPose': fullpose,
                    'fullPose': [],
                    'rol': 'person'
                }
                self.actor_list.append(actor)

    def add_pose_from_dsr(self):
        for actor in self.actor_list:
            edge_rt = self.rt_api.get_edge_RT(self.g.get_node('world'), actor['id'])
            pos = edge_rt.attrs['rt_translation'].value
            if actor["rol"] == "person":
                self.person_point = Point(pos[0], pos[1])
            rot = edge_rt.attrs['rt_rotation_euler_xyz'].value
            carla_pose = self.world_to_carla(pos[0], pos[1], rot[2])
            if len(actor['initPose']) > 4:
                actor['initPose'].pop(0)
            actor['initPose'].append(carla_pose)
            if actor["rol"] == "person":
                if len(actor['initPose']) > 1:
                    pos = np.array(actor['initPose'][-1][:2])
                    pos_ant = np.array(actor['initPose'][-2][:2])
                    velocity_vector = (pos - pos_ant)
                    self.current_speed_person = np.linalg.norm(velocity_vector) / self.revision_time #TODO: GENERALIZACIÓN N PERSONAS CON DICCIONARIO AAAA
                    #FACTORES DE DISPERSIÓN DEL PEATÓN
                    factor = self.current_speed_person/2
                    self.distance_dispersion = 2 + 2*factor
                    self.angle_dispersion = 360 - 315*factor
    def processing(self):
        x_init_person = []
        y_init_person = []
        x_final_person = []
        y_final_person = []
        x_final_person_gen_ant = []
        y_final_person_gen_ant = []
        total_angulo = []
        angulo_y_error = []
        x_final_person_discard = []
        y_final_person_discard = []
        x_init_car = []
        y_init_car = []
        x_final_car = []
        y_final_car = []
        processerror = []
        processangulo = []
        processdist = []
        vectorposes = []
        error_angulo = 360
        fullresult = self.results['fullResult']
        fullresult = fullresult + self.valid_result
        self.valid_result = []
        for result in fullresult:
            actor_info = result['actorList']
            indice_resultado = result['indice']
            correct = 0
            # for actor in actor_info:
            for i in range(0, len(actor_info)):
                if (len(actor_info[i]['fullPose'])>0):
                    ind = self.indice - indice_resultado
                    pose = actor_info[i]['fullPose'][-1]
                    try:
                        if ind < len(actor_info[i]['fullPose']):
                            pose_rev = actor_info[i]['fullPose'][ind]
                            diff_carla = np.array(pose) - np.array(pose_rev)
                            alfa_carla = np.rad2deg(np.arctan2(diff_carla[1], diff_carla[0]))
                            print("ANGULO CARLA: ", alfa_carla)
                            edge_rt = self.rt_api.get_edge_RT(self.g.get_node("world"), actor_info[i]['id'])
                            x, y, _ = edge_rt.attrs['rt_translation'].value
                            rot_copp = edge_rt.attrs['rt_rotation_euler_xyz'].value

                            carla_pose = self.world_to_carla(x, y, rot_copp[2])
                            xc = carla_pose[0]
                            yc = carla_pose[1]
                            alfa_copp = carla_pose[2]
                            #alfa_copp = self.__gaussian_distribution(alfa_copp, 20)

                            diff_alfas = np.deg2rad(alfa_carla) - np.deg2rad(alfa_copp)

                            if diff_alfas < -np.pi:
                                diff_alfas = diff_alfas + 2*np.pi
                            elif diff_alfas > np.pi:
                                diff_alfas = diff_alfas - 2 * np.pi

                            diff_alfas = np.rad2deg(diff_alfas)

                            error = np.sqrt(np.power(xc - pose_rev[0], 2) + np.power(yc - pose_rev[1], 2))
                            #print("POSE_REV", pose_rev)

                            if actor_info[i]['rol'] == 'person':
                                # print("PERSON ERROR:", error)
                                for actor in self.actor_list:
                                    if actor["id"] == actor_info[i]['id']:
                                        x_init_person.append(actor['initPose'][-1][0])
                                        y_init_person.append(actor['initPose'][-1][1])
                                        found = True
                                        break
                                print("DIFERENCIA ALFAS: ", diff_alfas)
                                if error <= self.distance_dispersion and diff_alfas <= self.angle_dispersion/2 and diff_alfas >= -self.angle_dispersion/2 :
                                    if ind == 0:
                                        x_final_person.append(pose[0])
                                        y_final_person.append(pose[1])
                                    else:
                                        # print("EXISTEN ANTERIORES")
                                        x_final_person_gen_ant.append(pose[0])
                                        y_final_person_gen_ant.append(pose[1])

                                    dist = np.sqrt(np.power(xc - pose_rev[0], 2) + np.power(yc - pose_rev[1], 2))
                                    processdist.append(dist)
                                    vectorposes.append([pose_rev[0], pose_rev[1]])
                                    processerror.append(diff_alfas)
                                    processangulo.append(alfa_carla)
                                    angulo_y_error.append({"angulo":alfa_carla, "error":diff_alfas})
                                    total_angulo.append(alfa_carla)
                                    correct += 1

                            elif actor_info[i]['rol'] == 'ego_vehicle':
                                for actor in self.actor_list:
                                    if actor["id"] == actor_info[i]['id']:
                                        x_init_car.append(actor['initPose'][-1][0])
                                        y_init_car.append(actor['initPose'][-1][1])
                                        found = True
                                        break
                                x_final_car.append(pose[0])
                                y_final_car.append(pose[1])
                                correct += 1
                                # else:
                                #     print("Incorrect person simulation", error)
                            else:
                                # if error <= 5:
                                correct += 1
                        else:
                            continue
                    except:
                            print("-----------------------------------------")
                            print("INDICE ACTUAL: ", self.indice)
                            print("INDICE POSICION FULL POSE", ind)
                            print("INDICE DE RESULTADO: ", indice_resultado)
                            #print(result)





                        # else:
                            # print("Incorrect vehicle simulation", error)
                    #actor_info[i]['fullPose'].pop(0)
            # print("Total ERROR:", total_error)

            if correct == len(actor_info):
                self.valid_result.append(result)
            
            # else:
                # print(i, "Simulación erronea en ", len(actor_info)-correct, "de ", len(actor_info))
        # print("Simulaciones válidas: ", len(fullresult))

        plt.scatter(x_final_person, y_final_person, s=10, color='orange')
        plt.scatter(x_final_person_gen_ant, y_final_person_gen_ant, s=10, color='orange')
        plt.scatter(x_init_person, y_init_person, s=25, color='red')
        #plt.scatter(x_final_person_discard, y_final_person_discard, s=5, color='cyan')
        plt.scatter(x_init_car, y_init_car, s=25, color='purple')
        plt.scatter(x_final_car, y_final_car, s=10, color='green')
        plt.scatter(self.x_path, self.y_path, s=10, color='black', marker="v")
        plt.title("Simulation final poses")

        plt.xlabel("X-Axis")
        plt.ylabel("Y-Axis")
        
        plt.xlim([-7.5, 62.5])
        plt.ylim([80, 150])
        plt.pause(0.000000001)
        plt.clf()

        if len(total_angulo) > 0:


            # PF step 1 Random particles
            if self.current_speed_person < 0.1:
                self.direction_to_carla = alfa_copp
                self.std_to_car = 90
            # Discard simulations
            elif len(processangulo) < 3:
                self.direction_to_carla = alfa_copp
                self.std_to_car = 15
            # Moving situation
            else:

                self.Filtro(processerror,processangulo, angulo_y_error)


    def Filtro(self, error, ang, angulo_y_error):

        npError = np.array(error)
        npAng = np.array(ang)

        maxe = npError.max()
        mine = npError.min()
        weights = []
        if mine - maxe != 0:
            npPesos = (npError - maxe) / (mine - maxe)
        else:
            npPesos = np.array([1])
        for count, i in enumerate(angulo_y_error):
            i["peso"] = npPesos[count] / sum(npPesos)
            weights.append(npPesos[count] / sum(npPesos))
        # print("DICCIONARIO: ", angulo_y_error)
        # print("npAng: ", npAng)
        # print("PESOS: ", weights)
        # print("ANGULO COPPELIA: ", alfa_copp)
        # print("SUMA PESOS: ", sum(weights))
        N = len(weights)

        # Resampling method
        if self.neff(weights) < N / 2:
            indexes = self.systematic_resample(weights)
            weights, npAng = self.resample_from_index(npAng, weights, indexes)

        mean = np.average(npAng, weights=weights)
        var = np.average((npAng - mean) ** 2, weights=weights)

        # print("MEAN PARA SIMULACIONES:", mean)
        # print("VAR PARA SIMULACIONES:", var)
        # print("MEAN COPPELIA:", alfa_copp)

        std = np.sqrt(var)

        self.direction_to_carla = mean
        self.std_to_car = std

    def Average(self, lst):
        return sum(lst) / len(lst)
    def decision_making(self):
        # print("Resultados validos", len(self.valid_result))
        collision_cont = 0
        brake_cont = 0
        collision_time = []
        # print("valid_result", self.valid_result[0]['actorList'][0]['fullPose'])
        for res in self.valid_result:
            if res['collision']['iscollision']:
                self.actor_id = res['collision']['actorcollision']
                time_collision = res['collision']['timecollision']-(self.indice - res['indice'])*self.revision_time
                if time_collision > 0:
                    collision_cont += 1
                    collision_time.append(time_collision-0.6)
            if res['isBrake']:
                brake_cont += 1
        # if (len(self.valid_result)==0):
        #     # print("Collision", 0, collision_time)
        #     print("Brake", 0)
        # else:
            # print("Collision", collision_cont/len(self.valid_result), collision_time)
            # print("Brake",brake_cont/len(self.valid_result))
        if collision_cont > 0:
            virtual_collision = self.g.get_edge(self.robot.id, self.actor_id, 'virtual_collision')
            if virtual_collision is None:
                collision = Edge(self.robot.id, self.actor_id, 'virtual_collision', self.agent_id)
                collision.attrs['collision'] = Attribute(collision_cont/len(self.valid_result), self.agent_id)
                collision.attrs['time_collision'] = Attribute(collision_time, self.agent_id)
                self.g.insert_or_assign_edge(collision)
            else:
                virtual_collision.attrs['collision'] = Attribute(collision_cont/len(self.valid_result), self.agent_id)
                virtual_collision.attrs['time_collision'] = Attribute(collision_time, self.agent_id)
                self.g.insert_or_assign_edge(virtual_collision)
        else:
            self.g.delete_edge(self.actor_id, self.robot.id, 'virtual_collision')
        # print(brake_cont)
        if brake_cont > 0:
            virtual_brake = self.g.get_edge(self.robot.id, self.robot.id, 'virtual_brake')
            if virtual_brake is None:
                brake = Edge(self.robot.id, self.robot.id, 'virtual_brake', self.agent_id)
                brake.attrs['brake'] = Attribute(brake_cont / len(self.valid_result), self.agent_id)
                self.g.insert_or_assign_edge(brake)
            else:
                virtual_brake.attrs['brake'] = Attribute(brake_cont / len(self.valid_result), self.agent_id)
                self.g.insert_or_assign_edge(virtual_brake)
        else:
            self.g.delete_edge(self.robot.id, self.robot.id, 'virtual_brake')
        # self.indice = 0
        # print('RESULTADOS VALIDOS', len(self.valid_result))
        # print(self.valid_result)
        # for result in self.valid_result:
        #     virtual_brake = self.g.get_edge(self.robot.id, self.robot.id, 'virtual_brake')
        #     if virtual_brake is None and result['isBrake']:
        #         print("Insert is_brake virtual edge")
        #         brake = Edge(self.robot.id, self.robot.id, 'virtual_brake', self.agent_id)
        #         self.g.insert_or_assign_edge(brake)
        #     # virtual_collision = self.g.get_edge(self.robot.id, self.robot.id, 'virtual_collision')
        #     # print(virtual_collision)
        #     if result['collision']['iscollision']:
        #         collision = Edge(self.robot.id,result['collision']['actorcollision'], 'virtual_collision', self.agent_id)
        #         self.g.insert_or_assign_edge(collision)
        #         print("Insert collision virtual edge")
        # self.valid_result = []

    def interface2agent(self, interface_data):
        result = []
        for res in interface_data.fullresult:
            simresult = {
                'indice': res.indice,
                'collision': {
                    'iscollision': res.collision.iscollision,
                    'timecollision': res.collision.timecollision,
                    'actorcollision': res.collision.actorcollision
                },
                'isBrake': res.isbrake,
                'actorList': []
            }
            for actor in res.actorlist:
                act = {
                    'id': actor.id,
                    'carlaID': actor.carlaid,
                    'initPose': [],
                    'fullPose': [],
                    'rol': actor.rol
                }
                for pose in actor.pose:
                    act['fullPose'].append([pose.tx, pose.ty, pose.rz])
                simresult['actorList'].append(act)
            result.append(simresult)
        data = {
            'valid': interface_data.valid,
            'time': interface_data.time,
            'fullResult': result
        }
        return data

    def agent2interface(self, cond_env):
        cond_sim = ifaces.RoboCompCarla.Simulations()
        cond_sim.indice = cond_env['indice']
        cond_sim.duration = cond_env['duration']
        cond_sim.actorlist = ifaces.Actors()
        cond_sim.direction = self.direction_to_carla
        cond_sim.speeddesv = self.distance_dispersion
        cond_sim.directiondesv = self.std_to_car
        for actor in cond_env['actorList']:
            act = ifaces.RoboCompCarla.Actor()
            act.id = actor['id']
            act.carlaid = actor['carlaID']
            act.rol = actor['rol']
            act.initpose = ifaces.Fullposedata()
            act.pose = ifaces.Fullposedata()
            for pose in actor['initPose']:
                pos = ifaces.RoboCompCarla.Posedata(pose[0], pose[1], 0, 0, 0, pose[2])
                act.initpose.append(pos)
            cond_sim.actorlist.append(act)
        print("CARGA SIMULACIONES ")
        return cond_sim

    def world_to_carla(self, x, y, alfa):
        # carla_point = self.R @ (np.array([x/1000, y/1000]) - self.trans).T
        carla_point = self.R @ (self.T @ np.array([x/1000, y/1000, 1.0]).T)
        alfa = -np.rad2deg(alfa)-74
        return [-carla_point[0], carla_point[1], alfa]
    ######################
    # From the RoboCompCarla you can call this methods:
    # self.carla_proxy.getState(...)
    # self.carla_proxy.setSimulationParam(...)

    ######################
    # From the RoboCompCarla you can use this types:
    # RoboCompCarla.Posedata
    # RoboCompCarla.Actor
    # RoboCompCarla.Simulations
    # RoboCompCarla.Collision
    # RoboCompCarla.Simresult
    # RoboCompCarla.Results

    def __gaussian_distribution(self, mean, std):
        dist_gauss = scp.norm(mean, std)
        valor = dist_gauss.rvs()
        return valor
    # =============== DSR SLOTS  ================
    # =============================================

    def update_node_att(self, id: int, attribute_names: [str]):
        console.print(f"UPDATE NODE ATT: {id} {attribute_names}", style='green')

    def update_node(self, id: int, type: str):
        console.print(f"UPDATE NODE: {id} {type}", style='green')

    def delete_node(self, id: int):
        console.print(f"DELETE NODE:: {id} ", style='green')

    def update_edge(self, fr: int, to: int, type: str):

        console.print(f"UPDATE EDGE: {fr} to {type}", type, style='green')

    def update_edge_att(self, fr: int, to: int, type: str, attribute_names: [str]):
        console.print(f"UPDATE EDGE ATT: {fr} to {type} {attribute_names}", style='green')

    def delete_edge(self, fr: int, to: int, type: str):
        console.print(f"DELETE EDGE: {fr} to {type} {type}", style='green')

    def systematic_resample(self, weights):
        N = len(weights)

        # make N subdivisions, choose positions
        # with a consistent random offset
        positions = (np.arange(N) + random.random()) / N

        indexes = np.zeros(N, 'i')
        cumulative_sum = np.cumsum(weights)
        i, j = 0, 0
        while i < N:
            if positions[i] < cumulative_sum[j]:
                indexes[i] = j
                i += 1
            else:
                j += 1
        return indexes

    def multinomal_resample(self, weights):
        cumulative_sum = np.cumsum(weights)
        cumulative_sum[-1] = 1.  # avoid round-off errors
        return np.searchsorted(cumulative_sum, random(len(weights)))

    def residual_resample(self, weights):
        N = len(weights)
        indexes = np.zeros(N, 'i')

        # take int(N*w) copies of each weight
        num_copies = (N * np.asarray(weights)).astype(int)
        k = 0
        for i in range(N):
            for _ in range(num_copies[i]):  # make n copies
                indexes[k] = i
                k += 1

        # use multinormial resample on the residual to fill up the rest.
        residual = w - num_copies  # get fractional part
        residual /= sum(residual)  # normalize
        cumulative_sum = np.cumsum(residual)
        cumulative_sum[-1] = 1.  # ensures sum is exactly one
        indexes[k:N] = np.searchsorted(cumulative_sum, random(N - k))

        return indexes

    def stratified_resample(self, weights):
        N = len(weights)
        # make N subdivisions, chose a random position within each one
        positions = (random(N) + range(N)) / N

        indexes = np.zeros(N, 'i')
        cumulative_sum = np.cumsum(weights)
        i, j = 0, 0
        while i < N:
            if positions[i] < cumulative_sum[j]:
                indexes[i] = j
                i += 1
            else:
                j += 1
        return indexes

    def resample_from_index(self, particles, weights, indexes):
        particles[:] = particles[indexes]
        weights.resize(len(particles))
        weights.fill(1.0 / len(weights))
        return weights , particles

    def neff(self, weights):
        return 1. / np.sum(np.square(weights))

