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
#include "i2c.h"
#include <i2c/smbus.h>
static void help(void)
{
	fprintf(stderr,
			"Usage: i2ccomm I2CBUS ADDRESS REG DATA\n\n"
			"  I2CBUS is an integer ( 0,1,2 etc... it depends | check /dev/i2c-*)\n"
			"  ADDRESS is a 16bit hexadecimal ( 0x20 )\n"
			"  REG is a 16 bit hexadecimal ( 0x34 )\n"
			"  DATA is hexadecimal (0x34)\n"
			"    Ex for read operatio\n"
			"		i2ccomm 1 0x20 0x36\n"
			"    Ex for write operatio\n"
			"		i2ccomm 1 0x20 0x36 0x45\n");
	exit(1);
}

unsigned char checkHex(int pos, char *argv[])
{
	if(strlen(argv[pos]) != 4)
	{
		printf("%s: is not 4 char long ex: 0x00\n", argv[pos]); 
		return 1;
	}
	else 
	{
		if(argv[pos][1] != 120)
		{
			printf("%s: is not an 16 bit Hex value, Ex 0x34\n",argv[pos]); 
			return 1;
		}
		else 
		{
			return 0;
		}
	}
	return 1;
}

unsigned char checkBusNo(int pos, char *argv[])
{

	if(strlen(argv[pos]) == 1)
	{
		if (isdigit(argv[1][0]))
		{
			return 0; 
		}
	}
	else 
	{
		printf("Please enter a value between 0-9 as i2c bus interface\n"); 
		return 1;
	}
	return 1;
}

int comnvertToDecimal(int pos, char *argv[])
{
	int num = 0; 
	char hex[] = "00";                          // here is the hex string
	hex[0] = argv[pos][2];
	hex[1] = argv[pos][3];
	num = (int)strtol(hex, NULL, 16);       // number base 16
	return num;
}


int main(int argc, char *argv[])
{
	int accErr = 0;
	int deviceAddress = 0;
	int deviceReg = 0;
	int deviceData = 0;
	int i2cBusNo = 0;
	int file = 0; 
	int result = 0; 
	//char buf[24]; 	
	//char char1; 	
	//char current_dev_id = 0;
	//unsigned char read_buf[1]; 

	//printf("Executing : %s\n", argv[0]);
	//printf("Arg Count : %d\n", argc);
	

	if(argc == 4)
	{	
		accErr += checkBusNo(1, argv);
		accErr += checkHex(2, argv);
		accErr += checkHex(3, argv);
		if (accErr == 0)
		{
			i2cBusNo = strtol(argv[1], NULL, 10);
			deviceAddress = comnvertToDecimal(2, argv);
			deviceReg = comnvertToDecimal(3, argv);
			file = i2c_open_device(i2cBusNo,deviceAddress);
			result = i2c_smbus_read_byte_data(file,deviceAddress); 
			printf("recieved : %d\n",result);
			return 0; 
		}
		else 
		{
			help();
		}
	}
	else if (argc == 5)
	{
		accErr += checkBusNo(1, argv);
		accErr += checkHex(2, argv);
		accErr += checkHex(3, argv);
		accErr += checkHex(4, argv);
		if (accErr == 0)
		{
			i2cBusNo = strtol(argv[1], NULL, 10);
			deviceAddress = comnvertToDecimal(2, argv);
			deviceReg = comnvertToDecimal(3, argv);
			deviceData = comnvertToDecimal(4, argv);
			return 0; 
		}
		else 
		{
			help();
		}
	}
	else
	{
		help();
	}
	return 1;
}

int i2c_open_device(int i2cbus, int16_t address)
{
	int fd = 0; // file descriptor 
	char fileName[20]; 
	sprintf(fileName, "/dev/i2c-%d", i2cbus);
	if ((fd = open(fileName, O_RDWR)) < 0) 
	{							
		printf("Error: Could not open file %s%d \n", PORT_I2C, i2cbus);
		exit(1); 
	}

	if (ioctl(fd, I2C_SLAVE, address) < 0) {								 								
		printf("Unable to communicat ewith the slave\n");
		exit(1); 
	}
	else 
	{
		return fd;
	}	
	return 1; 
} 

/*

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
*/
