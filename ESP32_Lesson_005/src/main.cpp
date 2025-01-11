// project - ESP32_Lesson_005
//  https://wokwi.com/projects/new/esp32

#include <Arduino.h>
#define PIN_IN_1 23
#define PIN_OUT_RED 13
#define PIN_OUT_JELOW 12
#define PIN_OUT_GREEN 14

//Data for ligning
int num_color = 0;
char arr_color[4] = {'r', 'j', 'g', 'j'};

//Data for Button
const int DELAY = 50;
int buttonState = LOW; // LOW for INPUT_PULLUP or HIGH for INPUT_PULLDOWN
int LastBatonState = LOW;
unsigned long LastDebonsTime = 0;
int reading;

void setup()
{
  Serial.begin(115200);

  pinMode(PIN_IN_1, INPUT_PULLDOWN);

  pinMode(PIN_OUT_RED, OUTPUT);
  pinMode(PIN_OUT_JELOW, OUTPUT);
  pinMode(PIN_OUT_GREEN, OUTPUT);
}

void blink_red();
void blink_jelow();
void blink_green();

void foo();

void loop()
{
  foo();

  switch (arr_color[num_color])
  {
  case 'r':
    // Serial.println("RED");
    blink_red();
    break;
  case 'j':
    // Serial.println("JELOW");
    blink_jelow();
    break;
  default:
    // Serial.println("GREEN");
    blink_green();
    break;
  }
}

void blink_red()
{
  digitalWrite(PIN_OUT_RED, true);
  digitalWrite(PIN_OUT_JELOW, false);
  digitalWrite(PIN_OUT_GREEN, false);
}

void blink_jelow()
{
  digitalWrite(PIN_OUT_JELOW, true);
  digitalWrite(PIN_OUT_RED, false);
  digitalWrite(PIN_OUT_GREEN, false);
}

void blink_green()
{
  digitalWrite(PIN_OUT_GREEN, true);
  digitalWrite(PIN_OUT_RED, false);
  digitalWrite(PIN_OUT_JELOW, false);
}

void foo()
{
  reading = digitalRead(PIN_IN_1); // LOW or HIGHT - of butoon (normal LOW)

  if (reading != LastBatonState) // if button LOW -and- LastBatonState=LOW >> FALSE
  {
    LastDebonsTime = millis();
  }
  if ((millis() - LastDebonsTime) > DELAY)
  {
    if (reading != buttonState) // normal LOW -and- buttonState=LOW >> FALSE
    {
      buttonState = reading;
      if (buttonState == HIGH)
      {
        Serial.print("Button Pressed   ");
        // ++ count (go HIGT)
        ++num_color;
        if (num_color == 4)
          num_color = 0;
      }
      else
      {
        Serial.println("Button UP   ");
        // ++ count (go LOW)
      }
    }
  }
  LastBatonState = reading;
};
