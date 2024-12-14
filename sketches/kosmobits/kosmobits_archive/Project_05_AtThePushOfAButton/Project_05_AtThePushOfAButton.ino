#include <Adafruit_NeoPixel.h>
#include <KosmoBits_Pixel.h>
#include <KosmoBits_Pins.h>

const int button1 = KOSMOBITS_BUTTON_1_PIN;
const int button2 = KOSMOBITS_BUTTON_2_PIN;

int red = 0;
int green = 0;
int blue = 0;
const int brightness = 50;

KosmoBits_Pixel pixel;

void setup() {
  // put your setup code here, to run once:

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(button1) == LOW){
    red = 255;
  } else {
    red = 0;
  }

  if (digitalRead(button2) == LOW){
    blue = 255;
  } else {
    blue = 0;
  }

  pixel.setColor(red, green, blue, brightness);
  
  delay(50);
}
