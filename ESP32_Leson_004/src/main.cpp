// project - ESP32_Lesson_004
//  https://wokwi.com/projects/new/esp32

#include <Arduino.h>

const int PIN = 4;
const int DELAY = 50;

int buttonState;
int LastBatonState = LOW;
unsigned long LastDebonsTime = 0;

// put function declarations here:
// int myFunction(int, int);

void setup()
{
  pinMode(PIN, INPUT);
  Serial.begin(115200);
  // put your setup code here, to run once:
  // int result = myFunction(2, 3);


}

void loop()
{
  int reading = digitalRead(PIN);

  if(reading != LastBatonState)
  {
    LastDebonsTime = millis();
  }
  if((millis() - LastDebonsTime) > DELAY)
  {
    if(reading != buttonState)
    {
      buttonState = reading;
      if(buttonState == HIGH)
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
  // put your main code here, to run repeatedly:
}

// put function definitions here:
// int myFunction(int x, int y) {
//   return x + y;
// }