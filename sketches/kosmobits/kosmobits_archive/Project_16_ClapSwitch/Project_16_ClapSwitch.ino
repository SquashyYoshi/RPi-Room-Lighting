#include <KosmoBits_Pins.h>
#include <Adafruit_NeoPixel.h>
#include <KosmoBits_Pixel.h>

const int sensorPin = KOSMOBITS_SENSOR_PIN;
const int threshold = 500;

KosmoBits_Pixel pixel;

bool on = false;

void setup() {
  pinMode(sensorPin, INPUT);
  pixel.setColor(0, 0, 0, 0);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  if (sensorValue > threshold) {
    toggle();
    delay(200);
  }
}

void toggle() {
  if (on) {
    pixel.setColor(0, 0, 0, 0);
    on = false;
  } else {
    pixel.setColor(255, 0, 0, 30);
    on = true;
  }
}
