#include"../main.h"
#include"../i2c/i2c.h"
#include"../algorithms/bitgestion.h"
#include"ma12070.h"


int curretnVolume = 0; 

uint8_t Buffer = 0; 
S_MA12070 amp; 

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

	DbNumber = 23; 	
	// amp.vol_db_master = i2c_read_8(MA12070_REG_VOL_VAL); 
 	DbFraction = 3; 	
	// amp.vol_lsb_master = i2c_read_8(MA12070_REG_VOL_VAL_DEC);
	
	volume += (24 - DbNumber) * 100 - DbFractionTab[DbFraction-1];    
			
	printf("Volume: %d\t", volume); 
	return 1; 
}



uint8_t ma12070_setPowerMode(uint8_t mode)
{
	Buffer = 0; //i2c_read_8(MA12070_REG_POWER_MODE_CONTROL);
  		
	switch(mode)
	{
		case MA12070_POWER_MODE_1:
	 		Buffer = set_nth_bit_uint8(Buffer,MA12070_POWER_MODE_LSB); 
	 		Buffer = unset_nth_bit_uint8(Buffer,MA12070_POWER_MODE_MSB); 
			amp.power_mode = Buffer; 
			i2c_write_16(MA12070_REG_POWER_MODE_CONTROL,amp.power_mode); 
			return 0; 
		
		case MA12070_POWER_MODE_2: 	
	 		Buffer = unset_nth_bit_uint8(Buffer,MA12070_POWER_MODE_LSB); 
	 		Buffer = set_nth_bit_uint8(Buffer,MA12070_POWER_MODE_MSB); 
			amp.power_mode = Buffer; 
			i2c_write_16(MA12070_REG_POWER_MODE_CONTROL,amp.power_mode); 
			return 0; 
		
		case MA12070_POWER_MODE_3: 	
	 		Buffer = set_nth_bit_uint8(Buffer,MA12070_POWER_MODE_LSB); 
	 		Buffer = set_nth_bit_uint8(Buffer,MA12070_POWER_MODE_MSB); 
			amp.power_mode = Buffer; 
			i2c_write_16(MA12070_REG_POWER_MODE_CONTROL,amp.power_mode); 
			return 0; 
		
		case MA12070_POWER_MODE_MAN:
	 		Buffer = set_nth_bit_uint8(Buffer,MA12070_POWER_MODE_LSB); 
	 		Buffer = unset_nth_bit_uint8(Buffer,MA12070_POWER_MODE_MSB); 
			amp.power_mode = Buffer; 
			i2c_write_16(MA12070_REG_POWER_MODE_CONTROL,amp.power_mode); 
			return 0; 
		
		case MA12070_POWER_MODE_DEFF:	
			amp.power_mode = MA12070_DEF_POWER_MODE_CONTROL; 
			i2c_write_16(MA12070_REG_POWER_MODE_CONTROL,amp.power_mode); 
			return 0; 
		
		default: 
				return 1; 
	}		
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
			DbFraction = (char) get_n_bits_lsb_int16(volume,2); 
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
			
			
			i2c_write_16(MA12070_REG_VOL_DB_MASTER, DbNumber); 
			i2c_write_16(MA12070_REG_VOL_LSB_MASTER, DbFraction); 
			
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
			DbFraction = (char) get_n_bits_lsb_int16(volume,2); 
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
						
			i2c_write_16(MA12070_REG_VOL_DB_MASTER, DbNumber); 
			i2c_write_16(MA12070_REG_VOL_LSB_MASTER, DbFraction); 
			
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

