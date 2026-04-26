/*
 *NAME: SOURABH B STHAVARAMATH
 *DATE: 12-01-2025
 *FILE NAME: lcd.h
 */

void KM_LCD_Init(void);
void KM_LCD_Write_Cmd(unsigned char);
void KM_LCD_Write_Data(unsigned char);
void write_high_nibble(unsigned char);
void write_low_nibble(unsigned char);
void KM_LCD_Write_Str(char[]);

