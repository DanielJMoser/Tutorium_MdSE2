CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

all: main

main: main.o Robot.o Motor.o Sensor.o
	$(CXX) $(CXXFLAGS) -o main main.o Robot.o Motor.o Sensor.o

main.o: main.cpp Robot.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Robot.o: Robot.h Robot.cpp Motor.h Sensor.h
	$(CXX) $(CXXFLAGS) -c Robot.cpp

Motor.o: Motor.h Motor.cpp
	$(CXX) $(CXXCFLAGS) -c Motor.cpp

Sensor.o: Sensor.h Sensor.cpp RobotExceptions.h
	$(CXX) $(CXXFLAGS) -c Sensor.cpp

clean:
	rm -f *.o main
