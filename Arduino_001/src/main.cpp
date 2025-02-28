#include <Arduino.h>
// Arduino UNO
//

const int PIN_A = 13;
bool ON;

volatile unsigned long int timerLED1;
unsigned long int timerRun;
unsigned long int timerStart;

ISR (TIMER0_COMPA_vect)
{
  timerLED1++;
}

void setup()
{
  pinMode(PIN_A, OUTPUT);
  // interrapt settings
  TCCR0A |= (1 << WGM01);
  // OCR0A = 0xF9; // 249
  OCR0A = 0xC7; // 199 - C7
  TIMSK0 |= (1 << OCIE0A);
  // TCCR0B |= (1 << CS01) | (1 << CS00);
  TCCR0B |= (1 << CS01);
  sei();

  Serial.begin(9600);
}

void loop()
{
  cli();
  timerRun = timerLED1;
  sei();

  // delay (1000);
  // Serial.println (timerRun);



  if (timerRun - timerStart > 100)
  {
    digitalWrite(PIN_A, ON = !ON);
    timerStart = timerRun;
  }
}
