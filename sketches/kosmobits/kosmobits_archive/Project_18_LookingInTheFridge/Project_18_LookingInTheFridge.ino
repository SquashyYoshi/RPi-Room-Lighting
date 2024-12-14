#include <Adafruit_NeoPixel.h>
#include <KosmoBits_Pixel.h>
#include <KosmoBits_Pins.h>

const int sensorPin = KOSMOBITS_SENSOR_PIN;
KosmoBits_Pixel pixel;

void setup() {
  pinMode(sensorPin, INPUT);
  pixel.setColor(255, 255, 255, 0);
}

void loop() {
  int brightness = analogRead(sensorPin);
  if (brightness > 255) {
    brightness = 255;
  }
  pixel.setColor(255, 255, 255, brightness);
  delay(10);
}
