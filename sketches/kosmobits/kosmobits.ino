
/***********************************
** KosmoBits_App.ino v.78_04 *******
** Kosmoduino Code for ************
** Cosmos Gamepad Controller *******
************************************
** the controller is exclusive *****
** included in the *******************
** KosmoBits experiment box ***
** by Kosmos (2016) ***************
************************************
** Code developed 2015 by ********
** Bobby Gee (NoaLabs) and *********
** Steffen Rothweiler (cosmos) *****
************************************/

/***********************************
**** KosmoBits_App.ino v.78_04 *****
**** Kosmoduino Code for use in ****
**** Cosmos gamepad controller *****
************* part of ***************
**** GameCoder experimental kit ****
**** by Thames and Kosmos **********
************************************
**** written 2015 by ***************
**** Bobby Gee (NoaLabs) and *******
**** Steffen Rothweiler (cosmos) ***
************************************/

/***********************************
**** Adafruit NeoPixel library *****
**** by Phil Burgess ***************
************************************/

/***********************************
*** Encoder.lib ********************
*** by Paul Stoffregen *************
************************************/

/***********************************
 ********* PROGRAM START ***********
 ***********************************
 **** Declaration of variables ****
 ***********************************/

/***********************************
 ********* CODE STARTS HERE ********
 ***********************************
 ** declaration of the variables ***
 ***********************************/


int L0 = 0;                              // Variable for instantaneous brightness at the light sensor
                                         // variable for actual sensory reading of light sensor

int T0 = 0;                              // Variable for instantaneous brightness at the temperature sensor
                                         // variable for actual sensory reading of temperature sensor

int f = 15;                              // variable specifies range for [map] command
                                         // variable is necessary for [map] -command
boolean bol = false;                     // Variable for light sensor basic value measurement
                                         // variable for light sensor base measurement
boolean bot = false;                     // Variable for temperature basic value measurement
                                         // variable for temperature sensor base measurement

int sig = 0;                             // Variables for sensor value
int Signal = 0;                          // variable for sensor value

int id = 0;                               // Variable for sensor number
                                          // variable for sensor number

#define button1 8                         // Assignment of variable "button1" to pin 8
#define button2 7                         // connects variable "button2" to pin 7

int a = 1;
int r = 0;                                // variable for color value [r] ed, [g] reen and [b] lue
int g = 0;                                
int b = 0;

int b1 = HIGH;                            // variable for the left and right button; "HIGH" is not pressed
int b2 = HIGH;                            // variable carries condition of left and right button; "HIGH" is released
char * Button1 [] = {"pressed", "off"};   // array for state of button 1 and 2
int x = 1; // pointer for array
char * Button2 [] = {"pressed", "off"};   // array for condition of button 1 and 2
int y = 1; // pointer for array

char * character [] = {"nothing", "movement", "light", "volume", "temperature"};
                                          // Array for the name of the inserted sensor bot
                                          // array for the name of the used sensor-bot

int k = 0; // pointer for array
                                          // pointer for array


boolean test = false;                     // test variable
                                          // variable for testing

#include <Encoder.h>                      // Include the library for wheel control via encoder
                                          // including the library for the encoder wheel
                      
#define PIN 5                             // maps the values ​​at pin 5 to the encoder
                                          // connects values ​​read on pin 5 to the encoder

#include <Adafruit_NeoPixel.h>            // Include the library for the Neopixel LED
                                          // including the library for the Neopixel LED

Adafruit_NeoPixel strip = Adafruit_NeoPixel (1, PIN, NEO_GRB + NEO_KHZ800);   // necessary for Neopixel
                                                                              // necessary for neopixel

const int sampleWindow = 50;              // Number of sound sensor readings
                                          // number of readings on the sound sensor
unsigned int sample;                      // variable for storage of min. or max. values ​​of the sound sensor
                                          // this variable contains min or max values ​​of the sound-sensor reading

volatile unsigned int Position = 0;       // 3 variables for encoder position
volatile unsigned int PositionLast = 0;   // 3 variables for encoder position
volatile unsigned int encoder0Pos = 0;

Encoder encoder (3, 2);                   // assigns the values ​​at pin 3 and 2 to the encoder; see Encoder.lib
                                          // connects values ​​read on pin 3 and 2 to the encoder, refer to encoder.lib

/**********************
***** setup code ******
**********************/

void setup () {

  encoder.write (0);                      // sets the encoder to home position 0 (no motion)
                                          // reset encoder position to 0 (no movement)
  //115200
  Serial.begin (115200);                  // Start the serial connection and simultaneously the Bluetooth transmission
                                          // establishing serial connection and start of sending bluetooth data
  strip.begin ();                         // turn on the Neopixel LED
                                          // turning on the neopixel LED
  strip.show ();                          // all colors are switched off at the beginning
                                          // Initialize all pixels to 'off'
}

/************************************
*** Main program: loop start ***
*************************************

/ ************************************
 ********* Main code: loop **********
 ************************************/

void loop () {

/***********************************
* check at the beginning of each loop **
* the Kosmoduino following: ********
* sig = the value of the sensor *******
* id = which sensor is active ****
* whether one of the buttons is pressed
************************************/

/***********************************
* at the beginning of each loop ****
* cycle the KosmoBits code checks **
* sig = the value of the seonsor ***
* id = which sensor is plugged in **
* if button 1 and / or 2 is pressed *
************************************/


sig = analogRead (1);
id = analogRead (2);
b1 = digitalRead (button1);
b2 = digitalRead (button2);


if (id <490 or id> 515)             // check for light sensor
                                    // checking for light sensor
    {bol = false;};                 // reset variable
                                    // resetting variable
                                    
if (id <991 or id> 1014)            // check for temperature sensor
                                    // checking for temperature sensor
    {bot = false;};                 // reset variable
                                    // resetting variable
          
  if (b1 == LOW) {                  // check if button 1 or 2 is pressed
    x = 0;} else {x = 1;};
  
  if (b2 == LOW) {                  // checking status of button 1 and 2
    y = 0;} else {y = 1;};

/**********************************
** reading the encoder position ***
***********************************/

/**********************************
***** read encoder position *******
***********************************/

Position = (encoder.read() / 2);

/***********************************
**** Accelerometer *********
************************************
* the if-loop is condition ****
* for the sensor query and the ***
* resulting reaction ****
************************************/

/***********************************
**** acceleration sensor ***********
************************************
* the if-clause is the basic *******
* condition to run the routine *****
* for sensor reading ***************
************************************/

if (id> 720 && id <790) {                   // the resistance at the sensor connector is greater than 720 and less than 790
  k = 1;                                    // then the acceleration sensor is detected and the variable [k] is set to "1"
                                            // if readings on the sensor slot get a value above 720 and below 790 then the acceleration-
                                            // sensor is recognized and the variable [k] is set to the value of "1"
  
  r = 10;                                   // The LED changes in response to the detected acceleration sensor
  g = 10;                                   // as a consequence of the ROCognition of the acceleration sensor the LED changes its value
  b = 3;
  Signal = map (sig, 325, 725, 0, 100);
  
  if (sig> 625) {r = 200;};                 // if the measured acceleration reaches a limit (sig> 625) then the red component increases strongly
                                            // if sensor readings detect at accleration above a fixed level (sig> 625) the LED turns intensive red
}

else

/***********************************
******* light sensor ***************
************************************
* the if-loop is condition ****
* for the sensor query and the ***
* resulting reaction ****
************************************/

/***********************************
******* light sensor ****************
************************************
* the if-clause is the basic *******
* condition to run the routine *****
* for sensor reading ***************
************************************/
                                            
if (id> 490 && id <515) {                   // the resistance at the sensor connector is greater than 490 and less than 515
  k = 2;                                    // then the light sensor is detected and the variable [k] is set to "2"
                                            // if readings on the sensor slot get a value above 490 and below 515 then the light sensor
                                            // is recognized and the variable [k] is set to the value of "2"


if (bol == false) {L0 = sig;};              // L0 is the value of the light sensor at the time of insertion
                                            // L0 is the sensor value at the moment the sensor is plugged in
bol = true;                                 // Switch for light output variable L0
                                            // switch for L0
int llow = L0;                              // Variables for lower and upper limit of the light sensor
int lhigh = L0 + 200;                       // variable for upper and lower threshold value for light sebnsor

if (sig> lhigh) {                           // set limit
  sig = lhigh;} else                        // setting threshold
  if (sig <llow) {
    sig = llow;};
    
 r = map (sig, llow, lhigh, 5, 80);         // in response, the LED changes
 g = map (sig, llow, lhigh, 5, 80);         // reacting to sensor readings the LED changes
 b = map (sig, llow, lhigh, 5, 80);
  
  Signal = map (sig, llow, lhigh, 0, 100);

  } else


/***********************************
****** Volume sensor ***********
************************************
* the if-loop is condition ****
* for the sensor query and the ***
* resulting reaction ****
************************************/

/***********************************
******* sound sensor ****************
************************************
* the if-clause is the basic *******
* condition to run the routine *****
* for sensor reading ***************
************************************/
                                       

if (id> 920 && id <940) {                     // as above
    k = 3; // see above

    unsigned long startMillis = millis ();    // variables for reading the sensor
    unsigned int peakToPeak = 0;              // variable for sensor reading
                                           
    unsigned int signalMax = 0;               // Variable limits for volume
    unsigned int signalMin = 1024;            // variable peak-to-peak level of loudness
    
/*********************************
** Collect data for 50ms *******
**********************************/

/*********************************
**** collect data for 50 mS ******
**********************************/
    
    while (millis () - startMillis <sampleWindow)
    {
      sample = analogRead (1);                // read the data of the sensor
      if (sample <1024)                       // toss out spurious readings // reading sensor data
      {
        if (sample> signalMax)
          {
          signalMax = sample;                 // Max. Save Level
          }                                   // save just the max levels
        else if (sample <signalMin)
        {
        signalMin = sample;                   // min. Save level
        }                                     // save just the min levels
      }
    }
    
  peakToPeak = signalMax - signalMin;         // Calculation of peak-to-peak amplitude
                                              // calculating the peak-to-peak amplitude
    if (peakToPeak> 670)                      // when a certain volume value is reached
      {                                       // the reaction is a color change into the green
      peakToPeak = 670;} else
        if (peakToPeak <400) {                // if a defined value is reached the controller reacts
         peakToPeak = 400;};                  // by changing its color to bright green
         g = map (peakToPeak, 400, 670, 30, 255);
         r = 0;
         b = 0;
    
    Signal = map (peakToPeak, 400, 670, 0, 100);
}

else

/***********************************
***** temperature sensor *************
************************************
* the if-loop is condition ****
* for the sensor query and the ***
* resulting reaction ****
************************************/

/***********************************
******* temperature sensor ********
************************************
* the if-clause is the basic *******
* condition to run the routine *****
* for sensor reading ***************
************************************/

if (id> 990 && id <1015) {                          // as above
  k = 4;                                            // see above

  if (bot == false) {T0 = sig;};                    // sets the current sensor value when inserted [sig]
   // as the zero output value [T0] of the sensor
                                                    // sets the actual sensor value [sig] as a start value of the temperature sensor [T0]
                                                  
  bot = true; // Temp output variable switch T0
                                                    // switch for T0
   
  if (r = map (sig, T0, T0 + f, 0, 100) <= 0) {r = 0;} // distributes the possible sensor values ​​between [tlow]
    else {r = map (sig, T0, T0 + f, 0, 100);};         // and [thigh] to color values ​​[r] ot and [b] lau
                                                       // divides the possible sensor values ​​between the threshold
                                                       // [tlow] and [thigh] to color values ​​of [r] ed and [b] lue
  b = map (sig, T0, (T0 + 13), 30, 0);
  g = 0;
  
  Signal = map (sig, T0, T0 + f, 0, 100);
   
 if (sig> (T0 + f)) {r = 150;};                   // the [signal] reaches or exceeds a value
                                                  // [thigh] illuminates [r] ot brightest, here max. [150]
                                                  // limits red color to 150
                                                  
  if (b <0) {b = 0; };                            // this line prevents the value for [b] lau from falling below 0 and thus again
                                                  // at very light (250)
                                                  // setting lower threshold for color blue


                                                  // *** changes for 81x to 807 ***
  
  if (Signal >= 51) {T0 = sig;};
  if (sig <= T0) {T0 = sig;};
       
}

else

/***********************************
****** End of the sensor query ******
************************************/

/***********************************
****** End of sensor reading ******
************************************/

/***********************************
 ******** light change *************
 **********************************/

/***********************************
 * the next lines are reasonable ***
 **** for the pulsating light ******
 **********************************/


{
  g=g+a;                             // the value for the [g] light fraction increases slowly (= is incremented)
                                        // the value for green light rises slowly
  Signal = 0;                            // reset the sensor value
                                        // resetting the sensor value
  k=0;                                // reset the discrimination variable of the different sensors; 0 means "no sensor"
                                        // resetting the variable for the sensor ID; 0 means "no sensor"
                                       
  if (g > 20 || g < 0) {g = 0;}           // as soon as [g] ruen reaches the limits between 0 and 20; the increment becomes a decrement
  if (g == 0 || g >= 20) {a = -a ;}     // the [g] rue portion of the LED is reset to 0;
                                        // if [g] reen reaches threshold boundaries between 0 and 20
                                        // it is reset to a value of 0 (no light); the slow increase of [g] becomes a decrease
                                           
  r = g;                                // the colors [r] ed and [b] lue are based on their values
  b = g;                                // [r] ed and [b] lue change as [g] reen does
}
  
colorWipe(strip.Color(r, g, b), 1);   // Call the subprogram "colorWipe" and transfer the color variables
                                        // calls sub-routine "colorWipe" and hands over values ​​for color                           
 
/************************************************* *******************
 **************** Serial.print - Output of values ​​******************
 ************************************************** ******************
 * Caution: the serial output will be 1 to 1 to the Bluetoot Chip **
 * Posted; she controls the character in the app; will the syntax *
 * the output changes, the controller may fail *************
 * ***************************************************************************** *****************
 * becomes the Serial.print command for debugging (= debugging) ********
 * used, for example, the original code has to be commented out ****
 * stay tuned and play again with the original syntax **
 * getting produced **********************************************
 ************************************************** *****************/
 
/************************************************* *******************
 *************** Serial.print part *************************** ***
 ************************************************** ******************
 *** caution: the Serial.print output has to follow this special ****
 syntax; if the syntax has changed the app on your mobile device ***
 * will not be able to recognize your controller output, the game ***
 * will not work anymore; *******************************************
 * ***************************************************************************** *****************
 * you can use the Serial.print part of the program for debugging ***
 * keep the original syntax in a comment line if the Serial.print ***
 * output is used for debugging and restore it for playing f *********
 ************************************************** *****************/


Serial.println ("{");
Serial.print ("\"right button\" : ");
Serial.print("\""); Serial.print(Button1[x]); Serial.print("\"");
Serial.println(",");
Serial.print("\"left button\" : ");
Serial.print("\""); Serial.print(Button2[y]); Serial.print("\"");
Serial.println(",");
Serial.print("\"Sensor\" : ");
Serial.print(Signal);
Serial.println(",");
Serial.print("\"Encoder\" : ");
Serial.print(Position);
Serial.println(",");
Serial.print("\"ID\" : ");
Serial.print("\""); Serial.print(character[k]); Serial.println("\"");
Serial.println("}");
 
/********************** The End  ************************** *************
 ******************* Serial.print ************************** *******
 ************************************************** *****************/

/*********************** END ************************* ***************
 ******************* Serial.print ************************** *******
 ************************************************** *****************/

  strip.show ();
  delay (120);
}

/***********************************
*** colorWipe subprogram ********
************************************
* the subroutine is responsible for *
* the pulsating color change ****
* as long as no sensor plugged **
***********************************/

 
/***********************************
 ******** colorWipe sub-routine ****
 ***********************************
 * if there is no sensor plugged in *
 * this subroutine is reasonable ***
 * for the changes of color every **
 * Cycle of the main program *******
 **********************************/
 
void colorWipe(uint32_t c, uint8_t wait)          

{
  for(uint16_t i=0; i<strip.numPixels(); i++) 
  {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}


/***********************************
 ********* PROGRAMMENTS ************
 **********************************/

/***********************************
********** CODE END ***************
***********************************/
