#include"../../main.h"
#include"../../lowlayer/i2c/ll_i2c.h"
#include"../../../c/algorithms/bitgestion.h"
#include"ma120x0.h"


#define REGAMOUNT 37
#define READWRITE 27
#define NONEXISTENT 99

ll_i2c ma120x0(MA12070_ADDR, 1, I2C_MODE_MASTER,I2C_ADDRESS_7B);

int curretnVolume = 0; 
uint8_t bitNo = 0 ; 
uint8_t bitStart = 0; 
uint8_t bitStop = 0; 
uint8_t valToset = 0; 

S_MA12070 amp				= {0}; 
uint8_t regBuffer[4]		= {0};
uint8_t dataBuffer[4]		= {0};

uint8_t dataTable[REGAMOUNT] = {0};

uint8_t regTable[REGAMOUNT] = 
{	ma_manualpm__a ,	// index 0 
	ma_mthr_1to2__a ,	//index 1
	ma_mthr_2to1__a ,	// index 2
	ma_mthr_2to3__index ,
	0x0A ,
	0x1D ,
	0x1E ,
	0x20 ,
	0x25 ,
	0x26 ,
	0x27 ,
	0x2D ,
	0x35 ,
	0x36 ,
	0x40 ,
	0x41 ,
	0x42 ,
	0x43 ,
	0x44 ,
	0x45 ,
	0x46 ,
	0x47 ,
	0x48 ,
	0x49 ,
	0x4A ,
	0x4B ,
	0x7E , 
	0x60 ,
	0x61 ,
	0x62 ,
	0x64 ,
	0x65 ,
	0x66 ,
	0x6D ,
	0x75 ,
	0x7C };

uint8_t defValTable[READWRITE] =
{	0x3D,
	0x3C,
	0x32,
	0x5A,
	0x50,
	0xC0,
	0x00,
	0x2F,
	0x1F,
	0x10,
	0x05,
	0x08,
	0x30,
	0x01,
	0x01,
	0x18,
	0x00,
	0x18,
	0x18,
	0x18,
	0x18,
	0x00,
	0x18,
	0x18,
	0x18,
	0x18,
	0X00};




uint8_t ma120x0_configure(uint8_t Default)
{
		//Set the device back to default setings
		ma120x0_i2c_fetch(); 

		ma120x0_clearErrHandler();

		ma120x0_setPowerMode( MA12070_POWER_MODE_DEFF); 	 						// Power mode is set to default 
		ma120x0_setTreshold(MA12070_REG_MTHR_1TO2, MA12070_DEF_MTHR_1TO2); 	// Default treshold
		ma120x0_setTreshold(MA12070_REG_MTHR_2TO1, MA12070_DEF_MTHR_2TO1); 	// Default treshold
		ma120x0_setTreshold(MA12070_REG_MTHR_2TO3, MA12070_DEF_MTHR_2TO3); 	// Default treshold
		ma120x0_setTreshold(MA12070_REG_MTHR_3TO2, MA12070_DEF_MTHR_3TO2); 	// Default treshold

		ma120x0_setClippingAndOcp(MA12070_CLIPPING_EN,1); 							// soft Clipping ins enabled
		ma120x0_setClippingAndOcp(MA12070_CLIPPING_LATCH,0); 						// Cilipping latch disabled
		ma120x0_setPowerModeProfileSetings(MA12070_POWER_PROFILE_2);			// Profile 2 the default one 
		ma120x0_setAudioInMode(MA12070_AUDIO_IN_MODE_0); 							// Audio in as default +20dB
		ma120x0_setDcProtection(1); 														// DC Protection Enabled
		ma120x0_setAudioInOverwrite(0);													// Audio In overwrite Disabled (must be enabeled to led AudioInMode to take effect)
	 	ma120x0_setI2sFormat(MA12070_I2S_STANDART);									// Standart I2S Configuration
		ma120x0_setI2sRightFirst(0); 														// Set to Left First
		ma120x0_setI2sNoOfFrameBits(64);													// Word data lenght set to 32
		ma120x0_setI2sBitOrder(0); 														//Set to most significant Bit

 		ma120x0_setProcMute(0); 															// disabeled
		ma120x0_setI2sWsPolarity(0); 														//Set to low
		ma120x0_setI2sSckPolarity(1); 													// Set to Falling edge 
		ma120x0_setProcReleaseLvl(1); 													// Set to slow 
	 	ma120x0_setProcAttackLvl(1); 														// Set to slow
 		ma120x0_setProcEn(1); 																// disabled
 		ma12060_setProcLimiterEn(1); 														// disabeled
		ma120x0_setVolumeCh0(0x18,0x0);
		ma120x0_setVolumeCh1(0x18,0x0);
		ma120x0_setVolumeCh2(0x18,0x0);
		ma120x0_setVolumeCh3(0x18,0x0);
		ma120x0_setVolumeMaster(0x40,0x0);
		//ma120x0_setVolume(-15);															// Set Volume to 0 dB 
	throwError(__LINE__); 
}

uint8_t ma120x0_i2c_update()
{
	
}

uint8_t ma120x0_i2c_feltch()
{
	ma120x0.i2c_receive(regTable,dataTable,REGAMOUNT,REGAMOUNT);
}


void throwError(uint16_t error)
{
	printf ("\n\rma120x0.c Has generated an Error on line >>%d<<\n\r", error); 
}

uint8_t ma120x0_setPowerMode(uint8_t mode)
{
	currentIndex = returnTableIndex(ma_manualpm__a);
	bitStart = 4; 
	bitStop = 5; 
  		
	switch(mode)
		case MA12070_POWER_MODE_MAN
			bitNo = ma_manualpm__shift;
			set_nth_bit_uint8(dataTable[currentIndex], bitNo); 		
			break;
		case MA12070_POWER_MODE_AUTO
			bitNo = ma_manualpm__shift;
			unset_nth_bit_uint8(dataTable[currentIndex], bitNo); 		
			break;
		case MA12070_POWER_MODE_1:
			valToset = 1;
			set_bits_range_uint16(dataTable[currentIndex], bitStart, bitStop, valToset); 			
			break; 
		
		case MA12070_POWER_MODE_2: 	
			valToset = 2;
			set_bits_range_uint16(dataTable[currentIndex], bitStart, bitStop, valToset); 			
			break; 
		
		case MA12070_POWER_MODE_3: 	
			valToset = 3;
			set_bits_range_uint16(dataTable[currentIndex], bitStart, bitStop, valToset); 			
			break;  
		
		case MA12070_POWER_MODE_DEFF:	
			dataTable[currentIndex] = defValTable[currentIndex]; 
			break; 
		
		default: 
				throwError(__LINE__); 
	}
	throwError(__LINE__);  	
}

uint8_t ma120x0_setTreshold(uint8_t transition, uint8_t value)
{
	if(value <= 0 && value <= 255)
	{
		currentIndex = returnTableIndex(ma_);
		switch(transition)
		{
			case MA12070_REG_MTHR_1TO2 :
				i2c_write_16(MA12070_REG_MTHR_1TO2, value); 
				break;
			
			case MA12070_REG_MTHR_2TO1 : 
				i2c_write_16(MA12070_REG_MTHR_2TO1, value); 
				break;  
			
			case MA12070_REG_MTHR_2TO3 : 
				i2c_write_16(MA12070_REG_MTHR_2TO3, value); 
				break; 
			
			case MA12070_REG_MTHR_3TO2 : 
				i2c_write_16(MA12070_REG_MTHR_3TO2, value); 
				break; 
			
			default : 
				throwError(__LINE__); 
		}
		throwError(__LINE__); 
	}
	else 
	{
		throwError(__LINE__);
	}
	throwError(__LINE__); 
}

uint8_t ma120x0_setClippingAndOcp(uint8_t clipOrOcp, uint8_t enable)
{
	if( clipOrOcp >= 0 && clipOrOcp <= 1 && enable >= 0 && enable <= 1)
	{
		currentIndex = ma120x0_returnTableIndex(MA12070_REG_SOFT_CILLIPNG); 
		
		if (clipOrOcp)
		{
			if (enable)
			{
				currentIndex = set_nth_bit_uint8(currentIndex, 7);
			}
			else 
			{
				currentIndex = unset_nth_bit_uint8(currentIndex, 7);
			}
		}
		else
		{
			if (enable)
			{
				currentIndex = set_nth_bit_uint8(currentIndex, 1);
			}
			else
			{
				currentIndex = unset_nth_bit_uint8(currentIndex, 1);
			}
		}

		i2c_write_16(MA12070_REG_SOFT_CILLIPNG, currentIndex);
		
		throwError(__LINE__); 
	}

	throwError(__LINE__); 
}

uint8_t ma120x0_setPowerModeProfileSetings(uint8_t setings)
{
		switch(setings)
		{
			case MA12070_POWER_PROFILE_0 :
				currentIndex = 0x00;
				break; 
			case MA12070_POWER_PROFILE_1 :
				currentIndex = 0x01;
				break; 
			case MA12070_POWER_PROFILE_2 :
				currentIndex = 0x02;
				break; 
			case MA12070_POWER_PROFILE_3 :
				currentIndex = 0x03;
				break; 
			case MA12070_POWER_PROFILE_4 :
				currentIndex = 0x04;
				break; 
			default:
				throwError(__LINE__); 
		}
		i2c_write_16(MA12070_REG_PM_PROFILE_MODE, currentIndex);
		throwError(__LINE__);
}

uint8_t ma120x0_setPowerModeProfileConfig(uint8_t scheme, uint8_t powerMode)
{
	if(scheme <= 3 && scheme >= 0 && powerMode <= 3 && powerMode >= 1)
	{
		currentIndex = ma120x0_returnTableIndex(MA12070_REG_PM_PROFILE_CONF);
		switch(powerMode)
		{
			case MA12070_POWER_MODE_1 : 
				switch(scheme)
				{
					case MA12070_POWER_SCHEME_CUSTOM : 
						currentIndex = set_nth_bit_uint8(currentIndex,5);	//1
						currentIndex = unset_nth_bit_uint8(currentIndex,4); //0
						break; 
						 
					case MA12070_POWER_SCHEME_A : 
						currentIndex = unset_nth_bit_uint8(currentIndex,5); //0
						currentIndex = unset_nth_bit_uint8(currentIndex,4); //0
						break; 
						
					case MA12070_POWER_SCHEME_B : 
						currentIndex = unset_nth_bit_uint8(currentIndex,5); //0
						currentIndex = set_nth_bit_uint8(currentIndex,4);	//1
						break; 
						
					case MA12070_POWER_SCHEME_C : 
						currentIndex = set_nth_bit_uint8(currentIndex,5);	//1
						currentIndex = unset_nth_bit_uint8(currentIndex,4); //0
						break; 
						
					case MA12070_POWER_SCHEME_D :
						currentIndex = set_nth_bit_uint8(currentIndex,5); 	//1 
						currentIndex = set_nth_bit_uint8(currentIndex,4); 	//1
						break; 
						
					default : 
						throwError(__LINE__); 
				}
				i2c_write_16(MA12070_REG_PM_PROFILE_CONF,currentIndex); 
				throwError(__LINE__); 

			case MA12070_POWER_MODE_2 : 
				switch(scheme)
				{
					case MA12070_POWER_SCHEME_CUSTOM : 
						currentIndex = set_nth_bit_uint8(currentIndex,3);	//1
						currentIndex = set_nth_bit_uint8(currentIndex,2);	//1
						break; 

					case MA12070_POWER_SCHEME_A :
						currentIndex = unset_nth_bit_uint8(currentIndex,3);	//0
						currentIndex = unset_nth_bit_uint8(currentIndex,2); //0
						break; 
					
					case MA12070_POWER_SCHEME_B : 
						currentIndex = unset_nth_bit_uint8(currentIndex,3);	//0
						currentIndex = set_nth_bit_uint8(currentIndex,2); 	//1 
						break; 
						
					case MA12070_POWER_SCHEME_C : 
						currentIndex = set_nth_bit_uint8(currentIndex,3);	//1 
						currentIndex = unset_nth_bit_uint8(currentIndex,2); //0
						break; 
						
					case MA12070_POWER_SCHEME_D :
						currentIndex = set_nth_bit_uint8(currentIndex,3); 	//1
						currentIndex = set_nth_bit_uint8(currentIndex,2); 	//1
						break; 
						
					default : 
						throwError(__LINE__); 
				}
				i2c_write_16(MA12070_REG_PM_PROFILE_CONF,currentIndex); 
				throwError(__LINE__); 
			
			case MA12070_POWER_MODE_3 : 
				switch(scheme)
				{
					case MA12070_POWER_SCHEME_CUSTOM : 
						currentIndex = set_nth_bit_uint8(currentIndex,1);	//1
						currentIndex = set_nth_bit_uint8(currentIndex,0);	//1
						break; 

					case MA12070_POWER_SCHEME_A :
						currentIndex = unset_nth_bit_uint8(currentIndex,1);	//0
						currentIndex = unset_nth_bit_uint8(currentIndex,0);	//0
						break; 

					case MA12070_POWER_SCHEME_B : 
						currentIndex = unset_nth_bit_uint8(currentIndex,1);	//0
						currentIndex = set_nth_bit_uint8(currentIndex,0);		//1
						break; 
						
					case MA12070_POWER_SCHEME_C : 
						currentIndex = set_nth_bit_uint8(currentIndex,1);		//1
						currentIndex = unset_nth_bit_uint8(currentIndex,0); 	//0
						break; 
					
					case MA12070_POWER_SCHEME_D :
						currentIndex = set_nth_bit_uint8(currentIndex,1);	//1
						currentIndex = set_nth_bit_uint8(currentIndex,0); 	//1
						break; 

					default : 
						throwError(__LINE__); 
				}				
				i2c_write_16(MA12070_REG_PM_PROFILE_CONF,currentIndex); 
				throwError(__LINE__);

			default :
				throwError(__LINE__); 
		}
	}
	else 
	{
		throwError(__LINE__); 
	}
	throwError(__LINE__);
}

uint8_t ma120x0_clearOcpLatch()
{
	currentIndex = ma120x0_returnTableIndex(MA12070_REG_OVER_CURR_PROT);
	currentIndex = unset_nth_bit_uint8(currentIndex,7);
	i2c_write_16(MA12070_REG_OVER_CURR_PROT, currentIndex); 
	throwError(__LINE__);
}

uint8_t ma120x0_setAudioInMode(uint8_t mode)
{
	if(mode <= 2 && mode >= 0 )
	{
		currentIndex = ma120x0_returnTableIndex(MA12070_REG_AUDIO_IN_MODE); 
		switch(mode)
		{
			case MA12070_AUDIO_IN_MODE_0 :
				currentIndex = unset_nth_bit_uint8(currentIndex,6); 
				currentIndex = unset_nth_bit_uint8(currentIndex,5); 
				break; 
			case MA12070_AUDIO_IN_MODE_1 : 
				currentIndex = unset_nth_bit_uint8(currentIndex,6); 
				currentIndex = set_nth_bit_uint8(currentIndex,5); 
				break; 
			default : 
				throwError(__LINE__); 
		}
		i2c_write_16(MA12070_REG_AUDIO_IN_MODE, currentIndex); 
		throwError(__LINE__); 
	}
	else 
	{
		throwError(__LINE__); 
	}
	throwError(__LINE__);
}

uint8_t ma120x0_setDcProtection(uint8_t enable)
{
	currentIndex = ma120x0_returnTableIndex(MA12070_REG_DC_PROTECTION);
	
	if(enable)
	{
		currentIndex = set_nth_bit_uint8(currentIndex,2);
	}
	else 
	{
		currentIndex = unset_nth_bit_uint8(currentIndex,2);
	}

	i2c_write_16(MA12070_REG_DC_PROTECTION, currentIndex); 
	throwError(__LINE__);  
}


uint8_t ma120x0_setAudioInOverwrite(uint8_t enable)
{
	currentIndex = ma120x0_returnTableIndex(MA12070_REG_AUDI_IN_OVERWRITE);
	
	if(enable)
	{
		currentIndex = set_nth_bit_uint8(currentIndex,5);
	}
	else 
	{
		currentIndex = unset_nth_bit_uint8(currentIndex,5);
	}

	i2c_write_16(MA12070_REG_AUDI_IN_OVERWRITE,currentIndex); 
	throwError(__LINE__);  
}

uint8_t ma120x0_clearErrHandler()
{
	currentIndex = ma120x0_returnTableIndex(MA12070_REG_ERROR_HANDLER);
	
	currentIndex = unset_nth_bit_uint8(currentIndex,2);
	i2c_write_16(MA12070_REG_ERROR_HANDLER,currentIndex); 
	currentIndex = set_nth_bit_uint8(currentIndex,2);
	i2c_write_16(MA12070_REG_ERROR_HANDLER,currentIndex); 
	currentIndex = unset_nth_bit_uint8(currentIndex,2);
	i2c_write_16(MA12070_REG_ERROR_HANDLER,currentIndex); 
	
	throwError(__LINE__); 
}

uint8_t ma120x0_setI2sFormat(uint8_t format)
{
	currentIndex = ma120x0_returnTableIndex(MA12070_REG_PCM_WORD_FORMAT); 
	switch(format)
	{	
		case MA12070_I2S_STANDART :
			currentIndex = 0x0;
			break; 
		case MA12070_I2S_LEFT :
			currentIndex = 0x01; 
			break; 
		case MA12070_I2S_RIGHT_16b :
			currentIndex = 0x04; 
			break; 
		case MA12070_I2S_RIGHT_18b :
			currentIndex = 0x06; 
			break; 
		case MA12070_I2S_RIGHT_20b :
			currentIndex = 0x0; 
			break; 
		case MA12070_I2S_RIGHT_24b :
			currentIndex = 0x7; 
			break; 
		default : 
			throwError(__LINE__); 
	}	
	i2c_write_16(MA12070_REG_PCM_WORD_FORMAT,currentIndex); 
	throwError(__LINE__); 	
}


uint8_t ma120x0_setI2sRightFirst(uint8_t leftOrRight)
{
	currentIndex = ma120x0_returnTableIndex(MA12070_REG_I2S_CONFIG); 
	if (leftOrRight == 0)
	{
		currentIndex = unset_nth_bit_uint8(currentIndex,5);
	}
	else if (leftOrRight == 1)
	{
	printf("Hre");
		currentIndex = set_nth_bit_uint8(currentIndex,5);
	}
	else 
	{
		throwError(__LINE__);
	}
	i2c_write_16(MA12070_REG_I2S_CONFIG,currentIndex); 
	throwError(__LINE__);
}


uint8_t ma120x0_setI2sNoOfFrameBits(uint8_t bits)
{
	currentIndex = ma120x0_returnTableIndex(MA12070_REG_I2S_CONFIG); 
	switch (bits)
	{
		case 64 :
			currentIndex = unset_nth_bit_uint8(currentIndex,4);
			currentIndex = unset_nth_bit_uint8(currentIndex,3);
			break;

		case 48 : 
			currentIndex = unset_nth_bit_uint8(currentIndex,4);
			currentIndex = set_nth_bit_uint8(currentIndex,3);
			break; 

		case 32 : 
			currentIndex = set_nth_bit_uint8(currentIndex,4);
			currentIndex = unset_nth_bit_uint8(currentIndex,3);
			break;  

		default : 
			  throwError(__LINE__); 	
	
	}
	i2c_write_16(MA12070_REG_I2S_CONFIG,currentIndex); 
	throwError(__LINE__);
}


uint8_t ma120x0_setI2sBitOrder(uint8_t mostOrLeast)
{
	currentIndex = ma120x0_returnTableIndex(MA12070_REG_I2S_CONFIG); 
	if (mostOrLeast == 0)
	{
		currentIndex = unset_nth_bit_uint8(currentIndex,2);
	}
	else if (mostOrLeast == 1)
	{
		currentIndex = set_nth_bit_uint8(currentIndex,2);
	}
	else 
	{
		throwError(__LINE__);
	}
	i2c_write_16(MA12070_REG_I2S_CONFIG,currentIndex); 
	throwError(__LINE__);
}


uint8_t ma120x0_setI2sWsPolarity(uint8_t highOrLow)
{
	currentIndex = ma120x0_returnTableIndex(MA12070_REG_I2S_CONFIG); 
	if (highOrLow == 0)
	{
		currentIndex = unset_nth_bit_uint8(currentIndex,1);
	}
	else if (highOrLow == 1)
	{
		currentIndex = set_nth_bit_uint8(currentIndex,1);
	}
	else 
	{
		throwError(__LINE__);
	}
	i2c_write_16(MA12070_REG_I2S_CONFIG,currentIndex); 
	throwError(__LINE__);
}

uint8_t ma120x0_setI2sSckPolarity(uint8_t risingOrFalling)
{
	currentIndex = ma120x0_returnTableIndex(MA12070_REG_I2S_CONFIG); 
	if (risingOrFalling == 0)
	{
		currentIndex = unset_nth_bit_uint8(currentIndex,0);
	}
	else if (risingOrFalling == 1)
	{
		currentIndex = set_nth_bit_uint8(currentIndex,0);
	}
	else 
	{
		throwError(__LINE__);
	}
	i2c_write_16(MA12070_REG_I2S_CONFIG,currentIndex); 
	throwError(__LINE__);
}



uint8_t ma120x0_setProcReleaseLvl(uint8_t lvl)
{
	currentIndex = ma120x0_returnTableIndex(MA12070_REG_PROCESSOR_SET); 
	switch (lvl)
	{
		case 1 :
			currentIndex = unset_nth_bit_uint8(currentIndex,7);
			currentIndex = unset_nth_bit_uint8(currentIndex,6);
			break;

		case 2 : 
			currentIndex = unset_nth_bit_uint8(currentIndex,7);
			currentIndex = set_nth_bit_uint8(currentIndex,6);
			break; 

		case 3 : 
			currentIndex = set_nth_bit_uint8(currentIndex,7);
			currentIndex = unset_nth_bit_uint8(currentIndex,6);
			break;  

		default : 
			  throwError(__LINE__); 	
	
	}
	i2c_write_16(MA12070_REG_PROCESSOR_SET,currentIndex); 
	throwError(__LINE__);
}

uint8_t ma120x0_setProcAttackLvl(uint8_t lvl)
{
	currentIndex = ma120x0_returnTableIndex(MA12070_REG_PROCESSOR_SET); 
	switch (lvl)
	{
		case 1 :
			currentIndex = unset_nth_bit_uint8(currentIndex,5);
			currentIndex = unset_nth_bit_uint8(currentIndex,4);
			break;

		case 2 : 
			currentIndex = unset_nth_bit_uint8(currentIndex,5);
			currentIndex = set_nth_bit_uint8(currentIndex,4);
			break; 

		case 3 : 
			currentIndex = set_nth_bit_uint8(currentIndex,5);
			currentIndex = unset_nth_bit_uint8(currentIndex,4);
			break;  

		default : 
			  throwError(__LINE__); 	
	
	}
	i2c_write_16(MA12070_REG_PROCESSOR_SET,currentIndex); 
	throwError(__LINE__);
}


uint8_t ma120x0_setProcEn(uint8_t enable)
{
	currentIndex = ma120x0_returnTableIndex(MA12070_REG_PROCESSOR_SET); 
	if (enable == 0)
	{
		currentIndex = unset_nth_bit_uint8(currentIndex,3);
	}
	else if (enable == 1)
	{
		currentIndex = set_nth_bit_uint8(currentIndex,3);
	}
	else 
	{
		throwError(__LINE__);
	}
	i2c_write_16(MA12070_REG_PROCESSOR_SET,currentIndex); 
	throwError(__LINE__);
}


uint8_t ma120x0_setProcMute(uint8_t mute)
{
	currentIndex = ma120x0_returnTableIndex(MA12070_REG_LIMITER_SET); 
	if (mute == 0)
	{
		currentIndex = unset_nth_bit_uint8(currentIndex,7);
	}
	else if (mute == 1)
	{
		currentIndex = set_nth_bit_uint8(currentIndex,7);
	}
	else 
	{
		throwError(__LINE__);
	}
	i2c_write_16(MA12070_REG_LIMITER_SET,currentIndex); 
	throwError(__LINE__);
}


uint8_t ma12060_setProcLimiterEn(uint8_t enable)
{
	currentIndex = ma120x0_returnTableIndex(MA12070_REG_LIMITER_SET); 
	if (enable == 0)
	{
		currentIndex = unset_nth_bit_uint8(currentIndex,6);
	}
	else if (enable == 1)
	{
		currentIndex = set_nth_bit_uint8(currentIndex,6);
	}
	else 
	{
		throwError(__LINE__);
	}
	i2c_write_16(MA12070_REG_LIMITER_SET,currentIndex); 
	throwError(__LINE__);
}





int16_t ma120x0_getVolume(void)
{
	uint8_t DbFractionTab[3] = {25,50,75}; 
 	int16_t volume = 0; 	

	amp.vol_db_master = ma120x0_returnTableIndex(MA12070_REG_VOL_DB_MASTER); 
	amp.vol_lsb_master = ma120x0_returnTableIndex(MA12070_REG_VOL_LSB_MASTER);
	
	volume += (24 - amp.vol_db_master) * 100 - DbFractionTab[amp.vol_lsb_master-1];    
			
	printf("\nVolume: %d\t\n", volume); 
	throwError(__LINE__); 
}

void ma120x0_printCurrentCconf(void)
{
	printf("\n\n\t CURRENT CONFIGURATION OF MA12070P \n\n");
	printf("power_mode = %d\n", amp.power_mode);
	printf("power_mode namual = %d\n", amp.power_mode_manual);
	printf("treshold_1to2 = %d\n", amp.treshold_1to2);
	printf("treshold_2to1 = %d\n", amp.treshold_2to1);
	printf("treshold_2to3 = %d\n", amp.treshold_2to3);
	printf("treshold_3to2 = %d\n", amp.treshold_3to2);
	printf("ifClampEn = %d\n", amp.ifClampEn);
	printf("ocpLatchEn = %d\n", amp.ocpLatchEn);
	printf("pmProfile = %d\n", amp.pmProfile);
	printf("pm3_man = %d\n", amp.pm3_man);
	printf("pm2_man = %d\n", amp.pm2_man);
	printf("pm1_man = %d\n", amp.pm1_man);
	printf("ocp_latch_clear = %d\n", amp.ocp_latch_clear);
	printf("audio_in_mode = %d\n", amp.audio_in_mode);
	printf("eh_dc_shndn = %d\n", amp.eh_dc_shndn);
	printf("audio_in_mode_ext = %d\n", amp.audio_in_mode_ext);
	printf("eh_clear = %d\n", amp.eh_clear);
	printf("i2s_format = %d\n", amp.i2s_format);
	printf("i2s_right_first = %d\n", amp.i2s_right_first);
	printf("i2s_frame_size = %d\n", amp.i2s_frame_size);
	printf("i2s_order = %d\n", amp.i2s_order);
	printf("i2s_ws_pol = %d\n", amp.i2s_ws_pol);
	printf("i2s_sck_pol = %d\n", amp.i2s_sck_pol);
	printf("audio_proc_release = %d\n", amp.audio_proc_release);
	printf("audio_proc_attack = %d\n", amp.audio_proc_attack);
	printf("audio_proc_enable = %d\n", amp.audio_proc_enable);
	printf("audio_proc_mute = %d\n", amp.audio_proc_mute);
	printf("audio_proc_limitter = %d\n", amp.audio_proc_limitter);
	printf("vol_db_master = %d\n", amp.vol_db_master);
	printf("vol_lsb_master = %d\n", amp.vol_lsb_master);
	printf("vol_db[0] = %d\n", amp.vol_db[0]);
	printf("vol_db[1] = %d\n", amp.vol_db[1]);
	printf("vol_db[2] = %d\n", amp.vol_db[2]);
	printf("vol_db[3] = %d\n", amp.vol_db[3]);
	printf("vol_lsb[0] = %d\n", amp.vol_lsb[0]);
	printf("vol_lsb[1] = %d\n", amp.vol_lsb[1]);
	printf("vol_lsb[2] = %d\n", amp.vol_lsb[2]);
	printf("vol_lsb[3] = %d\n", amp.vol_lsb[3]);
	printf("thr_db[0] = %d\n", amp.thr_db[0]);
	printf("thr_db[1] = %d\n", amp.thr_db[1]);
	printf("thr_db[2] = %d\n", amp.thr_db[2]);
	printf("thr_db[3] = %d\n", amp.thr_db[3]);
	printf("thr_lsb[0] = %d\n", amp.thr_lsb[0]);
	printf("thr_lsb[1] = %d\n", amp.thr_lsb[1]);
	printf("thr_lsb[2] = %d\n", amp.thr_lsb[2]);
	printf("thr_lsb[3]  = %d\n", amp.thr_lsb[3] );
	printf("audio_porc_limiter_mon = %d\n", amp.audio_porc_limiter_mon);
	printf("audio_proc_clip_mon = %d\n", amp.audio_proc_clip_mon);
	printf("dcu_frequency_mon[0] = %d\n", amp.dcu_frequency_mon[0]);
	printf("dcu_power_mode_mon[0] = %d\n", amp.dcu_power_mode_mon[0]);
	printf("dcu_frequency_mon[1] = %d\n", amp.dcu_frequency_mon[1]);
	printf("dcu_power_mode_mon[1] = %d\n", amp.dcu_power_mode_mon[1]);
	printf("dcu_mute_mon[0] = %d\n", amp.dcu_mute_mon[0]);
	printf("dcu_vdd_ok_mon[0] = %d\n", amp.dcu_vdd_ok_mon[0]);
	printf("dcu_pvdd_ok_mon[0] = %d\n", amp.dcu_pvdd_ok_mon[0]);
	printf("dcu_vcfly2_ok_mon[0] = %d\n", amp.dcu_vcfly2_ok_mon[0]);
	printf("dcu_vcfly1_ok_mon[0] = %d\n", amp.dcu_vcfly1_ok_mon[0]);
	printf("ocp_mon[0] = %d\n", amp.ocp_mon[0]);
	printf("dcu_mute_mon[1] = %d\n", amp.dcu_mute_mon[1]);
	printf("dcu_vdd_ok_mon[1] = %d\n", amp.dcu_vdd_ok_mon[1]);
	printf("dcu_pvdd_ok_mon[1] = %d\n", amp.dcu_pvdd_ok_mon[1]);
	printf("dcu_vcfly2_ok_mon[1] = %d\n", amp.dcu_vcfly2_ok_mon[1]);
	printf("dcu_vcfly1_ok_mon[1] = %d\n", amp.dcu_vcfly1_ok_mon[1]);
	printf("ocp_mon[1] = %d\n", amp.ocp_mon[1]);
	printf("dcu_modulation_mon[0] = %d\n", amp.dcu_modulation_mon[0]);
	printf("dcu_modulation_mon[1] = %d\n", amp.dcu_modulation_mon[1]);
	printf("error_acc = %d\n", amp.error_acc);
	printf("msel_mon = %d\n", amp.msel_mon);
	printf("error = %d\n", amp.error);
} 



uint8_t ma120x0_setVolumeCh0(uint8_t db, uint8_t lsb)
{
	if(db >= 0 && db <=255 && lsb>= 0 && lsb <= 3)
	{
		i2c_write_16(MA12070_REG_VOL_DB_CH0,db);

		currentIndex = ma120x0_returnTableIndex(MA12070_REG_VOL_LSB_CHX);
		
		switch(lsb)
		{
			case 0: 
				currentIndex = unset_nth_bit_uint8(currentIndex,1);
				currentIndex = unset_nth_bit_uint8(currentIndex,0);
				break; 
			case 1: 
				currentIndex = set_nth_bit_uint8(currentIndex,1);
				currentIndex = unset_nth_bit_uint8(currentIndex,0);
				break; 
			case 3: 
				currentIndex = set_nth_bit_uint8(currentIndex,1);
				currentIndex = set_nth_bit_uint8(currentIndex,0);
				break; 
			default: 
				throwError(__LINE__);
		}
		i2c_write_16(MA12070_REG_VOL_LSB_CHX,currentIndex);
		throwError(__LINE__); 
	}
	else 
	{
		throwError(__LINE__); 
	}
	throwError(__LINE__);
}

uint8_t ma120x0_setVolumeCh1(uint8_t db, uint8_t lsb)
{
	if(db >= 0 && db <=255 && lsb>= 0 && lsb <= 3)
	{
		i2c_write_16(MA12070_REG_VOL_DB_CH1,db);

		currentIndex = ma120x0_returnTableIndex(MA12070_REG_VOL_LSB_CHX);
		
		switch(lsb)
		{
			case 0: 
				currentIndex = unset_nth_bit_uint8(currentIndex,3);
				currentIndex = unset_nth_bit_uint8(currentIndex,2);
				break; 
			case 1: 
				currentIndex = set_nth_bit_uint8(currentIndex,3);
				currentIndex = unset_nth_bit_uint8(currentIndex,2);
				break; 
			case 3: 
				currentIndex = set_nth_bit_uint8(currentIndex,3);
				currentIndex = set_nth_bit_uint8(currentIndex,2);
				break; 
			default: 
				throwError(__LINE__);
		}
		i2c_write_16(MA12070_REG_VOL_LSB_CHX,currentIndex);
		throwError(__LINE__); 
	}
	else 
	{
		throwError(__LINE__); 
	}
	throwError(__LINE__);
}



uint8_t ma120x0_setVolumeCh2(uint8_t db, uint8_t lsb)
{
	if(db >= 0 && db <=255 && lsb>= 0 && lsb <= 3)
	{
		i2c_write_16(MA12070_REG_VOL_DB_CH2,db);

		currentIndex = ma120x0_returnTableIndex(MA12070_REG_VOL_LSB_CHX);
		
		switch(lsb)
		{
			case 0: 
				currentIndex = unset_nth_bit_uint8(currentIndex,5);
				currentIndex = unset_nth_bit_uint8(currentIndex,4);
				break; 
			case 1: 
				currentIndex = set_nth_bit_uint8(currentIndex,5);
				currentIndex = unset_nth_bit_uint8(currentIndex,4);
				break; 
			case 3: 
				currentIndex = set_nth_bit_uint8(currentIndex,5);
				currentIndex = set_nth_bit_uint8(currentIndex,4);
				break; 
			default: 
				throwError(__LINE__);
		}
		i2c_write_16(MA12070_REG_VOL_LSB_CHX,currentIndex);
		throwError(__LINE__); 
	}
	else 
	{
		throwError(__LINE__); 
	}
	throwError(__LINE__);
}



uint8_t ma120x0_setVolumeCh3(uint8_t db, uint8_t lsb)
{
	if(db >= 0 && db <=255 && lsb>= 0 && lsb <= 3)
	{
		printf("You are in"); 
		i2c_write_16(MA12070_REG_VOL_DB_CH3,db);

		currentIndex = ma120x0_returnTableIndex(MA12070_REG_VOL_LSB_CHX);
		
		switch(lsb)
		{
			case 0: 
				currentIndex = unset_nth_bit_uint8(currentIndex,7);
				currentIndex = unset_nth_bit_uint8(currentIndex,6);
				break; 
			case 1: 
				currentIndex = set_nth_bit_uint8(currentIndex,7);
				currentIndex = unset_nth_bit_uint8(currentIndex,6);
				break; 
			case 3: 
				currentIndex = set_nth_bit_uint8(currentIndex,7);
				currentIndex = set_nth_bit_uint8(currentIndex,6);
				break; 
			default: 
				throwError(__LINE__);
		}
		i2c_write_16(MA12070_REG_VOL_LSB_CHX,currentIndex);
		throwError(__LINE__); 
	}
	else 
	{
		throwError(__LINE__); 
	}
	throwError(__LINE__);
}


uint8_t ma120x0_setVolumeMaster(uint8_t db, uint8_t lsb)
{
	if(db >= 0 && db <=255 && lsb>= 0 && lsb <= 3)
	{
		i2c_write_16(MA12070_REG_VOL_DB_MASTER,db);

		currentIndex = ma120x0_returnTableIndex(MA12070_REG_VOL_LSB_MASTER);
		
		switch(lsb)
		{
			case 0: 
				currentIndex = unset_nth_bit_uint8(currentIndex,1);
				currentIndex = unset_nth_bit_uint8(currentIndex,0);
				break; 
			case 1: 
				currentIndex = set_nth_bit_uint8(currentIndex,1);
				currentIndex = unset_nth_bit_uint8(currentIndex,0);
				break; 
			case 3: 
				currentIndex = set_nth_bit_uint8(currentIndex,1);
				currentIndex = set_nth_bit_uint8(currentIndex,0);
				break; 
			default: 
				throwError(__LINE__);
		}
		i2c_write_16(MA12070_REG_VOL_LSB_MASTER,currentIndex);
		throwError(__LINE__); 
	}
	else 
	{
		throwError(__LINE__); 
	}
	throwError(__LINE__);
}



uint8_t ma120x0_setVolume(int16_t volume)
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
			} else { DbFraction = (DbFraction^3) + 1; DbBuff = (MA12070_VOL_MAX_DB) - DbBuff -1; } DbNumber = (char)DbBuff; printf("Bdnumber: %u\tfraction: %u \n",DbNumber, DbFraction); 
			
			
			i2c_write_16(MA12070_REG_VOL_DB_MASTER, DbNumber); 
			i2c_write_16(MA12070_REG_VOL_LSB_MASTER, DbFraction); 
			
			throwError(__LINE__); 
		}
		else 
		{
			
			throwError(__LINE__); 
		}
		throwError(__LINE__); 							
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
		   printf("Bdnumber: %u\tfraction: %u \n",DbNumber, DbFraction);
						
			i2c_write_16(MA12070_REG_VOL_DB_MASTER, DbNumber); 
			i2c_write_16(MA12070_REG_VOL_LSB_MASTER, DbFraction); 
			
			throwError(__LINE__); 
		}
		else
		{
			throwError(__LINE__); 
		}
	}
}


// This part of the code may later be neede but for now the ma120x0_getCurrentDevInfo functio does the trick for me.
/*
uint8_t ma120x0_monitorCh0FreqAndPwr()
{
	uint8_t frequency = 0;  
	uint8_t powerMode = 0; 
	currentIndex = ma120x0_returnTableIndex(MA12070_REG_MON_CH0_FREQ_POW); 
	frequency = get_n_bits_msb_uint8(currentIndex,4);
	frequency = frequency << 1; 
	powerMode = get_n_bits_lsb_uint8(currentIndex,2); 
	amp.
} 

uint8_t ma120x0_monitorCh0()
{
	currentIndex = ma120x0_returnTableIndex(MA12070_REG_MON_CH0_FREQ_POW);
}

uint8_t ma120x0_monitorCh0ModulationInd()
{

} */
