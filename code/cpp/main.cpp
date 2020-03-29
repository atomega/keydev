// cpp_training.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>
#include "lowlayer/i2c/ll_i2c.h"
#include <unistd.h>

using namespace std;

ll_i2c::ll_i2c_address_t i2cAdressmode = ll_i2c::I2C_ADDRESS_7B; 
ll_i2c::ll_i2c_mode_t i2cMode = ll_i2c::I2C_MODE_MASTER; 
ll_i2c::ll_i2c_speed_t i2cSpeed = ll_i2c::I2C_SPEED_STANDART; 
ll_i2c::ll_i2c_state_t i2cStatus = ll_i2c::I2C_STATE_READY; 


ll_i2c bh1750(1, 0x23, i2cMode, i2cAdressmode);

int main()
{
	uint8_t data[2]; 
	uint8_t reg[2]; 

	data[0] = 0; 
	data[1] = 0; 

	reg[0] = 0x20; 

	uint8_t dataLenght = 2; 
	uint8_t regLenght = 1; 

	

	bh1750.i2c_receive(reg,data,&regLenght,&dataLenght); 
	
	cout << "Separeted :\tHigh : "<< (void*) data[0] << endl; 
	cout << "Separeted :\tLow : "<< (void*) data[1] << endl; 

	std::cout << "\n\n\n Reached end of Main" << endl;
	return 0; 
}
