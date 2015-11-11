/*
    Command is a class that is used to save read, write or init commands to be 
    carried out by SerialControl.h
    three command types init: 'i', read: 'r', write: 'w'
*/

#ifndef Command_h
#define Command_h

#include "Arduino.h"

class Command
{
public:
    Command(char type, char pin, char value);
    ~Command();
    void run();
    char* getResponse();

private:
    char _type;
    char _pin;
    char _value;
    char* _response;
    void returnError();
    void returnSuccess();

    
};

#endif