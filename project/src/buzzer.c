#include <msp430.h>
#include "libTimer.h"

void buzzerInit() {
    timerAUpmode();		// used to drive speaker
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		// enable output to speaker (P2.6) 
}

void buzzerSetPeriod(short cycles) {
  // buzzer clock = 2MHz.  (period of 1k results in 2kHz tone)
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		// one half cycle
}
