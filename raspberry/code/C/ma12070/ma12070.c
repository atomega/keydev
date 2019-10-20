#include"../main.h"
#include"../i2c/i2c.h"
#include"../algorithms/bitgestion.h"
#include"ma12070.h"


int curretnVolume = 0; 

uint8_t ma12070_init(void)
{
		
	// Openning the i2c port for communication
	i2c_open_device(0x20); 

	return 1;
}

int16_t ma12070_getVolume(void)
{
	
	uint8_t DbFraction = 0; 
	uint8_t DbFractionTab[3] = {25,50,75}; 
	uint8_t DbNumber = 0; 
 	int16_t volume = 0; 
	

	DbNumber = 23; //i2c_read_8(MA12070_REG_VOL_VAL); 
 	DbFraction = 3; //i2c_read_8(MA12070_REG_VOL_VAL_DEC);
	
	volume += (24 - DbNumber) * 100 - DbFractionTab[DbFraction-1];    
			
	printf("Volume: %d\t", volume); 
}


uint8_t ma12070_setVolume(int16_t volume)
{
	int16_t DbBuff = 0; 
	uint8_t DbFraction = 0; 
	uint8_t DbNumber = 0; 
   		
	//printf("Volume: %d\t", volume); 
	
	if (volume >= 0)
	{
		if( volume <= MA12070_VOL_MAX)
		{
			DbFraction = (char) glnb_int16(volume,2); 
			DbBuff = (volume/100); 
			
			if(DbFraction == 0)
			{
				DbBuff = (MA12070_VOL_MAX_DB) - DbBuff; 
			}
			else 
			{
				DbFraction = (DbFraction^3) + 1; 
				DbBuff = (MA12070_VOL_MAX_DB) - DbBuff -1; 
			}
			
			DbNumber = (char)DbBuff; 
		//	printf("Bdnumber: %u\tfraction: %u \n",DbNumber, DbFraction); 
			
			
			i2c_write_16(MA12070_REG_VOL_VAL, DbNumber); 
			i2c_write_16(MA12070_REG_VOL_VAL_DEC, DbFraction); 
			
			return 0; 
		}
		else 
		{
			
			return 1; 
		}
		return 1; 							
	} 
	else
	{	
		if(volume >= MA12070_VOL_MIN)
		{
			DbFraction = (char) glnb_int16(volume,2); 
			DbBuff = (volume/100); 
			
			if(DbFraction == 0)
			{
				DbBuff = abs(DbBuff) + 24;
			}
			else 
			{	 
				DbFraction = (DbFraction^3) + 1; 
				DbBuff = abs(DbBuff) + 24 ;
			}
			
			DbNumber = (char)DbBuff; 
		//	printf("Bdnumber: %u\tfraction: %u \n",DbNumber, DbFraction);
						
			i2c_write_16(MA12070_REG_VOL_VAL, DbNumber); 
			i2c_write_16(MA12070_REG_VOL_VAL_DEC, DbFraction); 
			
			return 0; 
		}
		else
		{
			return 1; 
		}
	}
}



uint8_t ma12070_configure(uint8_t Default)
{
	//Set the device back to default setings
	if(Default)
	{	
		return 0; 	
	}
	else 
	{
		return 0; 
	}
	return 1; 
}

