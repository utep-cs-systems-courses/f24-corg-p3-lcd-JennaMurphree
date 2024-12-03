#include <msp430.h>
#include "switches.h"
#include "interuptVectorHandler.h"
#include "stateMachines.h"

void switchInit(){
  P2REN |= SWITCHES;  //enable resistors
  P2IE |= SWITCHES;   // enable switch interrupts
  P2OUT |= SWITCHES;  // pull ups for switches
  P2DIR &= ~SWITCHES; // set swtich bits for input
  switchPressCheck(); //set values that are currently being pressed.  Unsure if necessary 
}

int sw1Down = 0;
int sw2Down = 0;
int sw3Down = 0;
int sw4Down = 0;
int sw1Press = 0;
int sw2Press = 0;
int sw3Press = 0;
int sw4Press = 0;

void switchInterruptHandler(){
  char p2val = switchPressCheck(); //get the values of the switches that have been pressed
  int prev1 = sw1Down;
  int prev2 = sw2Down;
  int prev3 = sw3Down;
  int prev4 = sw4Down;

  //check if the button has been pressed
  sw1Down = (p2val & SW1) ? 0 : 1;
  sw2Down = (p2val & SW2) ? 0 : 1;
  sw3Down = (p2val & SW3) ? 0 : 1;
  sw4Down = (p2val & SW4) ? 0 : 1;

  if (prev1 != sw1Down && sw1Down){
    sw1Press ^= 1;
    //one button presses, all others off
    sw2Press =0, sw3Press =0, sw4Press = 0;
  }
  else if (prev2 != sw2Down && sw2Down){
    sw2Press ^= 1;
    sw1Press = 0, sw3Press = 0; sw4Press = 0;
  }
  else if (prev3 != sw3Down && sw3Down){
    sw3Press ^= 1;
    sw1Press = 0, sw2Press = 0, sw4Press =0;
  }
  else if (prev4 != sw4Down && sw4Down){
    sw4Press ^= 1;
    sw1Press = 0, sw2Press = 0, sw3Press = 0;
  }
  //  if(p2val & SW1){
  //    decreaseRedInterval();
  //  }
  //  else if (p2val & SW2){
  //    increaseRedInterval();
  //  }
  //  else if (p2val & SW3){
  //    decreaseGreenInterval();
  //  }
  //  else if (p2val & SW4){
  //    increaseGreenInterval();
  //  }
}

void updateIntervals(){
  if(sw1Press == 1){
    decreaseRedInterval();
    sw1Press = 0;
  }
  else if(sw2Press == 1){
    increaseRedInterval();
    sw2Press = 0;
  }
  else if(sw3Press == 1){
    decreaseGreenInterval();
    sw3Press = 0;
  }
  else if(sw4Press == 1){
    increaseGreenInterval();
    sw4Press = 0;
  }
}

void increaseRedInterval(){
  if(redInterval >= 4)
    redInterval = 1;
  else
    redInterval++;
}
void decreaseRedInterval(){
  if(redInterval <= 1)
    redInterval = 4;
  else
    redInterval--;
}
void increaseGreenInterval(){
  if(greenInterval >= 4)
    greenInterval = 1;
  else
    greenInterval++;
}
void decreaseGreenInterval(){
  if(greenInterval <= 1)
    greenInterval = 4;
  else
    greenInterval--;
}
