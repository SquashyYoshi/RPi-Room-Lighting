#include <Adafruit_NeoPixel.h>
#include <KosmoBits_Pixel.h>

KosmoBits_Pixel pixel;

int red = 0;
int green = 0;
int blue = 0;
int brightness = 0;

void setup() {
  // there is nothing to do here

}

void loop() {
  // 50 is a good brightness value.
  // The highest brightness level is 255.
  // It can be a bit blinding though!
  brightness = 50;

  //red
  red = 255;
  green = 0;
  blue = 0;
  pixel.setColor(red, green,blue, brightness);
  delay(500);

  //green
  red = 0;
  green = 255;
  blue = 0;
  pixel.setColor(red, green,blue, brightness);
  delay(500);

  //blue
  red = 0;
  green = 0;
  blue = 255;
  pixel.setColor(red, green,blue, brightness);
  delay(500);

  //purple
  red = 255;
  green = 0;
  blue = 255;
  pixel.setColor(red, green,blue, brightness);
  delay(500);
 
  //turquoise
  red = 0;
  green = 255;
  blue = 255;
  pixel.setColor(red, green,blue, brightness);
  delay(500);

  //yellow
  red = 255;
  green = 255;
  blue = 0;
  pixel.setColor(red, green,blue, brightness);
  delay(500);

  //white
  red = 255;
  green = 255;
  blue = 255;
  pixel.setColor(red, green,blue, brightness);
  delay(500);
}
