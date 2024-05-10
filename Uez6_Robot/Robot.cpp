//
// Created by danielm on 26.05.22.
//

#include "Robot.h"
#include "Motor.h"
#include "RobotExceptions.h"
#include <unistd.h>
#include <iostream>


int Robot::addSensor(Sensor *sensor) {

    int id = iterator++;
    sensorMap.insert({id, sensor});
    return iterator;
}

Sensor *Robot::getSensor(int id) {

    if (sensorMap.find(id) != sensorMap.end()) {
        return sensorMap[id];
    }
    return nullptr;
}

void Robot::deleteSensor(int id) {

    sensorMap.erase(id);
}

void Robot::eventLoop(int iterations) {
    int counter = 1;
    int emergencyCounter = 0;

    bool SensorError = false;
    bool emergencyBreak = false;


    while (iterations >= 0) {

        std::cout << "Durchlaufe Nummer " << counter << ":" << std::endl;

        int dangerLevel = 0;


        if (!emergencyBreak) {
            for (auto &sensor: sensorMap) {
                try {
                    int newDangerLevel = sensor.second->checkSensor();
                    if (newDangerLevel > dangerLevel) {
                        dangerLevel = newDangerLevel;
                        std::cout << "Neues Hoechstes Gefahrenlevel: " << dangerLevel << std::endl;
                    }
                }
                catch (CriticalDangerException &e) {
                    motor.emergencyBrake();
                    emergencyBreak = true;
                    if (emergencyCounter == 0) {
                        emergencyCounter = 5;
                    }
                }
                catch (InternalErrorException &e) {
                    std::cout << "Sensorfehler, setze minimale Geschwindigkeit!" << std::endl;
                    dangerLevel = 9;
                    if (!SensorError) {
                        SensorError = true;
                        emergencyCounter = 5;
                    }
                }
            }
        }

        if (emergencyCounter != 0 && emergencyBreak) {
            std::cout << "Wir sind im emergencyBreak fuer " << 6 - emergencyCounter << " von 5 Iterationen" << std::endl;
            emergencyCounter--;
        } else {
            if (emergencyCounter != 0 && SensorError) {
                std::cout << "Wir fahren im Notfallmodus fuer " << 6 - emergencyCounter << " von 5 Iterationen"
                          << std::endl;
                motor.setSpeed(1);
                emergencyCounter--;
            } else {
                if (dangerLevel == 0) {
                    std::cout << "Keine Gefahr, volle Geschwindigkeit!" << std::endl;
                    motor.setSpeed(10);
                } else {
                    int NewSpeed = 10 - dangerLevel;
                    motor.setSpeed(NewSpeed);
                }
            }
        }

        if (emergencyCounter == 0) {
            emergencyBreak = false;
            SensorError = false;
        }

        std::cout << "-------------------------------------------------------" << std::endl;

        if (iterations > 0) {
            iterations--;
            if (iterations <= 0) {
                break;
            }
        }
        sleep(1);
        counter++;
    }
}
