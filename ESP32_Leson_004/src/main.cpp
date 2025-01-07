// project - ESP32_Lesson_004
//  https://wokwi.com/projects/new/esp32

#include <Arduino.h>
#define PIN_IN_1 23
#define PIN_OUT_RED 13
#define PIN_OUT_JELOW 12
#define PIN_OUT_GREEN 14

int num_color = 0;
char arr_color[4] = {'r', 'j', 'g', 'j'};

void setup()
{
    Serial.begin(115200);
    pinMode(PIN_IN_1, INPUT_PULLUP);

    pinMode(PIN_OUT_RED, OUTPUT);
    pinMode(PIN_OUT_JELOW, OUTPUT);
    pinMode(PIN_OUT_GREEN, OUTPUT);
}

void blink_red(int time);
void blink_jelow(int time);
void blink_green(int time);

void loop()
{
    // bool value = digitalRead(PIN_IN_1);
    // Serial.print(value);
    // delay(200);

    Serial.println(num_color);

    switch (arr_color[num_color])
    {
    case 'r':
        Serial.println("RED");
        blink_red(5000);
        break;
    case 'j':
        Serial.println("JELOW");
        blink_jelow(2000);
        break;
    default:
        Serial.println("GREEN");
        blink_green(5000);
        break;
    }

    ++num_color;
    if (num_color == 4)
        num_color = 0;
}

void blink_red(int time)
{
    digitalWrite(PIN_OUT_RED, true);
    delay(time);
    digitalWrite(PIN_OUT_RED, false);
}

void blink_jelow(int time)
{
    digitalWrite(PIN_OUT_JELOW, true);
    delay(time);
    digitalWrite(PIN_OUT_JELOW, false);
}

void blink_green(int time)
{
    digitalWrite(PIN_OUT_GREEN, true);
    delay(time);
    digitalWrite(PIN_OUT_GREEN, false);
    delay(200);

    digitalWrite(PIN_OUT_GREEN, true);
    delay(1000);
    digitalWrite(PIN_OUT_GREEN, false);
}