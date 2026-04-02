/*
 * Keypad Calculator.c
 *
 * Created: 13/07/2024 8:04:05 am
 * Author : Amr Ezzat
 */ 

#include  <stdio.h>
#include  <string.h>
#define F_CPU 8000000
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_REGISTER.h"
#include "DIO_INTERFACE.h"
#include "LED_INTERFACE.h"
#include "LCD_INTERFACE.h"
#include "KEYPAD_INTERFACE.h"

int main()
{
	LCD_init();
	Kypad_init();
	u8 key;
	int num1 = 0, num2 = 0, result = 0;
	char operator = 0;

	LCD_WriteString("Calculator: ");

	while (1)
	{
		key = Kypad_GetKey();
		if (key != 't') // if not equal t and keypad is pressed
		{
			if (key >= '0' && key <= '9') //if the pressed button is numbers only
			{
				if (operator == 0)
				{
					num1 = num1 * 10 + (key - '0');// to convert from ascii value to integer so it works fine in calculate func
				}
				else
				{
					num2 = num2 * 10 + (key - '0');
				}
				LCD_WriteData(key);
			}
			else if (key == '+' || key == '-' || key == '*' || key == '/')
			{
				if (operator == 0) //check first if operator is zero so i donot write sign 2 times in a row
				{
					operator = key;
					LCD_WriteData(key);
				}
			}
			else if (key == '=')
			{
				result = calculate(num1, num2, operator);
				LCD_GoTo(2, 1);
				LCD_WriteString("Result: ");
				LCD_WriteInteger(result);
			}
            else if (key == 'c')
            {
                // Clear the LCD screen
                LCD_GoTo(1, 1);
                LCD_WriteString("                                 ");
                LCD_GoTo(2, 1);
                LCD_WriteString("                                 ");
                
                // Reset the variables
                num1 = 0;
                num2 = 0;
                operator = 0;

                // Reset the cursor position and display the prompt again
                LCD_GoTo(1, 1);
                LCD_WriteString("Calculator: ");				
            }

			
		}
	}

	return 0;
}
	
	
	
	
	






