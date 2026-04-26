#include "main.h"


void KM_LCD_Init(void)
{
	HAL_Delay(20);
	KM_LCD_Write_Cmd(0x33);
	HAL_Delay(1);
	KM_LCD_Write_Cmd(0x32);
	KM_LCD_Write_Cmd(0x0c);
	KM_LCD_Write_Cmd(0x01);
}

void KM_LCD_Write_Cmd(unsigned char command)
{	
	HAL_GPIO_WritePin(GPIOB, LCD_RS_Pin, GPIO_PIN_RESET); //reset RSPin to select as command
	write_high_nibble(command);
	write_low_nibble(command);
}

void KM_LCD_Write_Data(unsigned char data)
{
	HAL_GPIO_WritePin(GPIOB, LCD_RS_Pin, GPIO_PIN_SET); //set RSPin to select as data
	write_high_nibble(data);
	write_low_nibble(data);
}

void write_high_nibble(unsigned char data)
{	
	data>>=4; //shifting higher nibble right 4 times to load to ODR
	data&=0x0f; //cleaning higher 4-bits
	HAL_GPIO_WritePin(GPIOB, LCD_D4_Pin|LCD_D5_Pin|LCD_D6_Pin|LCD_D7_Pin |LCD_EN_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,LCD_D7_Pin,(data&0x8));
	HAL_GPIO_WritePin(GPIOB,LCD_D6_Pin,(data&0x4));
	HAL_GPIO_WritePin(GPIOB,LCD_D5_Pin,(data&0x2));
	HAL_GPIO_WritePin(GPIOB,LCD_D4_Pin,(data&0x1));
	
	HAL_GPIO_WritePin(GPIOB, LCD_EN_Pin, GPIO_PIN_SET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(GPIOB, LCD_EN_Pin, GPIO_PIN_RESET);
}

void write_low_nibble(unsigned char data)
{
	data&=0x0f; //cleaning higher 4-bits to load 
	HAL_GPIO_WritePin(GPIOB, LCD_D4_Pin|LCD_D5_Pin|LCD_D6_Pin|LCD_D7_Pin |LCD_EN_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,LCD_D7_Pin,(data&0x8));
	HAL_GPIO_WritePin(GPIOB,LCD_D6_Pin,(data&0x4));
	HAL_GPIO_WritePin(GPIOB,LCD_D5_Pin,(data&0x2));
	HAL_GPIO_WritePin(GPIOB,LCD_D4_Pin,(data&0x1));
	HAL_GPIO_WritePin(GPIOB, LCD_EN_Pin, GPIO_PIN_SET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(GPIOB, LCD_EN_Pin, GPIO_PIN_RESET);
}

void KM_LCD_Write_Str(char* str)
{
	register int i;
	for(i=0;*(str+i);i++)
		KM_LCD_Write_Data(*(str+i));
}

