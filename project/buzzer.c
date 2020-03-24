#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include <stdio.h>
#include <stdlib.h>

#define G3 5102
#define A3 4545

#define A4 440
#define G4 391
#define E4 329

void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}
void music(){
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2DIR = BIT6;
  P2SEL |= BIT6;//buzzer turns on
  int song[] = {A4, 0, 0, A4,A4,A4, 0, A4,A4, 0, G4,A4, 0,0,G4,G4,G4};
  int keys = 0;
  for(int i =0; i<20; i++){
    keys = song[i];
    buzzer_set_period(keys);
    __delay_cycles(2500000);
    P2SEL &= ~BIT7;//buzzer turns off
  }
  P2DIR &= ~BIT6;//buzzer stops
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}


    
    
  

