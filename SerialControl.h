/*
    SerialControl.h - library for implementing full arduino control over a serial
    connection. Meaning to make no need for specific sketch implementations. The
    end goal of this project is to allow full control of the arduino from a ROS 
    node, making it similar to rosserial, but with a features like ros-arduino-bridge.
*/

#ifndef SerialControl_h
#define SerialControl_h

#include "Arduino.h"
#include "Command.h"

class SerialControl
{
public:
    SerialControl();
    ~SerialControl();
    void run();
};

#endif
