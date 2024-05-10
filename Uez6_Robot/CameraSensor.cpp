#include <cstdlib>

#include "RobotException.h"
#include "Sensor.h"

class CameraSensor : public Sensor {
public:
    int checkSensor() override {
        if (rand() % 100 < 15) throw InternalErrorException();
        if (rand() % 100 < 20) throw CriticalDangerException();
        return rand() % 10; // 0 bis 9
    }
};

