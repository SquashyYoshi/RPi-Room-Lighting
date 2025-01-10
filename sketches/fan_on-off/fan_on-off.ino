//this tries to send an rf signal that should be interpreted as the on/off command
//doesn't work right now, haven't figured out why ;(

const int TX_PIN = 12;
//up for x ms, down for x ms...
short lightCode[] = {40, 20, 40, 20, 40, 20, 40, 200, 280};
short delaysLen = 9;

void setup() 
{
    Serial.begin(9600);
    pinMode(TX_PIN, OUTPUT);
}

void loop() 
{
    
    bool curState = true;
    for(int i = 0; i < delaysLen; i++) {
        digitalWrite(TX_PIN, curState);
        Serial.print(">tx:");
        Serial.print(curState);
        Serial.print("\r\n");

        Serial.print(">time:");
        Serial.print(millis() / 1000.0);
        Serial.print("\r\n");
        Serial.println();

        curState = !curState;
        delay(lightCode[i]);

        
    }
    digitalWrite(TX_PIN, false);
    Serial.print(">tx:");
    Serial.print(false);
    Serial.print("\r\n");

    Serial.print(">time:");
    Serial.print(millis() / 1000.0);
    Serial.print("\r\n");

    Serial.print("\n\n_____WAITING_______\n\n");
    delay(5000);
    

}

