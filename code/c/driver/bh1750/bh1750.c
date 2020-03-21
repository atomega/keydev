#include"../../main.h"
#include"../../baremetal/i2c_raspberry/i2c/i2c.h"
#include"bh1750.h"




void bh1750_open(void)
{
	i2c_open_device(BH1750_ADDR); 
}

uint8_t bh1750_sleep(void)
{
	if(i2c_write_8(BH1750_POWER_DOWN))
	{
		printf("F: %s|L: %d | ERROR Power Down\n", __FILE__, __LINE__); 
		return 1; 
	}
	else 
	{
		return 0; 
	}	
	
	return 1; 
}

uint8_t bh1750_wake(void)
{
	if(i2c_write_8(BH1750_POWER_ON))
	{
		printf("F: %s|L: %d | ERROR Power Down\n", __FILE__, __LINE__); 
		return 1; 
	}
	else 
	{
		return 0; 
	}	
	
	return 1; 
}

uint8_t bh1750_reset(void)
{
	if(i2c_write_8(BH1750_RESET))
	{
		printf("F: %s|L: %d | ERROR Reset\n", __FILE__, __LINE__); 
		return 1; 
	}
	else 
	{
		return 0; 
	}	
	
	return 1; 
}

uint8_t bh1750_set_mode(uint8_t mode)
{
	if(i2c_write_8(mode))
	{
		printf("F: %s|L: %d | ERROR Reset\n", __FILE__, __LINE__); 
		return 1; 
	}
	else 
	{
		return 0; 
	}	

	return 1; 	

}

uint16_t bh1750_oneShot(uint8_t mode)
{
	if(mode != BH1750_ONE_TIME_HIGH_RES_MODE_1 &&  BH1750_ONE_TIME_HIGH_RES_MODE_2 && BH1750_ONE_TIME_LOW_RES_MODE)
	{
		printf("F: %s Not One Shot mode\n",__FILE__); 
	}
	else 
	{
		
		int16_t result = 0;
		int16_t recieved = 0;
	
		recieved = i2c_read_16(mode);
 		result = bh1750_calculateLumen(recieved);   
		printf("F: %s Light level : \t %u Lux\n",__FILE__,result);
		return result;  
	}
	return 0xffff;
}

int16_t bh1750_calculateLumen(int16_t measured)
{
	#ifdef BH1750_DEBUG
	int8_t high = 0; 
	int8_t low = 0;
  	high = (unsigned char)(measured >> 8);
  	low  = measured & 0xff;
	printf("Returned value : %u \n", measured); 	
	printf("Separeted :\tHigh : 0x%x \n", high & 0xff); 
	printf("Separated :\tLow : 0x%x \n", low & 0xff); 
	#endif	
	
	int16_t lux = 0; 
	lux=((measured & 0xff00)>>8) | ((measured & 0x00ff)<<8);		
	return lux; 
} 

