/*
 * LED_PROG.c
 *
 * Created: 09/07/2024 1:04:32 pm
 *  Author: Amr Ezzat
 */ 


#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_REGISTER.h"
#include "DIO_INTERFACE.h"
#include "LED_INTERFACE.h"
void LED_PORTON(u8 Port)
{
	switch (Port)
	{
		case DIO_PORTA:DDRA=OUTPUT;PORTA=HIGH_PORT;break;
		case DIO_PORTB:DDRB=OUTPUT;PORTA=HIGH_PORT;break;
		case DIO_PORTC:DDRC=OUTPUT;PORTA=HIGH_PORT;break;
		case DIO_PORTD:DDRD=OUTPUT;PORTA=HIGH_PORT;break;
	}
}
void LED_PORTOFF(u8 Port)
{
	switch (Port)
	{
		case DIO_PORTA:PORTA=LOW_PORT;break;
		case DIO_PORTB:PORTA=LOW_PORT;break;
		case DIO_PORTC:PORTA=LOW_PORT;break;
		case DIO_PORTD:PORTA=LOW_PORT;break;
	}
}
void LED_PinON(u8 Port, u8 Pin) 
{
	switch (Port)
	{
		case DIO_PORTA:DDRA=OUTPUT;setbit(PORTA,Pin);break;
		case DIO_PORTB:DDRB=OUTPUT;setbit(PORTB,Pin);break;
		case DIO_PORTC:DDRC=OUTPUT;setbit(PORTC,Pin);break;
		case DIO_PORTD:DDRD=OUTPUT;setbit(PORTD,Pin);break;
	}
}

void LED_PinOFF(u8 Port, u8 Pin)
{
	switch (Port)
	{
		case DIO_PORTA:clrbit(PORTA,Pin);break;
		case DIO_PORTB:clrbit(PORTB,Pin);break;
		case DIO_PORTC:clrbit(PORTC,Pin);break;
		case DIO_PORTD:clrbit(PORTD,Pin);break;
	}
}

void seven_seg(u8 port ,u8 num)
{
	switch(num)
	{
		case 0:
		DIO_VoidSetPortValue(port,0b00111111);
		break;
		case 1:
		DIO_VoidSetPortValue(port,0b00000110);
		break;
		case 2 :
		DIO_VoidSetPortValue(port,0b01011011);
		break;
		case 3:
		DIO_VoidSetPortValue(port,0b01001111);
		break;
		case 4 :
		DIO_VoidSetPortValue(port,0b01100110);
		break;
		case 5:
		DIO_VoidSetPortValue(port,0b01101101);
		break;
		case 6 :
		DIO_VoidSetPortValue(port,0b01111101);
		break;
		case 7 :
		DIO_VoidSetPortValue(port,0b00000111);
		break;
		case 8:
		DIO_VoidSetPortValue(port,0b01111111);
		break;
		case 9:
		DIO_VoidSetPortValue(port,0b01101111);
		break;
		
		
		
	}
}
