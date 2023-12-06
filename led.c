#include "led.h"
#include <pic16f877a.h>
#include "utilities.h"
#include "gpio.h"

#define LED_TOGGLE_MS (1000)

static void LED_Toggle(tLED led);

void LED_Init(tLED led,tLED_State initial_state)
{
    /* Initialize led pin as an output*/
    switch(led)
    {
    case LED_1:
        //TRISA0 = 0;
        GPIO_InitPortPin(PORT_B, 0, GPIO_OUTPUT);
        break;
    case LED_2:
        //TRISA1 = 0;
        GPIO_InitPortPin(PORT_B, 1, GPIO_OUTPUT);
        break;
    case LED_3:
        //TRISA2 = 0;
        GPIO_InitPortPin(PORT_B, 2, GPIO_OUTPUT);
        break;
    case LED_4:
        //TRISA3 = 0;
        GPIO_InitPortPin(PORT_B, 3, GPIO_OUTPUT);
        break;
    default:
        /* Should not be here */
        break;
    }
    /* Set led state */
    LED_SetState(led, initial_state);
}

void LED_Update(void)
{
    /* Toggle initialized led with period*/
    LED_Toggle(LED_3);
    UTIL_DelayMS(LED_TOGGLE_MS);
}

void LED_SetState(tLED led, tLED_State state)
{
    switch(led)
    {
    case LED_1:
        //RB0 = state;
        GPIO_SetPortPinState(PORT_B, 0, state);
        break;
    case LED_2:
        //RB1 = state;
        GPIO_SetPortPinState(PORT_B, 1, state);
        break;
    case LED_3:
        //RB2 = state;
        GPIO_SetPortPinState(PORT_B, 2, state);
        break;
    case LED_4:
        //RB3 = state;
        GPIO_SetPortPinState(PORT_B, 3, state);
        break;
    default:
        /* Should not be here */
        break;
    }
}

tLED_State LED_GetState(tLED led)
{
    tLED_State ret = LED_OFF;

    switch(led)
    {
    case LED_1:
        //ret = RB0;
        ret = GPIO_GetPortPinState(PORT_B, 0);
        break;
    case LED_2:
        //ret = RB1;
        ret = GPIO_GetPortPinState(PORT_B, 1);
        break;
    case LED_3:
        //ret = RB2;
        ret = GPIO_GetPortPinState(PORT_B, 2);
        break;
    case LED_4:
        //ret = RB3;
        ret = GPIO_GetPortPinState(PORT_B, 3);
        break;
    default:
        /* Should not be here */
        break;
    }

    return ret;
}

static void LED_Toggle(tLED led)
{
   if(LED_GetState(led) == LED_ON)
   {
       LED_SetState(led, LED_OFF);
   }else
   {
       LED_SetState(led, LED_ON);
   }
}
