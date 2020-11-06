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
#include <sys/ioctl.h>
#include <i2c/smbus.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>
#include <errno.h>
#include <string.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <fcntl.h>

#define PORT_I2C "/dev/i2c-" // Declaration du port a utiliser pour la communication I2C. 

int i2c_open_device(int i2cbus, int16_t address);

/*
int16_t i2c_write_16(int8_t reg, int8_t data); 

int16_t i2c_write_8(int8_t data); 

uint8_t i2c_read_8(int8_t regToRead); 

uint16_t i2c_read_16(int8_t regToRead);
*/
