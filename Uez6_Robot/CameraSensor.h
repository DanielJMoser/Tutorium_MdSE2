#ifndef CAMERASENSOR_H
#define CAMERASENSOR_H

#include "Sensor.h"

class CameraSensor : public Sensor {
public:
    int checkSensor() override;
};

#endif // CAMERASENSOR_H
