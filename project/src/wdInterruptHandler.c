#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"

unsigned int count = 0;
unsigned int seconds = 1;
unsigned int redInterval = 1;
unsigned int greenInterval = 3;
char redBright = 0;
char greenBright = 0;

void __interrupt_vec(WDT_VECTOR) WDT () {
  if(count == 250){
    redBright = (seconds%redInterval == 0)? 1 : 0;
    greenBright = (seconds % greenInterval == 0)? 1 : 0;
    updateSeconds();
    updateIntervals();
  }
  setState();
  updateCount();
}

void updateCount(){
  if(count >= 250)
    count = 0;
  else
    count++;
}

void updateSeconds(){
  if(seconds >=12)
    seconds = 1;
  else
    seconds++;
}
