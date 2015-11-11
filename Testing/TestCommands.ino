/*
    Testing the command class for serial control
*/
#include <Command.h>
Command init = Command('i', '\r', 'o');
Command ledOn = Command('w', '\r', 'h');
Command ledOff = Command('w', '\r', 'l');

void setup()
{
    init.run();
}

void loop()
{
    ledOn.run();
    delay(1000);
    ledOff.run();
}