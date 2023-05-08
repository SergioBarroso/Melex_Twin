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
import interfaces as ifaces
import numpy as np
from numpy.linalg import inv
import time
import datetime as dt
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt

import matplotlib.animation as animation
from PySide2.QtCore import QTimer
from PySide2.QtWidgets import QApplication
from rich.console import Console
from genericworker import *
from pydsr import *
sys.path.append('/opt/robocomp/lib')
console = Console(highlight=False)
import json
from numpy import linalg as LA
# If RoboComp was compiled with Python bindings you can use InnerModel in Python
# import librobocomp_qmat
# import librobocomp_osgviewer
# import librobocomp_innermodel


class SpecificWorker(GenericWorker):
    def __init__(self, proxy_map, startup_check=False):
        super(SpecificWorker, self).__init__(proxy_map)
        self.Period = 50

        # YOU MUST SET AN UNIQUE ID FOR THIS AGENT IN YOUR DEPLOYMENT. "_CHANGE_THIS_ID_" for a valid unique integer
        self.agent_id = 26
        self.g = DSRGraph(0, "Monitor_simulation", self.agent_id)
        self.rt_api = rt_api(self.g)
        self.inner_api = inner_api(self.g)

        self.jsondata ={
            "Brake_P":[],
            "Collision_P":[],
            "T_T_Collision":[],
            "Distance_V2P": [],
            "Adv_speed":[],
            "Rot_speed":[]
        }
        ##TRANSFORM##
      
        #     signals.connect(self.g, signals.UPDATE_NODE_ATTR, self.update_node_att)
        #     signals.connect(self.g, signals.UPDATE_NODE, self.update_node)
        #     signals.connect(self.g, signals.DELETE_NODE, self.delete_node)
        #     signals.connect(self.g, signals.UPDATE_EDGE, self.update_edge)
        #     signals.connect(self.g, signals.UPDATE_EDGE_ATTR, self.update_edge_att)
        #     signals.connect(self.g, signals.DELETE_EDGE, self.delete_edge)
        #     console.print("signals connected")
        # except RuntimeError as e:
        #     print(e)
        self.seconds = 0
        self.robot_node = self.g.get_node("robot_1")
        self.fig = plt.figure(figsize=(12, 12))
        #self.fig.xlabel("TIME (s)")
        # self.ax = self.fig.add_subplot(511)
        # self.ax.title.set_text('Brake Probability')


        self.bx = self.fig.add_subplot(411)
        self.bx.set_title('Collision Probability')
        self.tx = self.fig.add_subplot(412)
        self.rx = self.fig.add_subplot(413)
        #self.vx = self.fig.add_subplot(615)
        self.dx = self.fig.add_subplot(414)
        self.rx.title.set_text('Normalized Advance Speed')
        #self.vx.title.set_text('Normalized Rot Speed')
        self.dx.title.set_text('Pedestrian to Vehicle Distance')
        self.tx.set_title('Time to Collision')
        # self.ax.set(ylim=(0, 1))
        self.bx.set(ylim=(0, 1))
        self.tx.set(ylim=(0, 10))
        self.rx.set(ylim=(0, 1))
        #self.vx.set(ylim=(0, 1))
        self.dx.set(ylim=(0, 60))
        self.xs = []
        self.ys = []
        self.cs = []
        self.ts = []
        self.rs = []
        self.vs = []
        self.ds = []
        self.ani = animation.FuncAnimation(self.fig, self.animate, fargs=(self.xs, self.ys, self.cs, self.ts, self.rs, self.vs, self.ds), interval=1000)
        plt.show()
        self.tojson()
        if startup_check:
            self.startup_check()
        else:
            self.timer.timeout.connect(self.compute)
            self.timer.start(self.Period)

    def __del__(self):
        """Destructor"""

    def tojson(self):
        f = open(dt.datetime.now().strftime('%H:%M:%S.%f')+'.json', 'w')
        json.dump(self.jsondata, f)
        f.close()
    def animate(self, i, xs, ys, cs, ts, rs, vs, ds):
        self.inner_api = inner_api(self.g)
        self.robot_node = self.g.get_node("robot_1")
        # Read temperature (Celsius) from TMP102
        # virtual_brake = self.g.get_edge(self.robot.id, self.robot.id, 'virtual_brake')
        virtual_brakes = self.g.get_edges_by_type('virtual_brake')
        print(virtual_brakes)
        valor_brake = 0
        for virtual_brake in virtual_brakes:
            valor_brake = virtual_brake.attrs['brake'].value
        self.jsondata["Brake_P"].append(valor_brake)


        person_node = self.g.get_node("person_0")
        if person_node:
            distance_r_T_p = self.inner_api.transform(person_node.name, self.robot_node.name)
            distance = LA.norm(distance_r_T_p)/1000
        else:
            distance = 70

        self.jsondata["Distance_V2P"].append(distance)
        # if virtual_brake is None:
        #     valor_brake = 0
        # else:
        #     valor_brake = virtual_brake.attrs['brake'].value

        
        if "robot_ref_adv_speed" in self.robot_node.attrs and "robot_ref_rot_speed" in self.robot_node.attrs:
            print(self.robot_node.attrs["robot_ref_adv_speed"].value)
            adv_speed = self.robot_node.attrs["robot_ref_adv_speed"].value/1000
            rot_speed = self.robot_node.attrs["robot_ref_rot_speed"].value
        else:
            adv_speed = 0
            rot_speed = 0
        #adv_speed = self.robot_node.attrs["robot_ref_adv_speed"].value/1000
        self.jsondata["Adv_speed"].append(float(adv_speed))
        # self.jsondata["Rot_speed"].append(rot_speed)
        virtual_collision = self.g.get_edges_by_type('virtual_collision')
        #valor_collision_ADULT = 0
        #valor_collision_CHILD = 0
        valor_collision = 0
        time_collision = 31
        for cll in virtual_collision:
            valor_collision = cll.attrs['collision'].value
            # self.jsondata["Collision_P"].append(valor_collision)
            time_collision = min(cll.attrs['time_collision'].value)

        # for cll in virtual_collision:
        #     node = self.g.get_node(cll.origin)
        #     if node:
        #         if node.name == "person_0":
        #             valor_collision_ADULT= cll.attrs['collision'].value
        #         elif node.name == "person_1":
        #             # rs.append(cll.attrs['collision'].value)
        #             valor_collision_CHILD = cll.attrs['collision'].value
        #     # self.jsondata["Collision_P"].append(valor_collision)
        #     time_collision = min(cll.attrs['time_collision'].value)
        self.jsondata["Collision_P"].append(valor_collision)
        self.jsondata["T_T_Collision"].append(float(time_collision))

        # Add x and y to lists
        self.seconds = self.seconds +1
        xs.append(self.seconds)
        #xs.append(dt.datetime.now().strftime('%H:%M:%S.%f'))
        ys.append(valor_brake)
        cs.append(valor_collision)
        rs.append(adv_speed)
        ts.append(time_collision)
        # vs.append(rot_speed)
        ds.append(distance)

        # Limit x and y lists to 20 items
        xs = xs[-20:]
        ys = ys[-20:]
        cs = cs[-20:]
        ts = ts[-20:]
        rs = rs[-20:]
        vs = vs[-20:]
        ds = ds[-20:]
        #print(self.jsondata)
        # Draw x and y lists
        #self.ax.clear()
        self.bx.clear()
        self.tx.clear()
        self.rx.clear()
        # self.vx.clear()
        self.dx.clear()
        #self.ax.title.set_text('Brake Probability')
        # self.ax.set_ylabel("Probability")
        # self.ax.set_xlabel("Time (s)")
        self.bx.title.set_text('Collision Probability')
        self.bx.set_ylabel("Probability")
        self.bx.set_xlabel("Time (s)")
        self.rx.title.set_text('Normalized Speed')
        self.rx.set_ylabel("Normalized Speed")
        self.rx.set_xlabel("Time (s)")
        # self.vx.title.set_text('Normalized Rotation Speed')
        # self.vx.set_ylabel("Speed (rad/s)")
        # self.vx.set_xlabel("Time (s)")
        self.tx.title.set_text('Time to Collision')
        self.tx.set_ylabel("Time (s)")
        self.tx.set_xlabel("Time (s)")
        self.dx.title.set_text('Pedestrian to Vehicle Distance')
        self.dx.set_ylabel("Distance (m)")
        self.dx.set_xlabel("Time (s)")
        # self.ax.set(ylim=(0, 1))
        self.bx.set(ylim=(0, 1))
        self.tx.set(ylim=(0, 10))
        self.rx.set(ylim=(0, 1))
        #self.vx.set(ylim=(0, 1))
        self.dx.set(ylim=(0, 70))
        # self.ax.plot(xs, ys, 'r')
        self.bx.plot(xs, cs, 'g')
        self.tx.plot(xs, ts, 'b')
        self.rx.plot(xs, rs, 'y')
        #self.vx.plot(xs, vs, 'p')
        self.dx.plot(xs, ds, 'o')


        # Format plot
        plt.xticks(rotation=45, ha='right')
        plt.subplots_adjust(bottom=0.10, hspace=0.7)

       # plt.title('Brake Probability')
        #plt.ylabel('Probability')
    def setParams(self, params):
        # try:
        #	self.innermodel = InnerModel(params["InnerModelPath"])
        # except:
        #	traceback.print_exc()
        #	print("Error reading config params")
        return True


    @QtCore.Slot()
    def compute(self):
        # self.inner_api = inner_api(self.g)
        # # Read temperature (Celsius) from TMP102
        # # virtual_brake = self.g.get_edge(self.robot.id, self.robot.id, 'virtual_brake')
        # virtual_brakes = self.g.get_edges_by_type('virtual_brake')
        # print(virtual_brakes)
        # valor_brake = 0
        # for virtual_brake in virtual_brakes:
        #     valor_brake = virtual_brake.attrs['brake'].value
        # self.jsondata["Brake_P"].append(valor_brake)
        #
        # person_node = self.g.get_node("person_0")
        # if person_node:
        #     distance_r_T_p = self.inner_api.transform(person_node.name, self.robot_node.name)
        #     distance = LA.norm(distance_r_T_p) / 1000
        # else:
        #     distance = 70
        #
        # self.jsondata["Distance_V2P"].append(distance)
        # # if virtual_brake is None:
        # #     valor_brake = 0
        # # else:
        # #     valor_brake = virtual_brake.attrs['brake'].value
        #
        # if self.robot_node.attrs["robot_ref_adv_speed"].value:
        #     print(self.robot_node.attrs["robot_ref_adv_speed"].value)
        #     adv_speed = self.robot_node.attrs["robot_ref_adv_speed"].value / 1000
        #     rot_speed = self.robot_node.attrs["robot_ref_rot_speed"].value
        # else:
        #     adv_speed = 0
        #     rot_speed = 0
        # self.jsondata["Adv_speed"].append(adv_speed)
        # self.jsondata["Rot_speed"].append(rot_speed)
        # virtual_collision = self.g.get_edges_by_type('virtual_collision')
        # # valor_collision_ADULT = 0
        # # valor_collision_CHILD = 0
        # valor_collision = 0
        # time_collision = 31
        # for cll in virtual_collision:
        #     valor_collision = cll.attrs['collision'].value
        #     # self.jsondata["Collision_P"].append(valor_collision)
        #     time_collision = min(cll.attrs['time_collision'].value)
        #
        # # for cll in virtual_collision:
        # #     node = self.g.get_node(cll.origin)
        # #     if node:
        # #         if node.name == "person_0":
        # #             valor_collision_ADULT= cll.attrs['collision'].value
        # #         elif node.name == "person_1":
        # #             # rs.append(cll.attrs['collision'].value)
        # #             valor_collision_CHILD = cll.attrs['collision'].value
        # #     # self.jsondata["Collision_P"].append(valor_collision)
        # #     time_collision = min(cll.attrs['time_collision'].value)
        # # self.jsondata["Collision_P"].append(valor_collision)
        # self.jsondata["T_T_Collision"].append(time_collision)
        #
        # # Add x and y to lists
        # self.seconds = self.seconds + 1
        # self.xs.append(self.seconds)
        # # xs.append(dt.datetime.now().strftime('%H:%M:%S.%f'))
        # self.ys.append(valor_brake)
        # self.cs.append(valor_collision)
        # self.rs.append(adv_speed)
        # self.ts.append(time_collision)
        # self.vs.append(rot_speed)
        # self.ds.append(distance)
        #
        # # Limit x and y lists to 20 items
        # self.xs = self.xs[-20:]
        # self.ys = self.ys[-20:]
        # self.cs = self.cs[-20:]
        # self.ts = self.ts[-20:]
        # self.rs = self.rs[-20:]
        # self.vs = self.vs[-20:]
        # self.ds = self.ds[-20:]
        # # print(self.jsondata)
        # # Draw x and y lists
        # self.ax.clear()
        # self.bx.clear()
        # self.tx.clear()
        # self.rx.clear()
        # self.vx.clear()
        # self.dx.clear()
        # self.ax.title.set_text('Brake Probability')
        # self.ax.set_ylabel("Probability")
        # self.ax.set_xlabel("Time (s)")
        # self.bx.title.set_text('Collision Probability')
        # self.bx.set_ylabel("Probability")
        # self.bx.set_xlabel("Time (s)")
        # self.rx.title.set_text('Normalized Advance Speed')
        # self.rx.set_ylabel("Speed (m/s)")
        # self.rx.set_xlabel("Time (s)")
        # self.vx.title.set_text('Normalized Rotation Speed')
        # self.vx.set_ylabel("Speed (rad/s)")
        # self.vx.set_xlabel("Time (s)")
        # self.tx.title.set_text('Time Collision')
        # self.tx.set_ylabel("Time_t_collision (s)")
        # self.tx.set_xlabel("Time (s)")
        # self.dx.title.set_text('Distance V2P')
        # self.dx.set_ylabel("Distance (m)")
        # self.dx.set_xlabel("Time (s)")
        # self.ax.set(ylim=(0, 1))
        # self.bx.set(ylim=(0, 1))
        # self.tx.set(ylim=(0, 30))
        # self.rx.set(ylim=(0, 1))
        # self.vx.set(ylim=(0, 1))
        # self.dx.set(ylim=(0, 70))
        # self.ax.plot(self.xs, ys, 'r')
        # self.bx.plot(xs, self.cs, 'g')
        # self.tx.plot(self.xs, self.ts, 'b')
        # self.rx.plot(self.xs, self.rs, 'y')
        # self.vx.plot(self.xs, self.vs, 'p')
        # self.dx.plot(self.xs, self.ds, 'o')
        #
        # # Format plot
        # plt.xticks(rotation=45, ha='right')
        # plt.subplots_adjust(bottom=0.10, hspace=0.7)
        # # self.tojson()
        # self.__del__()

        return False



    def startup_check(self):
        QTimer.singleShot(200, QApplication.instance().quit)

    


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
