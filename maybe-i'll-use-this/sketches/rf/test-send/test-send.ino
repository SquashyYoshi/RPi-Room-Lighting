#include <RCSwitch.h>

RCSwitch rf = RCSwitch();
char chr;
bool newData = false;
void setup() 
{
    Serial.begin(9600);
    rf.enableTransmit(13);
    rf.setRepeatTransmit(10);
    rf.setProtocol(2);
    rf.enableReceive(0); //pin 2
    Serial.println("Setup complete...");
}

void loop()
{
    
    rf.send(2, 24);
    delay(500); 
}
