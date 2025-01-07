// prpject - ESP32_Lesson_003
//  https://wokwi.com/projects/new/esp32

#include <Arduino.h>
#define PIN_IN_1 23
#define PIN_IN_2 4
#define PIN_IN_3 4

void setup()
{

    Serial.begin(115200);
    // pinMode(PIN_IN_1, INPUT);
    // pinMode(PIN_IN_1, INPUT_PULLDOWN);
    pinMode(PIN_IN_1, INPUT_PULLUP);
}

void loop()
{
    bool value =  digitalRead(PIN_IN_1);
    Serial.print(value);
    delay(200);

}

// // prpject - ESP32_Lesson_002
//
// #include <Arduino.h>
//
// #define LED_PIN_1 0
// #define LED_PIN_2 2
// #define LED_PIN_3 15
// // Sumylyator
// //  https://wokwi.com/projects/new/esp32
//
// void setup()
// {
//   pinMode(LED_PIN_1, OUTPUT);
//   pinMode(LED_PIN_2, OUTPUT);
//   pinMode(LED_PIN_3, OUTPUT);
// }
// void loop()
// {
//   digitalWrite(LED_PIN_1, true);
//   delay(200);
//   digitalWrite(LED_PIN_1, false);
//   delay(100);
//   digitalWrite(LED_PIN_2, true);
//   delay(200);
//   digitalWrite(LED_PIN_2, false);
//   delay(100);
//   digitalWrite(LED_PIN_3, true);
//   delay(200);
//   digitalWrite(LED_PIN_3, false);
//   delay(100);
// }
