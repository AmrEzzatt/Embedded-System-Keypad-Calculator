/*
 * KEYPAD_PROG.c
 *
 * Created: 11/07/2024 11:11:46 am
 *  Author: Amr Ezzat
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_REGISTER.h"
#include "DIO_INTERFACE.h"
#include "KEYPAD_INTERFACE.h"
u8 Key_arr[4][4]={{'7','8','9','/'}
,{'4','5','6','*'}
,{'1','2','3','-'}
,{'c','0','=','+'}};

void Kypad_init(void)
{
	for(u8 i=0;i<4;i++)
	{
		/*SET Direction of col----->input*/
		DIO_VoidSetPinDirection(DIO_PORTC,FIRSTCOL+i,INPUT);
	}
	for(u8 i=0;i<4;i++)
	{
		/*Set Direction of RW------->output*/
		DIO_VoidSetPinDirection(DIO_PORTC,FIRSTRW+i,OUTPUT);
	}
	for(u8 i=0;i<4;i++)
	{
		/*SET Values of RW------->1*/
		DIO_VoidSetPinValue(DIO_PORTC,FIRSTRW+i,HIGH);
	}
	for(u8 i=0;i<4;i++)
	{
		/*SET Values of COL------->Pull UP*/
		DIO_VoidSetPinValue(DIO_PORTC,FIRSTCOL+i,HIGH);
	}

}

u8 Kypad_GetKey(void)
{
	u8 COLITERATION = 0;
	u8 RWITERATION = 0;
	u8 RETURN_VAL = 't';
	u8 KEY_VAL;

	for (RWITERATION = 0; RWITERATION < 4; RWITERATION++)
	{
		DIO_VoidSetPinValue(DIO_PORTC,RWITERATION, LOW);
		for (COLITERATION = 4; COLITERATION < 8; COLITERATION++)
		{
			KEY_VAL = DIO_GetPinVal(DIO_PORTC, COLITERATION);
			if (KEY_VAL == 0)
			{
				RETURN_VAL = Key_arr[RWITERATION][COLITERATION - 4];
			}
			while (Getbit(PINC, COLITERATION) == 0);
		}
		DIO_VoidSetPinValue(DIO_PORTC,RWITERATION,HIGH);
	}

	return RETURN_VAL;
}

u16 calculate(u16 num1, u16 num2, u8 operator)
{
	switch (operator)
	{
		case '+': return num1 + num2;
		case '-': return num1 - num2;
		case '*': return num1 * num2;
		case '/': return (num2 != 0) ? num1 / num2 : 0; // Avoid division by zero
		default: return 0;
	}
}