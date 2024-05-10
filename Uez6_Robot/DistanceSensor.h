#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H

#include "Sensor.h"

class DistanceSensor : public Sensor {
public:
    int checkSensor() override;
};

#endif // DISTANCESENSOR_H
