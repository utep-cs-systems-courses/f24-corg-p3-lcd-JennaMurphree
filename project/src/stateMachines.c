#include <msp430.h>
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "stateMachines.h"
#include "lcdutils.h"
#include "lcddraw.h"

void updateViewMethod(){
  fillRectangle(playerCoordinates[0], playerCoordinates[1], 5, 5, COLOR_GREEN);
  drawRectOutline(playerCoordinates[0]-1, playerCoordinates[1]-1, 7, 7, COLOR_RED);
  if(success) setVictory();
  else buzzerSetPeriod(0);
}

void setVictory(){
  buzzerSetPeriod(6067);
  drawString8x12(10, 30, "Christmas", COLOR_GREEN, COLOR_RED);
  drawString8x12(10, 42, "Merry", COLOR_GREEN, COLOR_RED);
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
