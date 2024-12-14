/**
 * BlinkOnBoard – 
 * A simple program that causes the built-in LED on the
 * KosmoBits controller to blink on and off.
 * 
 */
 
int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(ledPin, HIGH);
 delay(500);
 digitalWrite(ledPin, LOW);
 delay(500);
}
