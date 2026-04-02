/*
 * LCD_INTERFACE.h
 *
 * Created: 07/07/2024 11:23:47 am
 *  Author: Amr Ezzat
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define LCD_RS_PIN       DIO_Pin7
#define LCD_control_Port DIO_PORTB
#define LCD_Data_Port    DIO_PORTA
#define LCD_EN_PIN       DIO_Pin6

void LCD_init(void);
void LCD_WriteInst(u8 ins);
void LCD_WriteData(u8 Data);
void LCD_WriteChar(u8 Char);
void LCD_GoTo(u8 Row,u8 Col);
void LCD_WriteString(cu8 *Str);
//void LCD_WriteInteger(u16 num);
#endif /* LCD_INTERFACE_H_ */