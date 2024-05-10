//
// Created by danielm on 26.05.22.
//

#ifndef ROBOT1_MOTOR_H
#define ROBOT1_MOTOR_H



class Motor {

protected:

    int currentSpeed;

public:

    ~Motor()= default;

    int getSpeed();

    void emergencyBrake();

    void setSpeed(int speed);
};


#endif //ROBOT1_MOTOR_H
