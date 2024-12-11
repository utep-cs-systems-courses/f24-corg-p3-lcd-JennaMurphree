#include <msp430.h>
#include "switches.h"

//Turn on p2

void __interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) { // check for button interrupt
    P2IFG &= ~SWITCHES; //clear switch interrupts
    switchInterruptHandler(); //methods for when buttons are pressed
  }
}

char switchPressCheck(){
  char p2val = P2IN;

  P2IES |= (p2val & SWITCHES); //set correct switches on
  P2IES &= (p2val | ~SWITCHES); //turn off any non switches that may have accidentally been turned on

  return p2val;
}
