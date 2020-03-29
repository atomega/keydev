/////////////////////////////////////////////////////////
// Created by 	: Kerem Yollu												
//	Project 		: Multiprise conectée
//	Date 			: 27.12.2017
//			
//_________________________Info_________________________
//
// Header pour I2C.c ecrit pour l'utilisation du protocol 
// I2C avec une raspberry PI 3 
//
/////////////////////////////////////////////////////////
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define PORT_I2C "/dev/i2c-1" // Declaration du port a utiliser pour la communication I2C. 


int16_t i2c_write_16(int8_t reg, int8_t data); 

int16_t i2c_write_8(int8_t data); 

void i2c_open_device(int16_t address); 

uint8_t i2c_read_8(int8_t regToRead); 

uint16_t i2c_read_16(int8_t regToRead);
