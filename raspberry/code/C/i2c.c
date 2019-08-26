//////////////////////////////////////////////////////////
// Created by 	: Kerem Yollu												
//	Project 		: Multiprise conectée
// Nom			: i2c.c
// Header 		: i2c.h			
//_________________________Info_________________________
//
// Header pour I2C.c ecrit pour l'utilisation du protocol 
// I2C avec une raspberry PI 3 
// La Fonction "write" pour la communication en i2c est déja 
// compris dans les libraires du raspian 
//////////////////////////////////////////////////////////
#include "main.h"
#include "i2c.h"


int fd = 0; 																		// File description (pour suivre létat du port i2c) 
char buf[24]; 	
char current_dev_id = 0;




//Initialisation de la communication avec un IC
// PORT_I2C Definit dan i2c.h corresspond au nom du port I2C a etre tuilisé
void i2c_open_device( int address )
{
	char *fileName = PORT_I2C; 
	
	if ((fd = open(fileName, O_RDWR)) < 0)		 							// Ouverture du port pour le lecture et l'écriture 
	{							
		printf("I2C.C :\tOuverture du port I2C a echoue\n");
		exit(1); 
	}

	if (ioctl(fd, I2C_SLAVE, address) < 0) {								// mise en place du port (SLAVE) et l'addresse de l'IC esclave 								
		printf("I2C.C :\tLe BUS n'arrive pas a acommuniquer avec l'ésclave\n");
		exit(1); 
	}
	else 
	{
		buf[0] = 0;																	// This is the register we want to read from
		current_dev_id = address; 
	}
	
} 


//Ecriture de 8 bits sur l'excave qui à été initialisé dans i2c_open_device() 
int i2c_write_8(char data)														
{
	buf[0] = data; 
	if ((write(fd, buf, 1)) != 1) 											// Ecriture d'un seul élément présent sur le buffer
	{	
		#ifdef I2C_DEBUG
		printf("I2C.C :\tErreur d'ecriture : 8 bits \n");
		printf("I2C.C :\tDonee : 0x%x \n", buf[0] & 0xff); 
		printf("I2C.C :\tAddresse : 0x%x \n \n", current_dev_id & 0xff); 
		#endif
		return 1; 
	}
	else 
	{
		
		#ifdef I2C_DEBUG
		printf("I2C.C :\tEcriture reussit : 8 bits \n");
		printf("I2C.C :\tDonee : 0x%x \n", buf[0] & 0xff); 
		printf("I2C.C :\taddresse : 0x%x \n \n", current_dev_id & 0xff);  
		#endif
		return 0; 
	}
	
	return 1; 
}


//Ecriture de 16 bits sur l'escave qui à été initialisé dans i2c_open_device() 
int i2c_write_16(char reg, char data)
{
	buf[0] = reg; 
	buf[1] = data; 
	if ((write(fd, buf, 2)) != 2) 											// Ecriture de deux éléments présent sur le buffer
	{														
		#ifdef I2C_DEBUG
		printf("I2C.C :\tErreur d'ecriture : 16 bits \n");
		printf("I2C.C :\tDonee 1  : 0x%x \n", buf[0] & 0xff); 
		printf("I2C.C :\tDonee 2  : 0x%x \n", buf[1] & 0xff);
		printf("I2C.C :\tAddresse : 0x%x \n \n", current_dev_id & 0xff);  
		#endif
		return 1; 
	}	
	else 
	{
		#ifdef I2C_DEBUG
		printf("I2C.C :\tEcriture reussit : 16 bits \n");
		printf("I2C.C :\tDonee 1  : 0x%x \n", buf[0] & 0xff); 
		printf("I2C.C :\tDonee 2  : 0x%x \n", buf[1] & 0xff);
		printf("I2C.C :\tAddresse : 0x%x \n \n", current_dev_id & 0xff);  
		#endif
		return 0; 
	}
	
	return 1; 
}

