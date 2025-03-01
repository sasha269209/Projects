#include <Arduino.h>
// Arduino UNO
//

bool ON = true;

volatile unsigned long int timerLED1;
unsigned long int timerRun;
unsigned long int timerStart;

ISR(TIMER0_COMPA_vect)
{
  timerLED1++;
}

// void setup()
int main(void)

{
  // pinMode(PIN_A, OUTPUT);
  DDRB = 0xFF;
  PORTB = 0xFF;

  // interrapt settings

  cli();
  TCCR0A = 0;
  TCCR0B = 0;

  TCCR0A |= (1 << WGM01);

  TIMSK0 |= (1 << OCIE0A);

  // CS00=1 CS01=1 CS02=0 equal 64
  // CS00=0 CS01=1 CS02=0 equal 8
  // CS00=1 CS01=0 CS02=0 equal 1
  TCCR0B |= (1 << CS00); // write 1 in CS00 // ON 
  // TCCR0B &= ~(1 << CS00);  // write 0 in CS00

  //TCCR0B |= (1 << CS01); // write 1 in CS01
  // TCCR0B &= ~(1 << CS01);  // write 0 in CS01

  // TCCR0B |= (1 << CS02);   // write 1 in CS02
  // TCCR0B &= ~(1 << CS02); // write 0 in CS02

  OCR0A = 7; // 7 = 0.5 mk cek

  sei();

  // Serial.begin(9600);

  // void loop()

  while (1)
  {
    cli();
    timerRun = timerLED1;
    sei();

    if (timerRun - timerStart > 2 && ON) // 2 = 1 mk cek
    {
      // digitalWrite(PIN_A, false);
      PORTB &= ~(1 << 5);
      ON = false;
      timerStart = timerRun;
      // Serial.println(timerRun);
    }

    if (timerRun - timerStart > 10 && !ON) // 10 = 5 mk cek
    {
      // digitalWrite(PIN_A, true);
      PORTB |= (1 << 5);
      ON = true;
      timerStart = timerRun;
      // Serial.println(timerRun);
    }
  }
}