#include "Command.h"

Command::Command(char type, char pin, char value){
    _type = type;
    _pin = pin;
    _value = value;

}

Command::~Command(){//Destructor
}

void Command::returnError(){
    _response = (char*)"Error";
}

void Command::returnSuccess(){
    _response = (char*)"Success";
}

char* Command::getResponse(){
    return _response;
}

void Command::run(){
    int pin = int(_pin);
    switch (_type){
        case 'i'://Initialize
            switch(_value){
                case 'i'://INPUT
                    pinMode(pin, INPUT);
                    returnSuccess();
                break;

                case 'o'://OUTPUT
                    pinMode(pin, OUTPUT);
                    returnSuccess();
                break;

                case 'p'://INPUT_PULLUP
                    pinMode(pin, INPUT_PULLUP);
                    returnSuccess();
                break;

                default:
                    returnError();
                break;
            }

        break;

        case 'w'://Digital write
            switch(_value){
                case 'h'://HIGH
                    digitalWrite(pin, HIGH);
                    returnSuccess();
                break;

                case 'l'://LOW
                    digitalWrite(pin, LOW);
                    returnSuccess();
                break;

                default:
                    returnError();
                break;
            }

        break;

        case 'r'://Digital read
            _response = (char*)digitalRead(pin);
        break;

        case 'a'://Analog read
            _response = (char*)analogRead(pin);
        break;

        case 'b'://Analog write
            analogWrite(pin, int(_value));
            returnSuccess();
        break;

        case 'p':
            switch(_value){
                case 'h': //HIGH
                    _response = (char*)pulseIn(pin, HIGH);
                break;

                case 'l': //LOW
                    _response = (char*)pulseIn(pin, HIGH);
                break;

                default:
                    returnError();
                break;
                }
        break;

        default:
            returnError();

        break;
    }

}