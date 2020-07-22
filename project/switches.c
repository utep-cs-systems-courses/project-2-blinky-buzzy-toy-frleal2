#include <msp430.h>
#include "switches.h"
//#include "led.h"
//#include "buzzer.h"
#include "stateMachines.h"

char sw1_state,sw2_state,sw3_state,sw4_state;
char switch_state_down, switch_state_changed; // effectively boolean

switch_state = 0;

static char switch_update_interrupt_sense() {
  char p1val = P1IN;
  // update switch interrupt to detect changes from current buttons
  P1IES |= (p1val & SWITCHES);    // if switch up, sense down
  P1IES &= (p1val | ~SWITCHES);   // if switch down, sense up
  return p1val;
}

void
switch_init(){
  P2REN |= SWITCHES;
  P2IE = SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
}

char switch_interrupt_handler(){
  sw1_state_down = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  sw2_state_down = (p2val & SW2) ? 0 : 1; /* 0 when SW2 is up */
  sw3_state_down = (p2val & SW3) ? 0 : 1; /* 0 when SW3 is up */
  sw4_state_down = (p2val & SW4) ? 0 : 1; /* 0 when SW4 is up */

  if (sw1_state_down)
  {
    switch_state = 1;
    state_advance();
  }
  if (sw2_state_down)
  {
    switch_state = 2;
    state_advance();
  }
  if (sw3_state_down)
  {
    switch_state = 3;
    state_advance();
  }
  if (sw4_state_down)
  {
    switch_state = 4;
    state_advance();
  }
  
}
