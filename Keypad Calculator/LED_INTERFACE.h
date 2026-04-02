/*
 * LED_INTERFACE.h
 *
 * Created: 09/07/2024 1:04:52 pm
 *  Author: Amr Ezzat
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_
void LED_PORTON(u8 Port);
void LED_PORTOFF(u8 Port);
void LED_PinON(u8 Port, u8 Pin);
void LED_PinOFF(u8 Port, u8 Pin);
void seven_seg(u8 port ,u8 num);
void LCD_WriteInteger(s16 num);
#endif /* LED_INTERFACE_H_ */