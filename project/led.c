#include <msp430.h>
#include "led.h"
#include "switches.h"

unsigned char led_off; //definition of global variable

unsigned char state;

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  led_update();
}

void led_update(){
  char ledFlags = 0;

  ledFlags = toggle_led;

  P1OUT &= (0xff - LEDS) | ledFlags;
  P1OUT |= ledFlags;
}

