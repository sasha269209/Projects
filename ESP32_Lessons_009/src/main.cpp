#include <Arduino.h>
#define LED 13

void setup()
{
  pinMode(LED, OUTPUT);
}

void loop()
{
  digitalWrite(13, 1);
   ets_delay_us(1);

  digitalWrite(13, 0);
  ets_delay_us(5);
  
}


// vTaskDelay(10);
// pinMode(13, OUTPUT);

// digitalWrite(13, 1);
// foo(1000000);

// digitalWrite(13, 0);
// foo(1000000);