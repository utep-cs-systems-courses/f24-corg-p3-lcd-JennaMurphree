#ifndef led_included
#define led_included

#define LED_RED BIT6    //p1.6 flipped on board 69 from usual 
#define LED_GREEN BIT0  //p1.0 flipped on board 69 from usual
#define LEDS (BIT0 | BIT6)

void ledInit();
void ledsOff();
void greenOn();
void greenOff();
void redOn();
void redOff();


#endif
