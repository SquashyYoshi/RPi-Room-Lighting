#include <KosmoBits_Pins.h>

const int buzzerPin = KOSMOBITS_BUZZER_PIN;
const int FREQ_MIN = 440;
const int FREQ_MAX = 660;
const int DELAY = 4;

int freq = FREQ_MIN; // Frequency of the sound
// that is output.


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  tone(buzzerPin, freq); // (1)
  delay(DELAY);
  ++freq; // Short for: freq = freq + 1;
  if (freq > FREQ_MAX) {
    freq = FREQ_MIN;
  }
}
