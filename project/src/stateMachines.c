#include <msp430.h>
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "stateMachines.h"

void setState(){
  if(success){
    setVictory();
  }
  else{
    updateScreen();
    buzzerSetPeriod(0);
  }
}

void updateScreen(){
  //different options for success or not?
}

void setVictory(){
  buzzerSetPeriod(200);
}

void setRedDim(){
  if(count % 2 == 0)
    redOn();
  else
    redOff();
}

void setRedBright(){
  redOn();
}

void setGreenDim(){
 if(count % 2 == 0)
   greenOn();
 else
    greenOff();
}

void setGreenBright(){
  greenOn();
}
