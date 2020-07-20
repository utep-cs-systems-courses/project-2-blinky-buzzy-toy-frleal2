#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "timerLib/libTimer.h"

unsigned char toggle_led;

void state_init(){
  state = 0;
  toggle_led = (toggle_led & LED_RED) ? LED_GREEN : LED_RED;
  led_update();
}

void state_advance()		/* alternate between toggling red & green */
{
  switch (state)
  {
  case 0:
    toggle_led = LED_RED;
    if(switch1_state_down){
      state = 1;
    }
    break;
  case 1:
    toggle_led = LED_GREEN;
    if(switch1_state_down){
      state = 2;
    }
    break;
  case 2:
    toggle_led = LED_RED;
    if (switch1_state_down){
      state = 3;
    }
    break;
  case 3: 
    toggle_led = LED_RED;
    toggle_led = LED_GREEN;
    if (switch1_state_down)
    {
      state = 4;
    }
    break;

  default:
    break;
  }

  led_update();
}
