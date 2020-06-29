// cpp_training.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
//#include "lowlayer/i2c/ll_i2c.h"
//#include "driver/pf8574/pf8574lcd.h"
#include "driver/ma120x0/ma120x0.h"
#include <unistd.h>
#include "../c/algorithms/bitgestion.h"

using namespace std;


int main()
{
	uint8_t i = 0; 
	char strBuffer[20] = "Kerem"; 	
/*
	lcd_init(); 
	printf("PLease enter a string to be displayed on the LCD \n\r >"); 
	fgets(strBuffer,20,stdin); 
	for(i = 0 ; i <= 20 ; i++)
	{
		if(strBuffer[i] == '\n')
		{
			strBuffer[i] = '.'; 
		}

	}
	lcd_display_string(0,0,strBuffer);
*/
/*	ma_configure(0); 
	ma_i2c_update(); 
	ma_i2c_fetch(); 
	ma_printCurrentCconf();
*/
       ma_setVolumeMaster(0x28,0);	

	return 0; 
}
