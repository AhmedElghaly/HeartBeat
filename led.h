#ifndef __LED_H__
#define __LED_H__

typedef enum
{
    LED_1,
    LED_2,
    LED_3,
    LED_4
}tLED;

typedef enum
{
	LED_OFF,
	LED_ON
}tLED_State;

void LED_Init(tLED led,tLED_State initial_state);
void LED_Update(void);  //====> void - void to work as a task or ISR
void LED_SetState(tLED led, tLED_State state);
tLED_State LED_GetState(tLED led);

#endif // __LED_H
