#include <cstdlib>

#include "RobotException.h"
#include "Sensor.h"

class CliffSensor : public Sensor {
public:
    int checkSensor() override {
        if (rand() % 100 < 5) throw InternalErrorException();
        if (rand() % 100 < 10) throw CriticalDangerException();
        return rand() % 5; // 0 bis 4
    }
};
