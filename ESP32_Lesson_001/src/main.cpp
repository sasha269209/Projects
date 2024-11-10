// prpject - ESP32_Lesson_001

#include <Arduino.h>

#define LED_PIN 2

// Sumylyator
//  https://wokwi.com/projects/new/esp32

void setup() //////
{
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(LED_PIN, true);
  delay(1000);
  digitalWrite(LED_PIN, false);
  delay(1000);
}

// put function definitions here:
