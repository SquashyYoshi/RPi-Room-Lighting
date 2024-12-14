int ledPin = 13;
int switchPin = 9;
int switchValue = HIGH;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchValue = digitalRead(switchPin);
  digitalWrite(ledPin, switchValue);

delay(50);
}
