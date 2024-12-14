#include <Adafruit_NeoPixel.h>
#include <KosmoBits_Pins.h>
#include <KosmoBits_Pixel.h>

const int sensorPin = KOSMOBITS_SENSOR_PIN;
KosmoBits_Pixel pixel;

int restingValue = 0;

int determineRestingValue() {
  const int N = 20; // measurement numbers
  float average = 0;
  for (int i = 0; i < 20; ++i) {
    average = average + analogRead(sensorPin);
    delay(10);
  }
  average = average / N;
  return average;
}

void setup() {
  pinMode(sensorPin, INPUT);
  restingValue = determineRestingValue();
}

void loop() {
  int value = analogRead(sensorPin);
  int difference;
  if (value > restingValue) {
    difference = value - restingValue;
  } else {
    difference = restingValue - value;
  }

   pixel.setColor(2 * difference, 100 - 2 * difference, 0, difference); // RGB value and
// brightness.
   delay(10);
}
