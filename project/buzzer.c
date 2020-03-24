#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include <stdio.h>
#include <stdlib.h>

#define E4 330
#define A4 440
#define B4 494
#define Cs5 554
#define D5 587
#define E5 659
#define F5 698
#define G5 784
#define A5 880
#define C5 523

//Notes for ZeldaItem tune
#define Fs5 740
#define Ef5 622
#define A4 440
#define Gs4 415
#define E5 659
#define Gs5 831
#define C6 1046

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
void ZeldaTheme(){
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2DIR = BIT6;
  P2SEL |= BIT6;//buzzer turns on
  
  int song[] = {A4, E4, A4, B4, Cs5, D5, E5, 0, E5, E5, F5, G5, A5, 0, A5, A5, G5, F5, G5, F5, E5, E5, D5, D5, E5, F5, E5, D5, C5, C5, D5, E5, D5, C5};
  
  int keys = 0;
  for(int i =0; i<34; i++){
    keys = song[i];
    buzzer_set_period(keys);
    __delay_cycles(2500000);
    P2SEL &= ~BIT7;//buzzer turns off
  }
  P2DIR &= ~BIT6;//buzzer stops
}

void ZeldaItem(){
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2DIR = BIT6;
  P2SEL |= BIT6;
  int song[] = {0,G5,Fs5,Ef5,A4,Gs4,E5,Gs5,C6};
  int keys = 0;
  for(int i =0; i<9; i++){
    keys = song[i];
    buzzer_set_period(keys);
    __delay_cycles(2500000);
    P2SEL &= ~BIT7;
  }
  P2DIR &= ~BIT6;
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}


    
    
  

