// project - ESP32_Lesson_005
//  https://wokwi.com/projects/new/esp32

#include <Arduino.h>

const int PIN = 22;
const int PIN_2 = 2;

const int DELAY = 50;

int buttonState;
int LastBatonState = LOW;
unsigned long LastDebonsTime = 0;
int reading;

// put function declarations here:
// int myFunction(int, int);
void foo();

void setup()
{
  pinMode(PIN, INPUT_PULLDOWN);
  Serial.begin(115200);
  pinMode(PIN_2, OUTPUT);
  // put your setup code here, to run once:
  // int result = myFunction(2, 3);
}

void loop()
{
  foo();
  digitalWrite(PIN_2, buttonState);
  // put your main code here, to run repeatedly:
};

void foo()
{
  reading = digitalRead(PIN);

  if (reading != LastBatonState)
  {
    LastDebonsTime = millis();
  }
  if ((millis() - LastDebonsTime) > DELAY)
  {
    if (reading != buttonState)
    {
      buttonState = reading;
      if (buttonState == HIGH)
      {
        Serial.print("Button Pressed");
      }
      else
      {
        Serial.print("Button UP");
      }
    }
  }
  LastBatonState = reading;
};
// put function definitions here:
// int myFunction(int x, int y) {
//   return x + y;
// }