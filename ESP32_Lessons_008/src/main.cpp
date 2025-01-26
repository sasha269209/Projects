// project - ESP32_Lesson_008

#include <Arduino.h>

// Data for Pins
// const int PIN_OUT_RED = 13;
// const int PIN_OUT_JELOW = 12;
// const int PIN_OUT_GREEN = 14;

//
const int PORT_PIN = 36;
int portValue = 0;

int pwm_Chanel = 0; //Chuse the bcanal 0 (fron 0 to 15)
int frecuence = 1000; //Frecuence of PWM 1kHz
int resolution = 9; //Resolution 9 bits = 512 values
int pwmPin = 22; // Number of PWM pin

void setup()
{
  Serial.begin(115200);

  pinMode(PORT_PIN, INPUT_PULLUP);
  analogReadResolution(9); //fron 9 = 511  to 12 = 4095  

  ledcSetup(pwm_Chanel, frecuence, resolution);
  ledcAttachPin(pwmPin, pwm_Chanel);

}

void loop()
{
  portValue = analogRead(PORT_PIN);
  Serial.println(portValue);

  ledcWrite(pwm_Chanel, portValue);
  delay(500);
}