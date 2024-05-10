#ifndef CLIFFSENSOR_H
#define CLIFFSENSOR_H

#include "Sensor.h"

class CliffSensor : public Sensor {
public:
    int checkSensor() override;
};

#endif // CLIFFSENSOR_H
