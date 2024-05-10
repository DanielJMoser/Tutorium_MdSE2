cmake_minimum_required(VERSION 3.28)
project(Uez6_Robot)

set(CMAKE_CXX_STANDARD 17)

add_executable(Uez6_Robot main.cpp
        Sensor.cpp
        Sensor.h
        CameraSensor.cpp
        CameraSensor.h
        CliffSensor.cpp
        CliffSensor.h
        DistanceSensor.cpp
        DistanceSensor.h
        Motor.cpp
        Motor.h
        Robot.cpp
        Robot.h
        RobotException.cpp
        RobotException.h)
