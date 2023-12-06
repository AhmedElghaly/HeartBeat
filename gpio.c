#include "gpio.h"
#include <pic16f877a.h>

#define SET_REGISTER_PIN(REG, BIT, VAL) ((REG) = (((REG) & (~(1<<BIT))) | ((VAL) << (BIT))))
#define READ_REGISTER_PIN(REG, BIT) ((REG &(1<<BIT)) >> (BIT))


void GPIO_InitPortPin(tPort port, unsigned char pin, tPortDirection direction)
{
    switch(port)
    {
    case PORT_A:
        SET_REGISTER_PIN(TRISA, pin, direction);
    break;
    case PORT_B:
        SET_REGISTER_PIN(TRISB, pin, direction);
    break;
    case PORT_C:
        SET_REGISTER_PIN(TRISC, pin, direction);
    break;
    case PORT_D:
        SET_REGISTER_PIN(TRISD, pin, direction);
    break;
    case PORT_E:
        SET_REGISTER_PIN(TRISE, pin, direction);
    break;
    }
}

void GPIO_Update(void)
{
    /* Nothing to do */
}


void GPIO_SetPortPinState(tPort port, unsigned char pin, unsigned char state)
{
    switch(port)
    {
    case PORT_A:
        SET_REGISTER_PIN(PORTA, pin, state);
    break;
    case PORT_B:
        SET_REGISTER_PIN(PORTB, pin, state);
    break;
    case PORT_C:
        SET_REGISTER_PIN(PORTC, pin, state);
    break;
    case PORT_D:
        SET_REGISTER_PIN(PORTD, pin, state);
    break;
    case PORT_E:
        SET_REGISTER_PIN(PORTE, pin, state);
    break;
    }
}

unsigned char GPIO_GetPortPinState(tPort port, unsigned char pin)
{
    unsigned char ret = 0;

    switch(port)
    {
    case PORT_A:
        ret =  READ_REGISTER_PIN(PORTA, pin);
    break;
    case PORT_B:
        ret =  READ_REGISTER_PIN(PORTB, pin);
    break;
    case PORT_C:
        ret =  READ_REGISTER_PIN(PORTC, pin);
    break;
    case PORT_D:
        ret =  READ_REGISTER_PIN(PORTD, pin);
    break;
    case PORT_E:
        ret =  READ_REGISTER_PIN(PORTE, pin);
    break;
    }

    return ret;
}
