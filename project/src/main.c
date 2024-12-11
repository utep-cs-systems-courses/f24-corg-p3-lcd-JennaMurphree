#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

int main(void) {
  configureClocks(); /* setup master oscillator, CPU and peripharel clocks */
  ledInit();
  buzzerInit();
  switchInit();
  enableWDTInterrupts();

  or_sr(0x18); /* CPU off, GIE on*/
  
}
