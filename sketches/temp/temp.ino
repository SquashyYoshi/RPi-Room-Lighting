
const int TEMP_PIN = A7;
void setup() 
{
    Serial.begin(9600);
    pinMode(TEMP_PIN, INPUT);
}

void loop() 
{
    float raw = analogRead(TEMP_PIN);
    float F = tempToF(raw);
    Serial.print(">temp:");
    Serial.print(F);
    Serial.print("\r\n");
    delay(1500);
}
const float tempToF(int measurement) 
{
    const float R1 = 10000.f;
    const float B = 3950.f;
    const float T0 = 273.15; // 0° Celsius in Kelvin
    const float T25 = 25 + T0; // 25° Celsius in Kelvin
    const float R25 = 5000.f;
    float Rt = R1 * (1023.f / measurement - 1); // Thermistor-Widerstand
    float temperature = 1.f / T25 + 1.f / B  * log(Rt/R25); // Kehrwert der Temperatur
                                                    // in Kelvin
    temperature = 1.0 / temperature - T0; // Celsius
    float far = (temperature * 1.8) + 32;
    return far;
}