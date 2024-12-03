#include <msp430.h>
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "stateMachines.h"

void setState(){
  if(redBright)
    setRedBright();
  else
    setRedDim();
  if(greenBright)
    setGreenBright();
  else
    setGreenDim();
  //set buzzer
  if(redInterval == greenInterval)
    buzzerSetPeriod(1582);
  else
    buzzerSetPeriod(0);
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
