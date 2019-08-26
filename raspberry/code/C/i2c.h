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


int i2c_write_16(char reg, char data); 

int i2c_write_8(char data); 

void i2c_open_device(int address); 
