// cpp_training.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>
#include "lowlayer/i2c/ll_i2c.h"
#include "driver/pf8574/pf8574lcd.h"
#include <unistd.h>
#include "../c/algorithms/bitgestion.h"

using namespace std;


int main()
{
char strBuffer[20] = "Kerem"; 	
lcd_init(); 
lcd_display_string(0,0,"Test : MA1207P");
lcd_display_string(1,1,"Hello");

uint8_t test[2]  = {13}; 
uint8_t bitToset = 8;
uint8_t startBit = 1; 
uint8_t stopBit = 2;
uint8_t valToset = 2; 
test[1] = 9; 
	cout << "value is now : " << (void*)test[1]<< endl;
 set_bits_range_uint8(&test[1], startBit,stopBit,valToset);

	cout << "value is after :" << (void*)test[1]<< endl;
	std::cout << "\n\n\nReached end of Main" << endl;
	return 0; 
}
