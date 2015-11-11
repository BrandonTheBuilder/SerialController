#include "SerialControl.h"
#include "Command.h"

SerialControl::SerialControl(){
    //destructor
}

SerialControl::~SerialControl(){ //destuctor
}

void SerialControl::run(){
    char buffer[4];

    int input = Serial.readBytes(buffer, 4);
    if (input == 4){
        Command command = Command(buffer[1], buffer[2], buffer[3]);
        command.run();
        Serial.print(buffer[0]);
        Serial.print(command.getResponse());
        Serial.print('\x04');
    }
}


