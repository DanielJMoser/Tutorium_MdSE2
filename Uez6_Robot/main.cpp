#include <iostream>
#include "RobotExceptions.h"
#include "Robot.h"
#include "Sensor.h"

int main() {

    try {

        Robot robot;

        robot.addSensor(new Camerasensor);
        robot.addSensor(new Distancesensor);
        robot.addSensor(new Cliffsensor);

        robot.eventLoop(10);

        robot.deleteSensor(1);
        robot.deleteSensor(2);
        robot.deleteSensor(3);

    } catch (std::exception &error) {
        std::cerr << "Exception in Main: " << error.what() << std::endl;
    }
}