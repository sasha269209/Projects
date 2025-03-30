#include <Arduino.h>

int sensoRead = 15;
int out_sygnal;
const int PIN_OUT = 10;
const int PIN_IN_S = 11;
const int PIN_IN_D = 12;

int compureDID(float input, float setpoint, float kp, float ki, float kd, float dt);

void setup()
{
  pinMode(PIN_OUT, OUTPUT);
  pinMode(PIN_IN_S, INPUT);
  pinMode(PIN_IN_D, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int set_temp = analogRead(PIN_IN_S);
  int data_temp = analogRead(PIN_IN_D);

  out_sygnal = compureDID(data_temp, set_temp, 1.0, 1.0, 1.0, 2.0);
  analogWrite(PIN_OUT, out_sygnal);

  Serial.print(set_temp);
  Serial.print("  ");
  Serial.print(data_temp);
  Serial.print("  ");
  Serial.println(out_sygnal);
  delay(2000);
}

int compureDID(float input, float setpoint, float kp, float ki, float kd, float dt)
{
  float err = setpoint - input;
  static float integral = 0, prevErr = 0;
  integral += err * dt;
  float D = (err - prevErr) / dt;
  prevErr = err;
  return (err * kp + integral * ki + D * kd);
}