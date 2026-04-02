/*
 * LCD_PROG.c
 *
 * Created: 07/07/2024 11:23:16 am
 *  Author: Amr Ezzat
 */ 
#define F_CPU 8000000
#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_REGISTER.h"
#include "DIO_INTERFACE.h"
#include "LCD_INTERFACE.h"

void LCD_init(void)
{
	   DIO_VoidSetPortDirection(LCD_Data_Port ,OUTPUT);
	   DIO_VoidSetPortDirection(LCD_control_Port,OUTPUT);
	   DIO_VoidSetPinValue(LCD_control_Port,LCD_RS_PIN ,LOW); // RS=0 ,RW i have already connect it to ground
	   _delay_ms(50);
	   LCD_WriteInst(0B00111000);
	   LCD_WriteInst(0B00001100);
	   LCD_WriteInst(0B00000001);
	   LCD_WriteInst(0B00000110);
}

void LCD_WriteInst(u8 ins)
{
	DIO_VoidSetPinValue(LCD_control_Port,LCD_RS_PIN ,LOW); // RS=0
	DIO_VoidSetPortValue(LCD_Data_Port,ins) ;
		/*Pulse Enable*/
		DIO_VoidSetPinValue(LCD_control_Port,LCD_EN_PIN,HIGH);
		_delay_ms(1);
		DIO_VoidSetPinValue(LCD_control_Port,LCD_EN_PIN,LOW);
		_delay_ms(1);	
	
}

void LCD_WriteData(u8 Data)
{
		/*send data*/
		DIO_VoidSetPinValue(LCD_control_Port,LCD_RS_PIN,HIGH); //RS HIGH
		DIO_VoidSetPortValue(LCD_Data_Port,Data);
		/*Pulse Enable*/
		DIO_VoidSetPinValue(LCD_control_Port,LCD_EN_PIN,HIGH);
		_delay_ms(1);
		DIO_VoidSetPinValue(LCD_control_Port,LCD_EN_PIN,LOW);
		_delay_ms(1);
}

void LCD_WriteChar(u8 Char)
{
	LCD_WriteData(Char);
}
void LCD_GoTo(u8 Row,u8 Col)
{
		Col--;
		Row--;
			switch(Row)
			{
				case 0:LCD_WriteInst(0X80+Col);break;
				case 1:LCD_WriteInst(0XC0+Col);break;
			}
}

void LCD_WriteString(cu8 * Str)
{
	u8 i = 0;  

	while (Str[i] != '\0')
    {
		LCD_WriteData(Str[i]);

		i++;  
	}
}

void LCD_WriteInteger(s16 num)
{
	// Handle negative numbers
	if (num < 0)
	{
		LCD_WriteData('-');
		num = -num; // Convert negative number to positive
	}
	
	// Handle the case when the number is 0
	if (num == 0)
	{
		LCD_WriteData('0');
		return;
	}
	
	// Array to store digits and a variable to keep track of the number of digits
	char digits[10];
	int i = 0;
	
	// Extract digits in reverse order
	while (num > 0)
	{
		digits[i++] = (num % 10) + '0';// to convert from integer value to ascii again for ex 1+'0'-->1+48=49-->'1'
		num /= 10;
	}
	
	// Write digits to LCD in correct order
	for (int j = i - 1; j >= 0; j--)
	{
		LCD_WriteData(digits[j]);
	}
}
