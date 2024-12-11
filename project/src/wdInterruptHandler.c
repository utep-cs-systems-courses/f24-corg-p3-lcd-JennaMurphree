#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"

unsigned int count = 0;
unsigned int seconds = 1;//unused currently.  see updateSeconds method
short goalCoordinates[2] = {20, 20};
short playerCoordinates[2] = {5,5};
short previousCoordinates[2] = {5,5};
char success = 0;

void __interrupt_vec(WDT_VECTOR) WDT () {
  if(count == 25){// check every 10th of a second
    updatePosition();
    success = (goalCoordinates[0] <= playerCoordinates[0] && goalCoordinates[1] <= playerCoordinates[1])? 1: 0;
  }
  setState();
  updateCount();
}

void updateCount(){
  if(count >= 25)
    count = 0;
  else
    count++;
}

void updateSeconds(){//unused currently as no changes occur based on seconds.  May be used for music. idk though
  if(seconds >=12)
    seconds = 1;
  else
    seconds++;
}
