/*
 * DIO_INTERFACE.h
 *
 * Created: 30/06/2024 3:04:54 pm
 *  Author: Amr Ezzat
 */ 



#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_Pin0 0
#define DIO_Pin1 1
#define DIO_Pin2 2
#define DIO_Pin3 3
#define DIO_Pin4 4
#define DIO_Pin5 5
#define DIO_Pin6 6
#define DIO_Pin7 7

#define OUTPUT 255
#define INPUT 0

#define HIGH 1
#define LOW 0

#define HIGH_PORT 255
#define LOW_PORT  0

#define PORT_MAX		4
#define PIN_MAX			8

void DIO_VoidSetPortDirection(u8 Port,u8 Direction);
void DIO_VoidSetPortValue(u8 Port,u8 Value);
void DIO_VoidSetPinDirection(u8 Port ,u8 Pin,u8 Direction);
void DIO_VoidSetPinValue(u8 Port ,u8 Pin,u8 Value);
u8 DIO_GetPinVal(u8 Port, u8 Pin);
#endif /* DIO_INTERFACE_H_ */