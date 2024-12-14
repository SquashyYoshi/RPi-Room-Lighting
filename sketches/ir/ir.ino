
#include <Arduino.h>
#include <IRremote.h>
#define DECODE_NEC


const int INFARED_PIN = 2;
void setup() 
{
    Serial.begin(9600);
    IrReceiver.begin(INFARED_PIN, DISABLE_LED_FEEDBACK);
    Serial.println("Listening...");
}

void loop() 
{
    if(IrReceiver.decode())
    {
        Serial.println(IrReceiver.decodedIRData.command); //should add 100 to output before relaying to pi
        IrReceiver.resume();
        delay(100);
    }
}
