// project - ESP32_Lesson_005

#include <Arduino.h>

// Data for Pins
const int PIN_IN_1 = 23;
const int PIN_OUT_RED = 13;
const int PIN_OUT_JELOW = 12;
const int PIN_OUT_GREEN = 14;

// Data for ligning
int num_color = 0;
char arr_color[4] = {'r', 'j', 'g', 'j'};

// Data for Button
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

void read_button();

void loop()
{
  read_button(); // This function is changing "num_color"
                 //  acordin to reading button

  if (num_color > 3) // "num_color" can be (from 0 to 3)
    num_color = 0;

  switch (arr_color[num_color]) // This function take "num_color"
                                //  and light this color
  {
  case 'r':
    blink_red();
    break;
  case 'j':
    blink_jelow();
    break;
  default:
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

void read_button()
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