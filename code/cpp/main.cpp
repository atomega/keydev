// cpp_training.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cmath>
#include "baremetal/i2c/bm_i2c.h"
#include <unistd.h>






		
	  
//Start measurement at 4lx resolution. Time typically 16ms.
#define BH1750_CONTINUOUS_LOW_RES_MODE 0x13
//Start measurement at 1lx resolution. Time typically 120ms
#define BH1750_CONTINUOUS_HIGH_RES_MODE_1 0x10
//Start measurement at 0.5lx resolution. Time typically 120ms
#define BH1750_CONTINUOUS_HIGH_RES_MODE_2 0x11
//Start measurement at 1lx resolution. Time typically 120ms
//Device is automatically set to Power Down after measurement.
#define BH1750_ONE_TIME_HIGH_RES_MODE_1 0x20
//Start measurement at 0.5lx resolution. Time typically 120ms
//Device is automatically set to Power Down after measurement.
#define BH1750_ONE_TIME_HIGH_RES_MODE_2 0x21
//Start measurement at 1lx resolution. Time typically 120ms
//Device is automatically set to Power Down after measurement.
#define BH1750_ONE_TIME_LOW_RES_MODE 0x23

#define BH1750_POWER_DOWN  0x00 // No active state
#define BH1750_POWER_ON    0x01 // Power on
#define BH1750_RESET       0x07 // Reset data register value

#define BH1750_ADDR 0x23 // Device Adress 

uint8_t bh1750_sleep(void); 
uint8_t bh1750_wake(void); 
void bh1750_open(void); 
uint8_t bh1750_reset(void); 
uint8_t bh1750_set_mode(uint8_t mode); 
uint16_t bh1750_oneShot(uint8_t mode);
int16_t bh1750_calculateLumen(int16_t measured); 


using namespace std;

uint8_t data[10]; 
uint8_t reg[10];

bm_i2c::bm_i2c_address_t i2cAdressmode = bm_i2c::I2C_ADDRESS_7B; 
bm_i2c::bm_i2c_mode_t i2cMode = bm_i2c::I2C_MODE_MASTER; 
bm_i2c::bm_i2c_speed_t i2cSpeed = bm_i2c::I2C_SPEED_STANDART; 
bm_i2c::bm_i2c_state_t i2cStatus = bm_i2c::I2C_STATE_READY; 

bm_i2c bh1750(1, BH1750_ADDR, i2cMode, i2cAdressmode);

int main()
{
	bh1750_oneShot(BH1750_ONE_TIME_HIGH_RES_MODE_1);
    std::cout << "\n\n\n Reched end of Main" << endl;
	return 0; 
}

uint16_t bh1750_oneShot(uint8_t mode)
{
	if(mode != BH1750_ONE_TIME_HIGH_RES_MODE_1 &&  BH1750_ONE_TIME_HIGH_RES_MODE_2 && BH1750_ONE_TIME_LOW_RES_MODE)
	{
		printf("F: %s Not One Shot mode\n",__FILE__); 
	}
	else 
	{
		reg[0] = mode;
		data[0] = 0x01; 
		data[1] = 0x02; 

		uint8_t RegisterLenght = 1; 
		uint8_t Datalenght = 2;
		int16_t result = 0;
		
		std::cout << "Recieved data[0] = " << data[0] << endl << "recieved data[1] = " << data[1] << endl; 

		bh1750.receive(data,reg,&Datalenght,&RegisterLenght);
		                                     
 		result = bh1750_calculateLumen(29);   
		printf("F: %s Light level : \t %u Lux\n",__FILE__,result);
		return result;  
	}
}

int16_t bh1750_calculateLumen(int16_t measured)
{
	int8_t high = 0; 
	int8_t low = 0;
  	high = data[0];
  	low  = data[1];

	cout << "Separeted :\tHigh : "<< (void*) data[0] << endl; 
	cout << "Separeted :\tLow : "<< (void*) data[1] << endl; 
	
	int16_t lux = 0; 
	lux= high | low;		
	return lux; 
} 
		
