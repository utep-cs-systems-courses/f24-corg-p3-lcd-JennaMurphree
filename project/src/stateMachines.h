#ifndef stateMachine_included
#define stateMachine_included

extern unsigned int count, seconds;
extern char success;
extern char updateView;
extern unsigned char goalCoordinates[2];
extern unsigned char playerCoordinates[2];

//short jingleBells[14] = {6067,6067,6067,0,6067,6067,6067,0,6067,5102,7644,6810,6067,0};
//{E,E,E,_,E,E,E,_,E,G,C,D,E,_ }

void updateViewMethod();

#endif
