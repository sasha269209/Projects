#include <Arduino.h>
// Arduino UNO

const int PIN_A = 8;


void setup()
{
  pinMode(PIN_A, OUTPUT);
}

void loop()
{
  // 1 m cek  PIN_A
  digitalWrite(PIN_A, HIGH);
  for (int i = 0; i > 100; i++)
  {
    i = i + 1 - 1;
  }
  digitalWrite(PIN_A, LOW);

  // 9 m cek  pauza
    for (int i = 0; i > 900; i++)
  {
    i = i + 1 - 1;
  }
}
