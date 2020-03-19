#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"

//char switch_state_down,
char switch_state_changed; /* effectively boolean */
int state =0;

static char switch_update_interrupt_sense(){
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE = SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  //led_update();
  switch_interrupt_handler();
}

void
switch_interrupt_handler(){
  switch_state_changed = 0;
  char p2val = switch_update_interrupt_sense();
  if(p2val & SW1 ? 0 : 1){
    state = 01;
  }
  if(p2val & SW2 ? 0:1){
    state = 02;
  }
  if(p2val & SW3 ? 0:1){
    state = 03;
  }
  if(p2val & SW4 ? 0:1){
    state = 04;
  }

  switch(state){
  case 01:
    switch_state_changed = 1;
    blinkLEDS();
    music();
    
    break;
  case 02:
    switch_state_changed = 1;
    blinkLEDS();
    
    
    break;
  case 03:
    switch_state_changed = 1;
    blinkLEDS();

    break;
  case 04:
    switch_state_changed = 1;
    blinkLEDS();

    break;

  default:

    break;
  }
}
/*
  switch_state_down = (p1val & SW1) ? 0 : 1;  0 when SW1 is up 
  switch_state_changed = 1;
  led_update();
}
*/
