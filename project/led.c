#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "stateMachines.h"




void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  toggle_led = 0;
  led_update();
}

void led_update(){
  char ledFlags =0;

  if (switch_state == 1){
    char ledFlags = 0;

    ledFlags = toggle_led;
    
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;		     // set bit for on leds
  }

  if (switch_state == 2){
    char ledFlags = 0;

    ledFlags = toggle_led;
    
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;		     // set bit for on leds
  }
  
  if (switch_state == 3){
    char ledFlags = 0;

    ledFlags = toggle_led;
    
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;		     // set bit for on leds
  }
}

