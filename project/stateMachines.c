#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"

unsigned char toggle_led;

void state_init(){
  switch_state = 0;
  //toggle_led = (toggle_led & LED_RED) ? LED_GREEN : LED_RED;
  toggle_led = LED_GREEN;
  led_update();
}

void state_advance(){
  switch (switch_state){
  case 1:
    toggle_led = LED_GREEN;
    break;
  case 2:
    toggle_led = LED_GREEN;
    break;
  case 3:
    toggle_led = LED_GREEN | LED_RED;
    break;
  case 4:
    toggle_led = 0;
    break;
  default: break;
  }
  led_update(); //after the state is set it will update the leds accordingly
}