
#include "TinyRF_TX.h"

void setup() 
{
    Serial.begin(9600);
    setupTransmitter();
}

void loop() 
{
    const char* msg = "Hello from far away!";
    sendMulti((byte*)msg, strlen(msg), 5);
    delayMicroseconds(TX_DELAY_MICROS);

    int numMsg = 12345;
    sendMulti((byte*)numMsg, strlen(msg), 5);
    delayMicroseconds(TX_DELAY_MICROS);
    Serial.println("Sent message");
}
