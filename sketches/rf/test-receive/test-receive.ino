#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
int signalsSoFar = 0;
void setup() {
    Serial.begin(9600);
    mySwitch.enableReceive(1);  
    Serial.println("ready for signals...");
}

void loop() {
    if (mySwitch.available()) {
        signalsSoFar++;
        Serial.println(signalsSoFar);
        Serial.print("Received ");
        Serial.print( mySwitch.getReceivedValue() );
        Serial.print(" / ");
        Serial.print( mySwitch.getReceivedBitlength() );
        Serial.print("bit ");
        Serial.print("Protocol: ");
        Serial.println( mySwitch.getReceivedProtocol() );

        mySwitch.resetAvailable();
    }
}