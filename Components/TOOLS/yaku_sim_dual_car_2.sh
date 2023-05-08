#!/bin/bash

sleep 2      

TERMINAL_ID_0=$(qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.terminalIdsForSessionId 0)

qdbus org.kde.yakuake /yakuake/tabs setTabTitle 0 "Coppelia-IDSERVER"

qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.splitTerminalLeftRight "$TERMINAL_ID_0"

SESSION_ID_1=$(qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.addSession)
TERMINAL_ID_1=$(qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.terminalIdsForSessionId 1)

qdbus org.kde.yakuake /yakuake/tabs setTabTitle 1 "DSR-MISSION"

qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.splitTerminalLeftRight "$TERMINAL_ID_1"

SESSION_ID_2=$(qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.addSession)
TERMINAL_ID_2=$(qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.terminalIdsForSessionId 2)

qdbus org.kde.yakuake /yakuake/tabs setTabTitle 2 "Followers"

qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.splitTerminalLeftRight "$TERMINAL_ID_2"
#qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.splitTerminalLeftRight "$TERMINAL_ID_2"
#qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.splitTerminalTopBottom "$TERMINAL_ID_2"
#qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.splitTerminalTopBottom "$TERMINAL_ID_2"

SESSION_ID_3=$(qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.addSession)
TERMINAL_ID_3=$(qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.terminalIdsForSessionId 3)

qdbus org.kde.yakuake /yakuake/tabs setTabTitle 3 "API"

SESSION_ID_4=$(qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.addSession)
TERMINAL_ID_4=$(qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.terminalIdsForSessionId 4)

qdbus org.kde.yakuake /yakuake/tabs setTabTitle 4 "CARLASIMS"

qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.splitTerminalLeftRight "$TERMINAL_ID_4"
#qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.splitTerminalLeftRight "$TERMINAL_ID_3"

SESSION_ID_5=$(qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.addSession)
TERMINAL_ID_5=$(qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.terminalIdsForSessionId 5)

qdbus org.kde.yakuake /yakuake/tabs setTabTitle 5 "JOYSTICK"

#qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.splitTerminalLeftRight "$TERMINAL_ID_4"
#qdbus org.kde.yakuake /yakuake/sessions org.kde.yakuake.splitTerminalLeftRight "$TERMINAL_ID_3"

#Coppelia
qdbus org.kde.yakuake /yakuake/sessions runCommandInTerminal 0 "killall -9 python3"
qdbus org.kde.yakuake /yakuake/sessions runCommandInTerminal 0 "rcnode&"
qdbus org.kde.yakuake /yakuake/sessions runCommandInTerminal 0 "cd ~/robocomp/components/MelexTwin/Sim/components/pioneer_pyrep_2cars"
qdbus org.kde.yakuake /yakuake/sessions runCommandInTerminal 0 "./run.sh"

qdbus org.kde.yakuake /yakuake/sessions runCommandInTerminal 1 "cd ~/robocomp/components/MelexTwin/Sim/agents/idserver"
qdbus org.kde.yakuake /yakuake/sessions runCommandInTerminal 1 "bin/idserver etc/config_dual_car"

#DSR
qdbus org.kde.yakuake /yakuake/sessions runCommandInTerminal 2 "cd ~/robocomp/components/MelexTwin/Sim/agents/melex_dsr_coppelia_dual_car"
qdbus org.kde.yakuake /yakuake/sessions runCommandInTerminal 2 "bin/pioneer_dsr etc/config"

qdbus org.kde.yakuake /yakuake/sessions runCommandInTerminal 3 "cd ~/robocomp/components/MelexTwin/CARLASIMS/plotresults_agent"
qdbus org.kde.yakuake /yakuake/sessions runCommandInTerminal 3 "src/plotresults.py etc/config"

qdbus org.kde.yakuake /yakuake/sessions runCommandInTerminal 4 "cd ~/robocomp/components/MelexTwin/Sim/agents/path_follower_melex_dual_sim"
qdbus org.kde.yakuake /yakuake/sessions runCommandInTerminal 4 "bin/path_follower etc/config_coppelia_melex_dual_m1"

#API
qdbus org.kde.yakuake /yakuake/sessions runCommandInTerminal 6 "cd ~/robocomp/components/MelexTwin/Sim/agents/api_communicator_dual_car"
qdbus org.kde.yakuake /yakuake/sessions runCommandInTerminal 6 "src/api_communicator.py etc/config"

qdbus org.kde.yakuake /yakuake/sessions runCommandInTerminal 7 "ssh crivac@192.168.50.249"
qdbus org.kde.yakuake /yakuake/sessions runCommandInTerminal 7 "cd CARLA13/CARLA_0.9.13"
qdbus org.kde.yakuake /yakuake/sessions runCommandInTerminal 7 "bash allservers.sh"

qdbus org.kde.yakuake /yakuake/sessions runCommandInTerminal 8 "cd ~/robocomp/components/MelexTwin/CARLASIMS/monitor_simulation"
qdbus org.kde.yakuake /yakuake/sessions runCommandInTerminal 8 "src/monitor_simulation.py etc/config"

sleep 6

#components
qdbus org.kde.yakuake /yakuake/sessions runCommandInTerminal 5 "cd ~/robocomp/components/MelexTwin/Sim/components/human_social_spaces_dsr"
qdbus org.kde.yakuake /yakuake/sessions runCommandInTerminal 5 "src/human_social_spaces_dsr.py etc/config"

#qdbus org.kde.yakuake /yakuake/sessions runCommandInTerminal 9 "cd ~/robocomp/components/robocomp-robolab/components/hardware/external_control/joystickpublish"
#qdbus org.kde.yakuake /yakuake/sessions runCommandInTerminal 9 "bin/JoystickPublish etc/config_giraff_bill"






