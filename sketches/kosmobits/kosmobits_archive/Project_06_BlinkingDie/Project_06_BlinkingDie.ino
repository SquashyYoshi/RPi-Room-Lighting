#include <KosmoBits_Pins.h>
#include <Adafruit_NeoPixel.h>
#include <KosmoBits_Pixel.h>

KosmoBits_Pixel pixel;

const int buttonPin = KOSMOBITS_BUTTON_1_PIN;
const int blinkDuration = 500; // Milliseconds
const int blinkPause = 250; // Milliseconds
const int brightness = 50;


void setup() {
  // put your setup code here, to run once:
  
   pinMode(buttonPin, INPUT);
   randomSeed(analogRead(12)); // Starting value
  // for random generator
  pixel.setColor(0, 0, 255, brightness); // Blue
  // signals operational readiness

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(buttonPin)==LOW){
    roll();
  }
}

void roll() {
  // (1)
  // Light off at first, to show that it is
  // ready to respond to the push of the button.
  pixel.setColor(0, 0, 0, 0); // Light off
  delay(500);

  // (2) Generate random number
  int number = random(1, 7);

  // (3) Blink number times
  for (int i = 0; i < number; ++i) {
    pixel.setColor(0, 255, 0, brightness); 
  // Green
    delay(blinkDuration);
    pixel.setColor(0, 0, 0, 0); // Light off
    delay(blinkPause);
  }

  // (4) Signal conclusion of rolling.
    delay(blinkDuration); // Pause at end 
// somewhat longer
    pixel.setColor(0, 0, 255, brightness); // Blue 
// signals state of readiness
}


