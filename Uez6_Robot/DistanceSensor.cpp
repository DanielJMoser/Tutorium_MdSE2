

#include <cstdlib>

#include "RobotException.h"
#include "Sensor.h"


class DistanceSensor : public Sensor {
public:
    int checkSensor() override {
        if (rand() % 100 < 5) throw InternalErrorException();
        if (rand() % 100 < 15) throw CriticalDangerException();
        return rand() % 7; // 0 bis 6
    }
};
