#include <avr/interrupt.h>
#include <avr/io.h>

#define FLASH		PB5  // "Pin 13" (Arduino pin) - ATmega168 pin 19
#define CONTROL_PORT	PORTB
#define CONTROL_DDR	DDRB

static void ioinit(void)
{
  CONTROL_DDR = _BV(FLASH);
}

int main(void)
{
  long n;

  ioinit();

  for( ; ; )
    {
      CONTROL_PORT &= ~_BV(FLASH);
      for(n=0; n < 100000; ++n)
        ;
      CONTROL_PORT |= _BV(FLASH);
      for(n=0; n < 100000; ++n)
        ;
      CONTROL_PORT &= ~_BV(FLASH);
      for(n=0; n < 900000; ++n)
        ;
      CONTROL_PORT |= _BV(FLASH);
      for(n=0; n < 100000; ++n)
        ;
    }
}

