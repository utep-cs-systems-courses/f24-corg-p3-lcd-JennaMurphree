#include <msp430.h>
#include "libTimer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"
#include "stateMachines.h"

char updateView = 1;

int main(void) {
  configureClocks(); /* setup master oscillator, CPU and peripharel clocks */
  lcd_init();
  ledInit();
  buzzerInit();
  switchInit();
  enableWDTInterrupts();

  or_sr(0x8);//GIE on
  
  clearScreen(COLOR_RED);
  
  while(1){
    if(updateView){
      updateView = 0;
      updateViewMethod();
    }
    P1OUT &= ~LED_RED;
    or_sr(0x10); // CPU off
    P1OUT |= LED_RED;
  }
}
