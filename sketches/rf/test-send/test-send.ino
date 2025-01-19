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
    // int curSig = -1;
    // if(rf.available()) {
    //     curSig = rf.getReceivedValue();
    //     Serial.print("received signal ");
    //     Serial.println(curSig);
    //     rf.resetAvailable();
    // }
    // if (Serial.available() > 0) {
    //     chr = Serial.read();
    //     int sig = chr - '0';
    //     rf.send(sig, 24);
    //     Serial.print("sent ");
    //     Serial.println(sig);
    // }
    rf.send(2, 24);
    delay(500); 
}
