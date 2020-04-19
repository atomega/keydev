// cpp_training.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>
#include "lowlayer/i2c/ll_i2c.h"
#include "driver/pf8574/pf8574lcd.h"
#include <unistd.h>

using namespace std;


int main()
{
char strBuffer[20] = "Kerem"; 	
lcd_init(); 
lcd_display_string(0,0,"Kerem Sending Energy");
lcd_display_string(1,0,"|#########  |78\% ok");
lcd_display_string(2,0,"Martina Receiving");
lcd_display_string(3,0,"<3");

	std::cout << "\n\n\nReached end of Main" << endl;
	return 0; 
}
