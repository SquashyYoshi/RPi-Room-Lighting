#include <Adafruit_NeoPixel.h>
#include <KosmoBits_Pins.h>
#include <KosmoBits_Pixel.h>

const int sensorPin = KOSMOBITS_SENSOR_PIN;
const int button1Pin = KOSMOBITS_BUTTON_1_PIN;
const int button2Pin = KOSMOBITS_BUTTON_2_PIN;

int button1 = HIGH;
int button2 = HIGH;
int sensorValue = 0;

enum Mode {IDLE, COUNTDOWN, WAIT_UNTIL_DARK, CLOSED, OPEN};

Mode mode = IDLE;

const int DARK_VALUE = 100;
unsigned long counter = 0;
KosmoBits_Pixel pixel;

void reset() {
  pixel.setColor(0, 0, 0, 0); // Pixel off 
mode = IDLE;
  counter = 0;
  Serial.println("Reset!");
}

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  Serial.begin(115200);
  reset();
}

void loop() {
  switch(mode) {
  case IDLE:
    loopIdle();
    break;
  case COUNTDOWN:
    loopCountdown();
    break;
  case WAIT_UNTIL_DARK:
    loopUntilDark();
    break;
  case CLOSED:
    loopClosed();
    break;
  case OPEN:
    loopOpen();
    break;
  }
}

void loopIdle() {
  Serial.println("Idle");
  bool pressed = false;
  while(digitalRead(button1Pin) == LOW) {
    // Button 1 was pressed.
    // Wait for it to be released again.
    pixel.setColor(0, 255, 0, 25);
    pressed = true;
    delay(50);
  }
  if (pressed) {
    mode = COUNTDOWN;
  }
}

void loopCountdown() {
  const int COUNTDOWN_NUMBER = 5;
  Serial.println("Countdown");
  pixel.setColor(0, 0, 0, 0); // Pixel OFF
  delay(500);
  // The actual countdown: Like Blink.
  for (int i = 0; i < COUNTDOWN_NUMBER; ++i) {
    pixel.setColor(0, 255, 0, 25); // Green
    delay(500);
    pixel.setColor(0, 0, 0, 0); // Pixel off
    delay(500);
  }
  pixel.setColor(255, 0, 0, 25); // Red
  delay(1000);
  pixel.setColor(0, 0, 0, 0); // Pixel off
  mode = WAIT_UNTIL_DARK;
}

void loopUntilDark() {
  Serial.println("Wait until dark");
  while (analogRead(sensorPin) > DARK_VALUE) {
    delay(10);
  }
  mode = CLOSED;
  delay(1000);
}

void loopClosed() {
  Serial.println("In the dark");
  sensorValue = analogRead(sensorPin);
  if (sensorValue < DARK_VALUE) {  // It is 
// still dark.
    delay(1000); // Wait 1 second, loop() invokes
// this function again.
  } else {
    // It is bright! Check again 
// after 0.5 seconds.
    delay(500);
    if (analogRead(sensorPin) >= DARK_VALUE) {
      // It is bright: drawer opened!
      mode = OPEN;
    }
  }
}

void loopOpen() {
  Serial.println("opened");
  delay(50);
  button2 = digitalRead(button2Pin);
  sensorValue = analogRead(sensorPin);

  if (button2 == LOW) {
    output();
  } else if (sensorValue < DARK_VALUE) {
    // Drawer closed again.
    ++counter;
    mode = CLOSED;
  }
}

void output() {  
  Serial.print("The drawer was opened ");
  Serial.print(counter);
  Serial.print(" times!\n");
  if (counter > 0) {
    pixel.setColor(255, 0, 0, 25);
  } else {
    pixel.setColor(0, 255, 0, 25);
  }
  delay(2000);
  reset();
}


