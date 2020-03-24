#include <msp430.h>
#include "led.h"
#include "switches.h"


void led_init()
{
  P1DIR |= LEDS;// bits attached to leds are output
  P1OUT = !LED_RED;
  P1OUT = !LED_GREEN;
  switch_state_changed = 1;
  if (switch_state_changed){
    blinkLEDS();
  }
  switch_state_changed = 0;
}

void blinkLEDS(){
  int i =0;
  while(i<5){
    P1OUT = LED_RED;// LED_RED turned ON
    __delay_cycles(1000000);
    P1OUT = LED_GREEN;// LED_GREEN turned ON
    __delay_cycles(1000000);
    P1OUT = !LED_RED; // LED_RED turned OFF
    __delay_cycles(1000000);
    P1OUT = !LED_GREEN; // LED_GREEN turned ON
    __delay_cycles(1000000);
    i++;
  }
}
