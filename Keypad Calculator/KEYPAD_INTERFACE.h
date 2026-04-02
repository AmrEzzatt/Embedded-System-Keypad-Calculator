/*
 * KEYPAD_INTERFACE.h
 *
 * Created: 11/07/2024 11:16:37 am
 *  Author: Amr Ezzat
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_



#define FIRSTCOL  DIO_Pin4
#define FIRSTRW   DIO_Pin0





void Kypad_init(void);
u8   Kypad_GetKey(void);
u16 calculate(u16 num1, u16 num2, u8 operator);


#endif /* KEYPAD_INTERFACE_H_ */