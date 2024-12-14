const int RX_PIN = 13;
const int TX_PIN = 11;
const int SIGS_LEN = 1000;
bool recordedSigs[SIGS_LEN];

unsigned int count = 0; //total number of loop cycles
int curSigs = 0; //total of all signal values taken in the last run of waits
int waits = 100; //how often sample is taken, more means less noise
int idx = 0;


void setup() 
{
    Serial.begin(9600);
    pinMode(RX_PIN, INPUT);
    //this goes in setup but compiler was being weird with comments
    pinMode(TX_PIN, OUTPUT);
    digitalWrite(TX_PIN, LOW);
    
}

void loop() //TODO: add playing of recordedSigs on an offset to getting recorded (5 seconds?)
{
    if(idx <= SIGS_LEN) {
        curSigs += digitalRead(RX_PIN);
        if(count % waits == 0) {
            int thisValue = round((double)curSigs / (float)waits);
            Serial.print(">RX:");
            Serial.print(thisValue);
            Serial.print("\r\n");
            
            recordedSigs[idx] = thisValue == 1;
            idx++;
            curSigs = 0;
        }
    }else{
        Serial.print("Stopped recording after ");
        Serial.print(millis() / (float)SIGS_LEN);
        Serial.println(" seconds");
        idx = 0;
        Serial.println("waiting 10 seconds before broadcasting signal...");
        delay(10000);

        Serial.println("Broadcasting signal 3 times...");
        //playSig(recordedSigs, SIGS_LEN)
        Serial.println("Broadcast complete.");
    }
    count++;
}
void playSig(bool* arr, int len)
{
    for(short i = 0; i < 3; i++) {
        for(short j = 0; j < len; j++) {
            for(short f = 0; f < waits; f++) { //do this to simulate timings without directly keeping track
                digitalWrite(TX_PIN, arr[j]);
            }
        }
        Serial.println("Signal broadcast");
        delay(1000);
    }
}

