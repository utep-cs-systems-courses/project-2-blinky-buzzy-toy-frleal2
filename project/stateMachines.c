#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

unsigned char toggle_led;

void state_init(){
  switch_state = 0;
  toggle_led = LED_GREEN | LED_RED;
  led_update();
}

void state_advance(){
  switch (switch_state){
  case 1:
    toggle_led = LED_GREEN;
    buzzer_set_period(750);
    break;
  case 2:
    toggle_led = LED_RED;
    buzzer_set_period(50);
    break;
  case 3:
    toggle_led = LED_GREEN | LED_RED;
    buzzer_set_period(25);
    break;
  case 4:
    toggle_led = 0;
    buzzer_set_period(20);
    break;
  default: break;
  }
  led_update(); //after the state is set it will update the leds accordingly
}