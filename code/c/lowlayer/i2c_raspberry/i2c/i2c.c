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
#include "../../../main.h"
#include "i2c.h"

int16_t fd = 0; 																		// File description (pour suivre létat du port i2c) 
int8_t buf[24]; 	
int8_t current_dev_id = 0;
uint8_t read_buf[1]; 



//Initialisation de la communication avec un IC
// PORT_I2C Definit dan i2c.h corresspond au nom du port I2C a etre tuilisé
void i2c_open_device( int16_t address )
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


void i2c_close_device(uint16_t address)
{
	
}


//Ecriture de 8 bits sur l'excave qui à été initialisé dans i2c_open_device() 
int16_t i2c_write_8(int8_t data)														
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
int16_t i2c_write_16(int8_t reg, int8_t data)
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

uint8_t i2c_read_8(int8_t regToRead)
{
	if (i2c_write_8(regToRead))
	{
			#ifdef I2C_DEBUG
			printf("I2C.C :\t Erreur de demande de lecture : 8 bits \n");
			printf("I2C.C :\t Addresse : 0x%x \n \n", regToRead & 0xff);  
			#endif
	
	}	
	else 
	{	
		if ((read(fd, read_buf, 1)) != 1) 											// Lecture d'un éllemnt dans le buffer. 
		{	
			#ifdef I2C_DEBUG
			printf("I2C.C :\t Erreur de lecture : 8 bits \n");
			printf("I2C.C :\t Registre \t : 0x%x \n", regToRead & 0xff); 
			printf("I2C.C :\t Recut 1 \t : 0x%x \n", read_buf[0] & 0xff); 
			printf("I2C.C :\t Addresse \t : 0x%x \n \n", current_dev_id & 0xff);  
			#endif
		}
		else 
		{
			#ifdef I2C_DEBUG
			printf("I2C.C :\t Lecture reuissit : 8 bits \n");
			printf("I2C.C :\t Registre \t : 0x%x \n", regToRead & 0xff); 
			printf("I2C.C :\t Recut 1 \t : 0x%x \n", read_buf[0] & 0xff); 
			printf("I2C.C :\t Addresse \t : 0x%x \n \n", current_dev_id & 0xff);  
			#endif
			return read_buf[0]; 	
		}
	}	
		return read_buf[0]; 	
}

uint16_t i2c_read_16(int8_t regToRead)
{
	uint16_t result = 0;

	if (i2c_write_8(regToRead))
	{
			#ifdef I2C_DEBUG
			printf("I2C.C :\t Erreur de demande de lecture : 8 bits \n");
			printf("I2C.C :\t Addresse : 0x%x \n \n", regToRead & 0xff);  
			#endif
	
	}	
	else 
	{	
		if ((read(fd, read_buf, 2)) != 2) 											// Lecture d'un éllemnt dans le buffer. 
		{	
			#ifdef I2C_DEBUG
			printf("I2C.C :\t Erreur de lecture : 8 bits \n");
			printf("I2C.C :\t Registre \t : 0x%x \n", regToRead & 0xff); 
			printf("I2C.C :\t Recut 1 \t : 0x%x \n", read_buf[0] & 0xff); 
			printf("I2C.C :\t Recut 2 \t : 0x%x \n", read_buf[1] & 0xff); 
			printf("I2C.C :\t Addresse \t : 0x%x \n \n", current_dev_id & 0xff);  
			#endif
		}
		else 
		{
			#ifdef I2C_DEBUG
			printf("I2C.C :\t Lecture reuissit : 8 bits \n");
			printf("I2C.C :\t Registre \t : 0x%x \n", regToRead & 0xff); 
			printf("I2C.C :\t Recut 1 \t : 0x%x \n", read_buf[0] & 0xff); 
			printf("I2C.C :\t Recut 2 \t : 0x%x \n", read_buf[1] & 0xff); 
			printf("I2C.C :\t Addresse \t : 0x%x \n \n", current_dev_id & 0xff);  
			#endif
			printf("I2C.C :\t Recut 1 \t : 0x%x \n", read_buf[0] & 0xff); 
			printf("I2C.C :\t Recut 2 \t : 0x%x \n", read_buf[1] & 0xff); 
			result = read_buf[1] + (read_buf[0] >> (CHAR_BIT - 2));
			return result;  	
		}
	}	
		return result; 	
}

