#include <KosmoBits_Pins.h>
const int buzzerPin = KOSMOBITS_BUZZER_PIN;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  tone(buzzerPin, 440);
  delay(500);
  noTone(buzzerPin);
  delay(500);
}
