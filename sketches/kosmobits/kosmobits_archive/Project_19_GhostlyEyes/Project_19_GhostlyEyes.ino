#include <KosmoBits_Pins.h>

const int buzzerPin = KOSMOBITS_BUZZER_PIN;
const int redPin = 11;
const int greenPin = 6;

void setup() {
  randomSeed(analogRead(3));
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}


void loop() {
  // Blinking
  analogWrite(redPin, random(0, 256));
  analogWrite(greenPin, random(0, 256));
  delay(200);

  // Hissing
  if (random(0, 1000) > 900) {
    for (int i = 0; i < 3000; ++i) {
      analogWrite(buzzerPin, random(0, 256));
    }
  }
}
