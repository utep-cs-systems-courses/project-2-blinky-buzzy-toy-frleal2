#include <msp430.h>
#include "led.h"
#include "switches.h"

unsigned char led_off; //definition of global variable

unsigned char state;

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

void led_update()
{
   if (switch_state_changed) {
    char ledFlags = 0; /* by default, no LEDs on */
    
    if(!led_off){ //if the led off variable is set to 0 then our leds have to be both off so we do not execute this
      ledFlags |= switch_state_down ? LED_GREEN : 0;
      ledFlags |= switch_state_down ? 0 : LED_RED;
    }
    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }
  switch_state_changed = 0;
}

