#include <msp430.h>
#include "led.h"
#include "switches.h"

//unsigned char red_on = 0, green_on = 0;
//unsigned char led_changed = 0;

//static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};


void led_init()
{
  P1DIR |= LEDS;// bits attached to leds are output
  P1OUT = !LED_RED;
  P1OUT = !LED_GREEN;
  switch_state_changed = 1;
  if (switch_state_changed){
    blinkLEDS();
  }
  //led_changed = 1;
  //led_update();
  switch_state_changed = 0;
}

void blinkLEDS(){
  int i =0;
  while(i<5){
    P1OUT = LED_RED;
    __delay_cycles(1000000);
    P1OUT = LED_GREEN;
    __delay_cycles(1000000);
    P1OUT = !LED_RED;
    __delay_cycles(1000000);
    P1OUT = !LED_GREEN;
    __delay_cycles(1000000);
    i++;
  }
}
/*   
  if (led_changed) {
    char ledFlags = redVal[red_on] | greenVal[green_on];
    
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;		     // set bit for on leds
    led_changed = 0;
  }
}

*/
