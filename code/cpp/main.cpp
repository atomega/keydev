// cpp_training.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "lowlayer/i2c/ll_i2c.h"
//#include "driver/pf8574/pf8574lcd.h"
#include "driver/ma120x0/ma120x0.h"
#include <unistd.h>
#include "../c/algorithms/bitgestion.h"

using namespace std;

int main(int argc, char *argv[])
{
	if(argc =! 2) 
	{
		cout << "Please enter more agrument arg[1] Volume arg[2] Framesize" << endl;
	}
	else 
	{
		int framesize =	atoi(argv[1]); 
		int volume = atoi(argv[2]);
		
		ma_configure(0); 
		ma_printCurrentCconf();
		if ((framesize == 16) || (framesize == 32) || (framesize == 64))
		{
			cout << "Setting frame size to: " << framesize << endl; 
			//ma_setI2sFrameSize(framesize);	// Word data lenght set to 64
		}
		else 
		{
			cout << "False framsize default of 32 will be used !" << endl;
		}
		
		if ((volume > 0) && (volume < 255))
		{
			cout << "setting volume to: "<< volume << endl; 
			ma_setVolumeMaster(0x30,0x0);
		}
		else 
		{
			cout << "Volume not in range setting it to default !" << endl; 
		}
		ma_i2c_update(); 
		ma_i2c_fetch(); 
	}

    return 0; 
}



/*
	uint8_t i = 0; 
	char strBuffer[20] = "Kerem"; 	
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

