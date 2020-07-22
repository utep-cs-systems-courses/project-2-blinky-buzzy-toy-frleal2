#include <msp430.>
#include "switches.h"

char switch_state_down, switch_state_changed; // effectively boolean

static char switch_update_interrupt_sense() {
  char p1val = P1IN;
  // update switch interrupt to detect changes from current buttons
  P1IES |= (p1val & SWITCHES);    // if switch up, sense down
  P1IES &= (p1val | ~SWITCHES);   // if switch down, sense up
  return p1val;
}

void switch_init() {
  P1REN |= SWITCHES;       // enables resistors for switches
  P1IE |= SWITCHES;        // enable interuppts from switches
  P1OUT |= SWITCHES;       // pull-ups for switches
  P1DIR &= ~SWITCHES;      // set switches' bits for input
  switch_update_interrupt_sense();
}

char switch_interrupt_handler(){
  char p1val = switch_update_interrupt_sense();
  switch_state_down = (p1val & SW1) ? 0 : 1; // 0 when SW1 is up
  switch_state_changed = 1;
  return p1val;
}
