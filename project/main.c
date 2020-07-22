#include <msp430.h>
#include "libTimer.h"
#include "switches.h"
#include "led.h"
#include "buzzer.h"

static enum {S1 = 0, S2 = 1, S3 = 2, S4 = 3, S5 = 4} state =1;
static char sound_ind = 0;
static int theme_song[][34] = {
  {0},
  {1329, 0, 1991, 0, 1491, 0, 1991, 0, 1329, 0, 1991, 0, 1408, 0, 1491, 0, 1991, 0, 2110, 0, 2110, 0, 2110, 0, 2110, 0, 2110, 0, 2110, 0, 1774, 0, 1879, 0}
};
static int soundLen[] = {1, 34};

void static stateAdv(){
  switch(state){
   
    case S1: 
      red_on = 0; green_on = 0;
      break;
    case S2:
      red_on = 1; green_on = 1;
      break;
    case S3:
      red_on = 0; green_on = 1;
      break;
    case S4:
      red_on = 1; green_on = 0;
      break;
    case S5:
      red_on ^= 1; green_on ^= 1; // toggle both LEDs
      break;
    default:
      red_on = 0; green_on = 0;
      state = S1;
  }
  led_changed = 1;
  led_update();

}

static void soundStateAdv(){
  if (sound_ind >= 0 && sound_ind < soundLen[state]){
    buzzer_set_period(theme_song[state][sound_ind++]);
  }else{
    buzzer_set_period(0);
  }
}

void __interrupt_vec(PORT2_VECTOR) port_1(){
  static char p1val, prev_p1val;
  if(P2IFG & SWITCHES){
    P2IFG &= ~SWITCHES;
    switch_interrupt_handler();
    p1val = ~switch_state_down;
    if (p1val & (p1val ^ prev_p1val)){
      state = (state > S5 || state < S1) ? S1 : state + 1;
      sound_ind = 0;
      stateAdv();
    }
    prev_p1val = p1val;
  }
}

void __interrupt_vec(WDT_VECTOR) WDT(){
  static char timerCount = 0;
  if (timerCount % 50 == 0){
    stateAdv();
    soundStateAdv();
  }
  timerCount = (timerCount >= 300) ? 0 : timerCount + 1;
}

int main(){
  configureClocks();
  buzzer_init();
  buzzer_set_period(0);
  led_init();
  switch_init();
  enableWDTInterrupts();
  or_sr(0x18);
}
  

