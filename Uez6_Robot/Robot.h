//
// Created by danielm on 26.05.22.
//

#ifndef ROBOT1_ROBOT_H
#define ROBOT1_ROBOT_H


#include <iostream>
#include <map>
#include "Motor.h"
#include "Sensor.h"


class Sensor;

class Robot {

protected:

    Motor motor;

    std::map<const int, Sensor* > sensorMap;
    int iterator = 0;


public:

    ~Robot(){
        sensorMap.clear();
    }

    int addSensor(Sensor* sensor);
    Sensor* getSensor(int id);
    void deleteSensor(int id);
    void eventLoop(int iterations);
};



#endif //ROBOT1_ROBOT_H
