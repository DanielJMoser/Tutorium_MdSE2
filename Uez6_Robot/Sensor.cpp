//
// Created by danielm on 26.05.22.
//

#include "Sensor.h"

int Camerasensor::checkSensor() {


    //Checking for Critical Danger
    isCriticalDanger = rand() % 100 + 1;

    if (isCriticalDanger <= 20) {
        throw CriticalDangerException("Camerasensor::checkSensor: Critical danger detected! Breaking...");
    }

    //Checking for Internal Error
    isInternalError = rand() % 100 + 1;

    if (isInternalError <= 15) {
        throw InternalErrorException("Camerasensor::checkSensor: Internal error detected! Breaking...");
    }

        //If neither Critical Danger nor an Internal Error occurred:
        //return a randomly generated Danger Level!
    else {

        dangerLevel = rand() % 7;
        return dangerLevel;
    }
}


int Distancesensor::checkSensor() {
    //Checking for Critical Danger
    isCriticalDanger = rand() % 100 + 1;

    if (isCriticalDanger <= 10) {
        throw CriticalDangerException("Disctancesensor::checkSensor: Critical danger detected! Breaking...");
    }

    //Checking for Internal Error
    isInternalError = rand() % 100 + 1;

    if (isInternalError <= 5) {
        throw InternalErrorException("Disctancesensor::checkSensor: Internal error detected! Breaking...");
    }

        //If neither Critical Danger nor an Internal Error occurred:
        //return a randomly generated Danger Level!
    else {

        dangerLevel = rand() % 5;
        return dangerLevel;
    }
}


int Cliffsensor::checkSensor() {

    //Checking for Critical Danger
    isCriticalDanger = rand() % 100 + 1;

    if (isCriticalDanger <= 20) {
        throw CriticalDangerException("Cliffsensor::checkSensor: Critical danger detected! Breaking...");
    }

    //Checking for Internal Error
    isInternalError = rand() % 100 + 1;

    if (isInternalError <= 5) {
        throw InternalErrorException("Cliffsensor::checkSensor: Internal error detected! Breaking...");
    }

        //If neither Critical Danger nor an Internal Error occurred:
        //return a randomly generated Danger Level!
    else {
        dangerLevel = rand() % 10;
        return dangerLevel;
    }
}

