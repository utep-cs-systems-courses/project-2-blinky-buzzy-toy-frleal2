#include <msp430.h>
#include "libTimer.h"
#include "switches.h"
#include "led.h"
#include "buzzer.h"

int main(){
  configureClocks();
  
  switch_init();
  led_init();
  
  state_init();
  
  or_sr(0x18);
}
  

