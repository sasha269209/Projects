// project - ESP32_Lesson_007

#include <Arduino.h>

// Data for Pins
// const int PIN_OUT_RED = 13;
// const int PIN_OUT_JELOW = 12;
// const int PIN_OUT_GREEN = 14;

//
const int PORT_PIN = 36;
int portValue = 0;

void setup()
{
  Serial.begin(115200);

  pinMode(PORT_PIN, INPUT_PULLUP);
  analogReadResolution(9); //fron 9 = 511  to 12 = 4095  
}

void loop()
{
  portValue = analogRead(PORT_PIN);
  Serial.println(portValue);
  delay(500);
}