// prpject - ESP32_Lesson_002

#include <Arduino.h>

#define LED_PIN_1 0
#define LED_PIN_2 2
#define LED_PIN_3 15
// Sumylyator
//  https://wokwi.com/projects/new/esp32

void setup()
{
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
}
void loop()
{
  digitalWrite(LED_PIN_1, true);
  delay(200);
  digitalWrite(LED_PIN_1, false);
  delay(100);
  digitalWrite(LED_PIN_2, true);
  delay(200);
  digitalWrite(LED_PIN_2, false);
  delay(100);
  digitalWrite(LED_PIN_3, true);
  delay(200);
  digitalWrite(LED_PIN_3, false);
  delay(100);
}
