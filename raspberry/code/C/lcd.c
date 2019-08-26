//////////////////////////////////////////////////////////
// Created by 	: Kerem Yollu												
//	Project 		: Multiprise conectée
// Nom			: lcd.c
// Header 		: lcd.h			
//_________________________Info_________________________
//
// Libraire pour le control d'un ecran lcd stadard (HD44780)
// controlée par un expandeur de port PCF8574 en I2C. 
//
//////////////////////////////////////////////////////////

#include "main.h"
#include "lcd.h"
#include "i2c.h"


// Fonction pour initialiser l'écran vide en mode 4 bits 
int i2c_lcd_init(int addrs)
{
	i2c_open_device(addrs);			// adressage de l'escave en i2c 
	lcd_write(0x03,CMD_MODE); 		// Mise en mode 4 bit avec 4 essai conssecutif
 	lcd_write(0x03,CMD_MODE); 
  	lcd_write(0x03,CMD_MODE); 
	lcd_write(0x02,CMD_MODE);  
	lcd_write(LCD_FUNCTIONSET | LCD_2LINE | LCD_5x8DOTS | LCD_4BITMODE ,CMD_MODE); 
	lcd_write(LCD_DISPLAYCONTROL | LCD_DISPLAYON ,CMD_MODE); 
	lcd_write(LCD_CLEARDISPLAY ,CMD_MODE); 
	lcd_write(LCD_ENTRYMODESET | LCD_ENTRYLEFT ,CMD_MODE); 
	return 1; 				
}


// Fonction qui vas afficher une pharse sur la ligne et colone qui lui est indiquée 
// Attention la fonction est capable de calculer la liongeure d0ubn phrase mais il ne 
// faut pas dépasser la limite d'une ligne totale qui est de 20 charactères max  
// 
//                  LCD 20x4
//	-------------------------------------------
//	||# # # # # # # # # # # # # # # # # # # #|| 
// ||# # # # # # # # # # # # # # # # # # # #|| 
// ||# # # # # # # # # # # # # # # # # # # #|| 
// ||# # # # # # # # # # # # # # # # # # # #||
// ------------------------------------------- 
void lcd_display_string(char line, char pos, char* charvalue)
{
	char setPosition = 0;	
	int i, S_length = 0; 
	char buf[TOTAL_CHAR_CAP];							// buffer contenant la quantité de char dissponible sur une ligne   
	

	S_length	= strlen(charvalue); 	
	if (S_length > TOTAL_CHAR_CAP)
	{
		printf("LCD.C :\t La phrase est trop longue => %d MAX: %d \n", S_length, TOTAL_CHAR_CAP); 
		exit(1); 
	}
	else 
	{	
		strcpy(buf, charvalue);								
		S_length	= strlen(buf); 		
		
		#ifdef LCD_DEBUG		
		printf("LCD.C :\t Longeure de la prhase => %d \n", S_length); 
		printf("LCD.C :\t Ligne selectionee => %d \n", line); 
		#endif
		
		if(line == 1)											// Selection de la ligne d'écriture 
		{
			setPosition = pos; 		
		}
		else if(line ==2)
		{
			setPosition = 0x40 + pos; 
		}
		else if(line ==3)
		{
			setPosition = 0x14 + pos;
		}
		else if(line ==4)
		{
			setPosition = 0x54 + pos; 
		}
		else 
		{
			setPosition = -1; 
		}
		
		if(setPosition >= 0)
		{
			lcd_write(LCD_SETDDRAMADDR + setPosition, CMD_MODE);

			for(i = 0; i < S_length; i++ )
			{
				lcd_write(buf[i],RS); 
			}	
		
		#ifdef LCD_DEBUG		
		printf("LCD.C :\t Ectiture reussit => %s \n", buf); 
		#endif	
		}
		else 
		{
			printf("LCD.C :\t Mauvais numéro de ligne => %d  MAX:4 Min:1 \n", line); 
			exit(1); 	
		}
	}
}

// Cette focntion nous pernet de faire pulser la ppin EN du lcd afin qu'il puisse 
// enregistrer les donées qui lui sont envoyées 
void ldc_pulse_En(char data)
{
	i2c_write_8(data | EN | LCD_BACKLIGHT);
	usleep(100);  
	i2c_write_8(((data & ~EN) | LCD_BACKLIGHT));
	usleep(500);  
}

// Cette fonction nous permet d'envoyer un information de 8 bits sous format 
// de 2x4 bites. Celà est necessaire du au fonctionnement de l'expendeur de port PCF8574
// qui est branché sur l'écran de facon a ce qu'il communiquer en 4 bits.  
void lcd_write(char cmd, char mode)
{
	lcd_write_4bits(mode | (cmd & 0xF0)); 
  	lcd_write_4bits(mode | ((cmd << 4) & 0xF0)); 	
}

// Fonction nous permettant d'nevoyer 4 bits dinformation sur le PC8574 ainsi que 
// le rétroéclairage. 
void lcd_write_4bits(char data)
{	
	i2c_write_8(data | LCD_BACKLIGHT);
	ldc_pulse_En(data); 
}
