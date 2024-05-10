//
// Created by danielm on 26.05.22.
//

#ifndef ROBOT1_ROBOTEXCEPTIONS_H
#define ROBOT1_ROBOTEXCEPTIONS_H

#include <stdexcept>


class RobotExceptions : public std::runtime_error {

public:
    using std::runtime_error::runtime_error;

};

class CriticalDangerException : public RobotExceptions {

public:
    using RobotExceptions::RobotExceptions;
};

class InternalErrorException : public RobotExceptions {

public:
    using RobotExceptions::RobotExceptions;
};

#endif //ROBOT1_ROBOTEXCEPTIONS_H
