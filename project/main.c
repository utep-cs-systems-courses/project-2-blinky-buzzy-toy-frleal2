#include <msp430.h>
#include "libTimer.h"
#include "switches.h"
#include "led.h"
#include "buzzer.h"

int main(){
  configureClocks();
  switch_init();
  //buzzer_init();
  //buzzer_set_period(0);
  led_init();

  state_init();
  
  //enableWDTInterrupts();
  or_sr(0x18);
}
  

