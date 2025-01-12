#include <Arduino.h>

// put function declarations here:

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello World");
}

void loop()
{
  // put your main code here, to run repeatedly:

  // Variant 1
  /*
  if (Serial.available() > 0)
  {
    char data = Serial.read();
    Serial.print("Your data  ");
    Serial.println(data);
  }
*/

  // Variant 2
  if (Serial.available() > 0)
  {
    String data = Serial.readStringUntil('\n');
    Serial.print("Your data:  ");
    Serial.println(data);

    if (data == "on")
    {
      Serial.println("Light is ON ");
      // comand to swich_on Light
    }

    if (data == "off")
    {
      Serial.println("Light is OFF ");
      // comand to swich_off Light
    }
  }
};
  // put function definitions here:
