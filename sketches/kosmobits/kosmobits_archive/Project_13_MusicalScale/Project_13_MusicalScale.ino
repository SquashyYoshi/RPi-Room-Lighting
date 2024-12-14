#include <KosmoBits_Pins.h>

const int buzzerPin = KOSMOBITS_BUZZER_PIN;
const int freqRoot = 220; // This is the
// note A (one octave deeper than the standard
// pitch A from project 10).

float scale[] = {1.f, 9.f/8, 5.f/4, 4.f/3, 3.f/2, 5.f/3, 15.f/8, 2.f};

void setup() {
  for (int i = 0; i < 8; ++i) {
    tone(buzzerPin, scale[i] * freqRoot);
    delay(500);
  }
  noTone(buzzerPin);
}

void loop() {
  // put your main code here, to run repeatedly:

}
