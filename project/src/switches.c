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

int sw1Press = 0;
int sw2Press = 0;
int sw3Press = 0;
int sw4Press = 0;

void switchInterruptHandler(){
  char p2val = switchPressCheck(); //get the values of the switches that have been pressed
  //clear previous button presses, possibly unnecessary as they get cleared in the updatePosition method
  sw1Press = 0, sw2Press = 0, sw3Press = 0, sw4Press = 0;
//if instead of if else so that multiple buttons can be pressed at the same time
  if(~p2val & SW1){
    sw1Press = 1;
  }
  if (~p2val & SW2){
    sw2Press = 1;
  }
  if (~p2val & SW3){
    sw3Press = 1;
  }
  if (~p2val & SW4){
    sw4Press = 1;
  }
}

void updatePosition(){
  previousCoordinates[0] = playerCoordinates[0];
  previousCoordinates[1] = playerCoordinates[1];
  if(sw1Press == 1){
    moveLeft();
    P1OUT |= BIT0;
    sw1Press = 0;
  }
  if(sw2Press == 1){
    moveRight();
    P1OUT &= ~BIT0;
    sw2Press = 0;
  }
  if(sw3Press == 1){
    moveUp();
    P1OUT |= BIT6;
    sw3Press = 0;
  }
  if(sw4Press == 1){
    moveDown();
    P1OUT &= ~BIT6;
    sw4Press = 0;
  }
}

void moveLeft(){
  //x axis is in cell 0, 0,0 is in top left corner so moving left is subtracting
  playerCoordinates[0]--;
}
void moveRight(){
  playerCoordinates[0]++;
}
void moveUp(){
  playerCoordinates[1]--;
}
void moveDown(){
  playerCoordinates[1] ++;
}
