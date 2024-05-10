//
// Created by danielm on 26.05.22.
//

#ifndef ROBOT1_SENSOR_H
#define ROBOT1_SENSOR_H


#include <ctime>
#include <iostream>
#include "RobotExceptions.h"

class Sensor {

public:

    Sensor() = default;

    virtual ~Sensor() = default;

    virtual int checkSensor() = 0;

    int dangerLevel{};
    int isCriticalDanger{};
    int isInternalError{};

};


class Camerasensor : public Sensor {

public:

    int checkSensor() override;

    ~Camerasensor() override = default;
};


class Cliffsensor : public Sensor {

public:

    int checkSensor() override;

    ~Cliffsensor() override = default;

};

class Distancesensor : public Sensor {

public:

    int checkSensor() override;

    ~Distancesensor()  override = default;
};


#endif //ROBOT1_SENSOR_H
