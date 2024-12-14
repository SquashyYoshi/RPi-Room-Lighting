
#include <KosmoBits_Pins.h>

const int sensorPin = KOSMOBITS_SENSOR_PIN;
const int buzzerPin = KOSMOBITS_BUZZER_PIN;
const int buttonPin = KOSMOBITS_BUTTON_2_PIN;

const float scale[] = {1.f, 9.f/8, 5.f/4, 4.f/3, 3.f/2, 5.f/3, 15.f/8, 2.f};
const int freqRoot = 220; // This is the
// note A.

const int measurementMin = 300;
const int measurementMax = 400;
const int scaling = (measurementMax - measurementMin) / 9;

const int N = 10; // Number of values that 
// are averaged.
int values[N] = {}; // Here is where the last 
// 10 values are stored.
int index = 0;

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // Reads a new value from the sensor and
  // saves it in values[].
  values[index] = analogRead(sensorPin);
  // Raise the index by 1, so the next
  // value can be saved at the next location
  // in the values[] field.
  
  ++index;
  // If index == N, the field is 
  // fully described.
  // index is then set to 0, so that 
  // the oldest value
  // is overwritten in the next pass.
  if (index == N) {
      index = 0;
  }
  // Now the average of the last N
  // measurement readings is calculated.
  int average = 0; // Start with the value 0
  // Total the measurement values.
  for (int i = 0; i < N; ++i) {
    average = average + values[i];
  }
  // Divide the total by the number of values.
  average = average / N;
  int noteIndex = (average - measurementMin) /
  scaling;
  // noteIndex must not be less than 0 or 
  // greater than 7:
  if (noteIndex < 0) {
    noteIndex = 0;
  } else if (noteIndex > 7) {
    noteIndex = 7;
  }
  // Output note
  if (digitalRead(buttonPin) == LOW) {
    tone(buzzerPin, scale[noteIndex] * freqRoot);
    delay(10);
  } else {
    noTone(buzzerPin);
    delay(1);
  }
}
