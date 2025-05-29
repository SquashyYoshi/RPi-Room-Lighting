// cat /dev/ttyACM0
// arduino:avr:uno
int trig = 13;
int echo = 12;
float duration, distance;
void setup() 
{
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    Serial.begin(9600);
}

void loop() 
{
    //sends a 10 microsecond pulse of sound
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    duration = pulseIn(echo, HIGH); //tracks how long echo was HIGH
    distance = (duration*.0343)/2;
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
}
