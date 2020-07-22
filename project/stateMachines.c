#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"

void state_init(){
  red_on = 1;
  green_on = 0;
  switch_state = 0;
}

void state_advance(){
  switch (switch_state){
  case 1:
    red_on = 1;
    green_on = 0;
    break;
  case 2:
    red_on = 1;
    green_on = 1;
    break;
  case 3:
    red_on = 0;
    green_on = 1;
    break;
  case 4:
    red_on = 0;
    green_on = 0;
    break;
  }
  led_update(); //after the state is set it will update the leds accordingly
}