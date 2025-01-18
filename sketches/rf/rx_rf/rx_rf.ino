//Prints a stream of digital data over a pin, averaged out over "waits" samples
const int RX_PIN = 13;
unsigned int count = 0; //total number of loop cycles
int curSigs = 0; //total of all signal values taken in the last run of waits
int waits = 2000; //how often sample is taken, more means less noise
unsigned int startMillis = 0;

void setup() 
{
    Serial.begin(9600);
    pinMode(RX_PIN, INPUT);
}

void loop() 
{
    curSigs += digitalRead(RX_PIN);
    if(count % waits == 0) {
        int thisValue = round((double)curSigs / (float)waits);

        //Serial.print(">RX:");
        //Serial.print(thisValue);
        //Serial.print("\r\n");

        Serial.print("(");
        Serial.print(millis() / 1000.0);
        Serial.print(", ");
        Serial.print(thisValue);
        Serial.print("), ");

        curSigs = 0;
        delay(1);
    }
    count++;
}


