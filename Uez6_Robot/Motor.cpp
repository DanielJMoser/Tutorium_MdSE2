//
// Created by danielm on 26.05.22.
//


#include "Motor.h"
#include "RobotExceptions.h"
#include <iostream>

void Motor::setSpeed(int speed) {

    if (speed >= 0 && speed <= 10) {
        this -> currentSpeed = speed;
    }
    else {
        throw InternalErrorException("Level of speed must be a number between 0 and 10!");
    }
}


void Motor::emergencyBrake() {

    setSpeed(0);
    std::cout << "Notbremsung wurde erforderlich!!" << std::endl;
}


int Motor::getSpeed() {

    return this -> currentSpeed;
}
