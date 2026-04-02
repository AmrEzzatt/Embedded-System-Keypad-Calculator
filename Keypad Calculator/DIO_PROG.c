/*
 * DIO_PROG.c
 *
 * Created: 01/07/2024 12:45:04 pm
 *  Author: Amr Ezzat
 */ 
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_REGISTER.h"
#include "DIO_INTERFACE.h"
void DIO_VoidSetPortDirection (u8 Port,u8 Direction)
{
	switch(Port)
	{
		case DIO_PORTA:
		DDRA= Direction;
		break;
		case DIO_PORTB:
		DDRB= Direction;
		break;
		case DIO_PORTC:
		DDRC= Direction;
		break;
		case DIO_PORTD:
		DDRD= Direction;
		break;
	}
}
void DIO_VoidSetPortValue(u8 Port,u8 Value)
{
	switch(Port)
	{
		case DIO_PORTA: PORTA = Value;break;
		case DIO_PORTB: PORTB = Value;break;
		case DIO_PORTC: PORTC = Value;break;
		case DIO_PORTD: PORTD = Value;break;
	}
}

void DIO_VoidSetPinDirection(u8 Port ,u8 Pin,u8 Direction)
{
	switch (Port)
	{
			case DIO_PORTA: 
			   if(Direction==OUTPUT)
			     {
				   setbit(DDRA,Pin);
			     }
			   else if (Direction==INPUT)
			       {
					   clrbit(DDRA,Pin);
			       }
				   break;
			case DIO_PORTB: 
			   if(Direction==OUTPUT)
			   {
				   setbit(DDRB,Pin);
			   }
			   else if (Direction==INPUT)
			   {
				   clrbit(DDRB,Pin);
			   }
			   break;
			case DIO_PORTC:
			   if(Direction==OUTPUT)
			   {
				   setbit(DDRC,Pin);
			   }
			   else if (Direction==INPUT)
			   {
				   clrbit(DDRC,Pin);
			   }
			   break;			 
			case DIO_PORTD: 
			   if(Direction==OUTPUT)
			   {
				   setbit(DDRD,Pin);
			   }
			   else if (Direction==INPUT)
			   {
				   clrbit(DDRD,Pin);
			   }
			   break;			
      }

}
void DIO_VoidSetPinValue(u8 Port ,u8 Pin,u8 Value)
{
	switch (Port)
	{
		case DIO_PORTA:
		if(Value==HIGH)
		{
			setbit(PORTA,Pin);
		}
		else if (Value==LOW)
		{
			clrbit(PORTA,Pin);
		}
		break;
		case DIO_PORTB:
		if(Value==HIGH)
		{
			setbit(PORTB,Pin);
		}
		else if (Value==LOW)
		{
			clrbit(PORTB,Pin);
		}
		break;
		case DIO_PORTC:
		if(Value==HIGH)
		{
			setbit(PORTC,Pin);
		}
		else if (Value==LOW)
		{
			clrbit(PORTC,Pin);
		}
		break;
		case DIO_PORTD:
		if(Value==HIGH)
		{
			setbit(PORTD,Pin);
		}
		else if (Value==LOW)
		{
			clrbit(PORTD,Pin);
		}
		break;
	}
	
}

u8 DIO_GetPinVal(u8 Port, u8 Pin)
{
	
	u8 val_ret;
	
	switch(Port)
{
	
			case DIO_PORTA: val_ret=Getbit(PINA,Pin);break;
			case DIO_PORTB: val_ret=Getbit(PINB,Pin);break;
			case DIO_PORTC: val_ret=Getbit(PINC,Pin);break;
			case DIO_PORTD: val_ret=Getbit(PIND,Pin);break;
	
}

return val_ret;
}