#include <Arduino.h>

#define L_P_A 2
#define L_P_B 4
#define L_P_C 5

void setup()
{
  pinMode(L_P_A, OUTPUT);
  pinMode(L_P_B, OUTPUT);
  pinMode(L_P_C, OUTPUT);
}

void loop()
{
  digitalWrite(L_P_A, true);
  delay(1000);
  digitalWrite(L_P_A, false);
  delay(1000);
}