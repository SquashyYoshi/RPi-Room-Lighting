#include <RCSwitch.h>

RCSwitch rx = RCSwitch();
RCSwitch tx = RCSwitch();
int signalsSoFar = 0;
void setup() {
    Serial.begin(9600);
    rx.enableReceive(0); //interupt 0, pin 2
    tx.enableTransmit(13);
    tx.setRepeatTransmit(10);
    tx.setProtocol(2);
    Serial.println("ready for signals...");
}

void loop() {
    if (rx.available()) {
        signalsSoFar++;
        Serial.println(signalsSoFar);
        Serial.print("Received ");
        Serial.print( rx.getReceivedValue() );
        Serial.print(" / ");
        Serial.print( rx.getReceivedBitlength() );
        Serial.print("bit ");
        Serial.print("Protocol: ");
        Serial.println( rx.getReceivedProtocol() );
        
        delay(800);
        int checkSum = rx.getReceivedValue()/2 + 8;
        tx.send(checkSum, 24); //return signal so pi knows correct signal was received
        Serial.print("Sent ");
        Serial.println(checkSum);
        rx.resetAvailable();
    }
}