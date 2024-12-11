#include <msp430.h>
#include "led.h"


void ledInit(){
  P1DIR |= LEDS; // mark LEDS values as outputs
  ledsOff(); 
}

void ledsOff(){
  //initialize LED outputs to off  
  P1OUT &= ~LEDS;
}

void greenOn(){
  P1OUT |= LED_GREEN;
}

void greenOff(){
  P1OUT &= ~LED_GREEN;
}

void redOn(){
  P1OUT |= LED_RED;
}

void redOff(){
  P1OUT &= ~LED_RED;
}
