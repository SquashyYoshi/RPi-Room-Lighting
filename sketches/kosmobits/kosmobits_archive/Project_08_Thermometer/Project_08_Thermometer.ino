#include <KosmoBits_Pins.h>
#include <KosmoBits_Thermistor.h>

const int sensorPin = KOSMOBITS_SENSOR_PIN;

void setup() {
  pinMode(sensorPin, INPUT);

  Serial.begin(115200); // Enable output via
// serial monitor.
}

void loop() {
  int measurement = analogRead(sensorPin);
  float celsius = thermistor_measurement_in_celsius(measurement); // Convert
// measurement into degrees Celsius.
  Serial.print(celsius); // Celsius value
// is output.
  Serial.println(" Degrees Celsius"); // Output of 
// "degrees Celsius" and line break.

  delay(1000);
}
