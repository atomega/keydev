
#include"../../lowlayer/i2c/ll_i2c.h"
#include"../../../c/algorithms/bitgestion.h"
#include"ma120x0.h"

ll_i2c ma(MA_ADDR, 1, I2C_MODE_MASTER,I2C_ADDRESS_7B);

int curretnVolume 		= 0; 
uint8_t bitNo 			= 0; 
uint8_t bitStart		= 0; 
uint8_t bitStop 		= 0; 
uint8_t valToset 		= 0; 
uint8_t i2cLenght 		= 0; 
uint8_t regBuffer[4]	= {0};
uint8_t dataBuffer[4]	= {0};

uint8_t dataTable[REGAMOUNT] = {0};


uint8_t regTable[REGAMOUNT] = 
{	
	MA_REG_PWR_MODE_CTRL,
	MA_REG_MTHR_1TO2,
	MA_REG_MTHR_2TO1,
	MA_REG_MTHR_2TO3,
	MA_REG_MTHR_3TO2,
	MA_REG_LATCH_CLAMP,
	MA_REG_PM_PROFILE_MODE,
	MA_REG_PM_PROFILE_CONF,
	MA_REG_OCP_LATCH_CLEAR,
	MA_REG_AUDIO_IN_MODE,
	MA_REG_DC_PROTECTION,
	MA_REG_AUDIO_IN_OVERWRITE,
	MA_REG_ERROR_HANDLER,
	MA_REG_PCM_PROC_SET,
	MA_REG_I2S_CONFIG,
	MA_REG_VOL_DB_MASTER,
	MA_REG_VOL_LSB_MASTER,
	MA_REG_VOL_DB_CH0,
	MA_REG_VOL_DB_CH1,
	MA_REG_VOL_DB_CH2,
	MA_REG_VOL_DB_CH3,
	MA_REG_VOL_LSB_CHX,
	MA_REG_THR_DB_CH0,
	MA_REG_THR_DB_CH1,
	MA_REG_THR_DB_CH2,
	MA_REG_THR_DB_CH3,
	MA_REG_THR_LSB_CHX,
	MA_REG_MON0_FREQ_PM,
	MA_REG_MON0,
	MA_REG_MON0_MODUL,
	MA_REG_MON1_FREQ_PM,
	MA_REG_MON1,
	MA_REG_MON_CH1_MODUL,
	MA_REG_ERRO_ACC,
	MA_REG_MON_MSEL,
	MA_REG_ERROR,
	MA_REG_MON_LIMIT_CLIP
};

uint8_t defValTable[READWRITE] =
{	
	MA_DEF_PWR_MODE_CTRL,
	MA_DEF_MTHR_1TO2,
	MA_DEF_MTHR_2TO1,
	MA_DEF_MTHR_2TO3,
	MA_DEF_MTHR_3TO2,
	MA_DEF_LATCH_CLAMP,
	MA_DEF_PM_PROFILE_MODE,
	MA_DEF_PM_PROFILE_CONF,
	MA_DEF_OCP_LATCH_CLEAR,
	MA_DEF_AUDIO_IN_MODE,
	MA_DEF_DC_PROTECTION,
	MA_DEF_AUDIO_IN_OVERWRITE,
	MA_DEF_ERROR_HANDLER,
	MA_DEF_PCM_PROC_SET,
	MA_DEF_I2S_CONFIG,
	MA_DEF_VOL_DB_MASTER,
	MA_DEF_VOL_LSB_MASTER,
	MA_DEF_VOL_DB_CH0,
	MA_DEF_VOL_DB_CH1,
	MA_DEF_VOL_DB_CH2,
	MA_DEF_VOL_DB_CH3,
	MA_DEF_VOL_LSB_CHX,
	MA_DEF_THR_DB_CH0,
	MA_DEF_THR_DB_CH1,
	MA_DEF_THR_DB_CH2,
	MA_DEF_THR_DB_CH3,
	MA_DEF_THR_LSB_CHX
};

uint8_t monitorinTable[READONLY]
{
	MA_DEF_MON0_FREQ_PM,
	MA_DEF_MON0,
	MA_DEF_MON0_MODUL,
	MA_DEF_MON1_FREQ_PM,
	MA_DEF_MON1,
	MA_DEF_MON_CH1_MODUL,
	MA_DEF_ERRO_ACC,
	MA_DEF_MON_MSEL,
	MA_DEF_ERROR,
	MA_DEF_MON_LIMIT_CLIP	
};

uint8_t ma_configure(uint8_t Default)
{
		//Set the device back to default setings
		ma_i2c_fetch(); 

		ma_clearErrHandler();

		ma_setPowerMode(MA_DEF_PWR_MODE_CTRL); 	 				// Power mode is set to default 
		ma_setTreshold(MA_REG_MTHR_1TO2, MA_DEF_MTHR_1TO2); 	// Default treshold
		ma_setTreshold(MA_REG_MTHR_2TO1, MA_DEF_MTHR_2TO1); 	// Default treshold
		ma_setTreshold(MA_REG_MTHR_2TO3, MA_DEF_MTHR_2TO3); 	// Default treshold
		ma_setTreshold(MA_REG_MTHR_3TO2, MA_DEF_MTHR_3TO2); 	// Default treshold

		ma_setClipping(1); 										// soft Clipping Enabled
		ma_setOcp(1); 											// Overcurrent protection Cilipping latch enabled
		ma_setPowerModeProfileSetings(MA_POWER_PROFILE_2);		// Profile 2 the default one 
		ma_setAudioInMode(MA_AUDIO_IN_MODE_0); 					// Audio in as default +20dB
		ma_setDcProtection(1); 									// DC Protection Enabled
		ma_setAudioInOverwrite(0);								// Audio In overwrite Disabled (must be enabeled to led AudioInMode to take effect)
	 	ma_setI2sFormat(MA_I2S_STANDART);						// Standart I2S Configuration
		ma_setI2sRightFirst(0); 								// Set to Left First
		ma_setI2sFrameSize(64);									// Word data lenght set to 64
		ma_setI2sBitOrder(0); 									// Set to most significant Bit

 		ma_setProcMute(0); 												
		ma_setI2sWsPolarity(I2S_WS_POL_LOW); 										
		ma_setI2sSckPolarity(I2S_SCK_POL_FALLING); 							
		ma_setProcReleaseLvl(MA_ATT_REL_NORMAL); 						
	 	ma_setProcAttackLvl(MA_ATT_REL_NORMAL); 					
 		ma_setProcEn(1); 											
 		ma_setProcLimiterEn(1); 										
		ma_setVolumeCh0(MA_DEF_VOL_DB_CH0,MA_DEF_VOL_LSB_CHX);
		ma_setVolumeCh1(MA_DEF_VOL_DB_CH1,MA_DEF_VOL_LSB_CHX);
		ma_setVolumeCh2(MA_DEF_VOL_DB_CH2,MA_DEF_VOL_LSB_CHX);
		ma_setVolumeCh3(MA_DEF_VOL_DB_CH3,MA_DEF_VOL_LSB_CHX);
		ma_setVolumeMaster(0x40,0x0);
		//ma_setVolume(-15);												// Set Volume to 0 dB 
	throwError(__LINE__); 
}

void ma_i2c_update()
{
	i2cLenght = REGAMOUNT; 
	ma.i2c_send(regTable,dataTable,i2cLenght,i2cLenght);
}

void ma_i2c_feltch()
{
	i2cLenght = REGAMOUNT - READONLY; 
	ma.i2c_read(regTable,dataTable,i2cLenght,i2cLenght);
}

void throwError(uint16_t error)
{
	printf ("\n\rma.c Has generated an Error on line >>%d<<\n\r", error); 
}

void ma_setPowerMode(uint8_t mode)
{
	bitStart = MA_SHIFT_PWR_MODE_SEL ; 
	bitStop = bitStart + MA_LEN_PWR_MODE_SEL; 
	switch(mode)
	{
		case MA_PWR_MODE_MAN
			bitNo = MA_MANUALPM__SHIFT;
			set_nth_bit_uint8(&dataTable[MA_IND_PWR_MODE_CTRL], bitNo); 		
			break;
		case MA_PWR_MODE_AUTO
			bitNo = MA_MANUALPM__SHIFT;
			unset_nth_bit_uint8(&dataTable[MA_IND_PWR_MODE_CTRL], bitNo); 		
			break;
		case MA_PWR_MODE_1:
			valToset = MA_PWR_MODE_1;
			set_bits_range_uint8(&dataTable[MA_IND_PWR_MODE_CTRL], bitStart, bitStop, valToset); 			
			break; 
		
		case MA_PWR_MODE_2: 	
			valToset = MA_PWR_MODE_2;
			set_bits_range_uint8(&dataTable[MA_IND_PWR_MODE_CTRL], bitStart, bitStop, valToset); 			
			break; 
		
		case MA_PWR_MODE_3: 	
			valToset = MA_PWR_MODE_3;
			set_bits_range_uint8(&dataTable[MA_IND_PWR_MODE_CTRL], bitStart, bitStop, valToset); 			
			break;  
		
		case MA_PWR_MODE_DEFF:	
			dataTable[MA_IND_PWR_MODE_CTRL] = defValTable[MA_DEF_PWR_MODE_CTRL]; 
			break; 
		
		default: 
				throwError(__LINE__); 
	}
}

void ma_setTreshold(uint8_t transition, uint8_t value)
{
	if(value <= 0 && value <= 255)
	{
		switch(transition)
		{
			case MA_MTHR_1TO2 :
				dataTable[MA_REG_MTHR_1TO2] = value;
				break;
			
			case MA_MTHR_2TO1 : 
				dataTable[MA_IND_MTHR_2TO1] = value;
				break;  
			
			case MA_MTHR_2TO3 : 
				dataTable[MA_IND_MTHR_2TO3] = value;
				break; 
			
			case MA_MTHR_3TO2 : 
				dataTable[MA_IND_MTHR_3TO2] = value;
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
}

void ma_setClipping(uint8_t enable)
{
	bitNo = MA_SHIFT_SOFT_CLAMP; 
	if (enable == 0)
	{
		unset_nth_bit_uint8(&dataTable[MA_IND_LATCH_CLAMP], bitNo);
	}
	else if (enable == 1)
	{
		set_nth_bit_uint8(&dataTable[MA_IND_LATCH_CLAMP], bitNo);
	}
	else
	{
		throwError(__LINE__); 
	}
		
}

void ma_setOcp(uint8_t enable)
{
	bitNo = MA_SHIFT_OCP_LATCH; 
	if (enable == 0)
	{
		unset_nth_bit_uint8(&dataTable[MA_IND_LATCH_CLAMP], bitNo);
	}
	else if (enable == 1)
	{
		set_nth_bit_uint8(&dataTable[MA_IND_LATCH_CLAMP], bitNo);
	}
	else
	{
		throwError(__LINE__); 
	}
}

void ma_setPowerModeProfileSetings(uint8_t setings)
{
	switch(setings)
	{
		case MA_POWER_PROFILE_0 :
			valToset = MA_POWER_PROFILE_0;
			break; 
		case MA_POWER_PROFILE_1 :
			valToset = MA_POWER_PROFILE_1;
			break; 
		case MA_POWER_PROFILE_2 :
			valToset = MA_POWER_PROFILE_2;
			break; 
		case MA_POWER_PROFILE_3 :
			valToset = MA_POWER_PROFILE_3;
			break; 
		case MA_POWER_PROFILE_4 :
			valToset = MA_POWER_PROFILE_4;
			break; 
		default:
			throwError(__LINE__); 
	}
	
	bitStart = MA_SHIFT_PM_PROFILE_MODE ; 
	bitStop = bitStart + MA_LEN_PM_PROFILE_MODE; 
	set_bits_range_uint8(&dataTable[MA_IND_PM_PROFILE_MODE], bitStart, bitStop, valToset);
}

void ma_setPowerModeProfileConfig(uint8_t scheme, uint8_t powerMode)
{
	if(scheme <= 3 && scheme >= 0 && powerMode <= 3 && powerMode >= 1)
	{
		switch(powerMode)
		{
			case MA_POWER_MODE_1 : 
				switch(scheme)
				{
					case MA_POWER_SCHEME_CUSTOM : 
						valToset = 2;
						bitStart = MA_SHIFT_PM_PROFILE_PM1; 
						bitStop = bitStart + MA_LEN_PM_PROFILE_PM1; 
						set_bits_range_uint8(&dataTable[MA_IND_PM_PROFILE_CONF], bitStart, bitStop, valToset);
						break; 
						 
					case MA_POWER_SCHEME_A : 
						valToset = MA_POWER_SCHEME_A;
						bitStart = MA_SHIFT_PM_PROFILE_PM1; 
						bitStop = bitStart + MA_LEN_PM_PROFILE_PM1; 
						set_bits_range_uint8(&dataTable[MA_IND_PM_PROFILE_CONF], bitStart, bitStop, valToset);
						break; 
						
					case MA_POWER_SCHEME_B : 
						valToset = MA_POWER_SCHEME_B;
						bitStart = MA_SHIFT_PM_PROFILE_PM1; 
						bitStop = bitStart + MA_LEN_PM_PROFILE_PM1; 
						set_bits_range_uint8(&dataTable[MA_IND_PM_PROFILE_CONF], bitStart, bitStop, valToset);
						break; 
						
					case MA_POWER_SCHEME_C : 
						valToset = MA_POWER_SCHEME_C;
						bitStart = MA_SHIFT_PM_PROFILE_PM1; 
						bitStop = bitStart + MA_LEN_PM_PROFILE_PM1; 
						set_bits_range_uint8(&dataTable[MA_IND_PM_PROFILE_CONF], bitStart, bitStop, valToset);
						break; 
						
					case MA_POWER_SCHEME_D :
						valToset = MA_POWER_SCHEME_D;
						bitStart = MA_SHIFT_PM_PROFILE_PM1; 
						bitStop = bitStart + MA_LEN_PM_PROFILE_PM1; 
						set_bits_range_uint8(&dataTable[MA_IND_PM_PROFILE_CONF], bitStart, bitStop, valToset);
						break; 
						
					default : 
						throwError(__LINE__); 
				}

			case MA_POWER_MODE_2 : 
				switch(scheme)
				{
					case MA_POWER_SCHEME_CUSTOM : 
						valToset = 3;
						bitStart = MA_SHIFT_PM_PROFILE_PM2; 
						bitStop = bitStart + MA_LEN_PM_PROFILE_PM2; 
						set_bits_range_uint8(&dataTable[MA_IND_PM_PROFILE_CONF], bitStart, bitStop, valToset);
						break; 
						 
					case MA_POWER_SCHEME_A : 
						valToset = MA_POWER_SCHEME_A;
						bitStart = MA_SHIFT_PM_PROFILE_PM2; 
						bitStop = bitStart + MA_LEN_PM_PROFILE_PM2; 
						set_bits_range_uint8(&dataTable[MA_IND_PM_PROFILE_CONF], bitStart, bitStop, valToset);
						break; 
						
					case MA_POWER_SCHEME_B : 
						valToset = MA_POWER_SCHEME_B;
						bitStart = MA_SHIFT_PM_PROFILE_PM2; 
						bitStop = bitStart + MA_LEN_PM_PROFILE_PM2; 
						set_bits_range_uint8(&dataTable[MA_IND_PM_PROFILE_CONF], bitStart, bitStop, valToset);
						break; 
						
					case MA_POWER_SCHEME_C : 
						valToset = MA_POWER_SCHEME_C;
						bitStart = MA_SHIFT_PM_PROFILE_PM2; 
						bitStop = bitStart + MA_LEN_PM_PROFILE_PM2; 
						set_bits_range_uint8(&dataTable[MA_IND_PM_PROFILE_CONF], bitStart, bitStop, valToset);
						break; 
						
					case MA_POWER_SCHEME_D :
						valToset = MA_POWER_SCHEME_D;
						bitStart = MA_SHIFT_PM_PROFILE_PM2; 
						bitStop = bitStart + MA_LEN_PM_PROFILE_PM2; 
						set_bits_range_uint8(&dataTable[MA_IND_PM_PROFILE_CONF], bitStart, bitStop, valToset);
						break; 
						
					default : 
						throwError(__LINE__);  
				}


			case MA_POWER_MODE_3 : 
				switch(scheme)
				{
					case MA_POWER_SCHEME_CUSTOM : 
						valToset = 3;
						bitStart = MA_SHIFT_PM_PROFILE_PM3; 
						bitStop = bitStart + MA_LEN_PM_PROFILE_PM3; 
						set_bits_range_uint8(&dataTable[MA_IND_PM_PROFILE_CONF], bitStart, bitStop, valToset);
						break; 
						 
					case MA_POWER_SCHEME_A : 
						valToset = MA_POWER_SCHEME_A;
						bitStart = MA_SHIFT_PM_PROFILE_PM3; 
						bitStop = bitStart + MA_LEN_PM_PROFILE_PM3; 
						set_bits_range_uint8(&dataTable[MA_IND_PM_PROFILE_CONF], bitStart, bitStop, valToset);
						break; 
						
					case MA_POWER_SCHEME_B : 
						valToset = MA_POWER_SCHEME_B;
						bitStart = MA_SHIFT_PM_PROFILE_PM3; 
						bitStop = bitStart + MA_LEN_PM_PROFILE_PM3; 
						set_bits_range_uint8(&dataTable[MA_IND_PM_PROFILE_CONF], bitStart, bitStop, valToset);
						break; 
						
					case MA_POWER_SCHEME_C : 
						valToset = MA_POWER_SCHEME_C;
						bitStart = MA_SHIFT_PM_PROFILE_PM3; 
						bitStop = bitStart + MA_LEN_PM_PROFILE_PM3; 
						set_bits_range_uint8(&dataTable[MA_IND_PM_PROFILE_CONF], bitStart, bitStop, valToset);
						break; 
						
					case MA_POWER_SCHEME_D :
						valToset = MA_POWER_SCHEME_D;
						bitStart = MA_SHIFT_PM_PROFILE_PM3; 
						bitStop = bitStart + MA_LEN_PM_PROFILE_PM3; 
						set_bits_range_uint8(&dataTable[MA_IND_PM_PROFILE_CONF], bitStart, bitStop, valToset);
						break; 
						
					default : 
						throwError(__LINE__);  
				}			
				
			default :
				throwError(__LINE__); 
		}
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void ma_clearOcpLatch()
{
	bitNo = MA_SHIFT_OCP_LATCH_CLEAR;
	unset_nth_bit_uint8(&dataTable[MA_IND_OCP_LATCH_CLEAR], bitNo);
}

void ma_setAudioInMode(uint8_t mode)
{
	if(mode <= 2 && mode >= 0 )
	{
		switch(mode)
		{
			case MA_AUDIO_IN_MODE_0 :
				valToset = MA_AUDIO_IN_MODE_0;
				bitStart = MA_SHIFT_AUDIO_IN_MODE; 
				bitStop = bitStart + MA_LEN_AUDIO_IN_MODE; 
				set_bits_range_uint8(&dataTable[MA_IND_PM_PROFILE_CONF], bitStart, bitStop, valToset);
				break; 
			case MA_AUDIO_IN_MODE_1 : 
				valToset = MA_AUDIO_IN_MODE_1;
				bitStart = MA_SHIFT_AUDIO_IN_MODE; 
				bitStop = bitStart + MA_LEN_AUDIO_IN_MODE; 
				set_bits_range_uint8(&dataTable[MA_IND_PM_PROFILE_CONF], bitStart, bitStop, valToset);
				break; 
			case MA_AUDIO_IN_MODE_DEFF : 
				valToset = MA_AUDIO_IN_MODE_0;
				bitStart = MA_SHIFT_AUDIO_IN_MODE; 
				bitStop = bitStart + MA_LEN_AUDIO_IN_MODE; 
				set_bits_range_uint8(&dataTable[MA_IND_PM_PROFILE_CONF], bitStart, bitStop, valToset);
				break; 
			default : 
				throwError(__LINE__); 
		}
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void ma_setDcProtection(uint8_t enable)
{
	bitNo = MA_SHIFT_DC_PROTECTION;
	if(enable == 0)
	{
		unset_nth_bit_uint8(&dataTable[MA_IND_DC_PROTECTION],bitNo);
	}
	else if(enable == 1)
	{
		set_nth_bit_uint8(&dataTable[MA_IND_DC_PROTECTION],bitNo);
	}
	else 
	{
		throwError(__LINE__);
	}
}

void ma_setAudioInOverwrite(uint8_t enable)
{
	bitNo = MA_SHIFT_AUDIO_IN_OVERWRITE;
	if(enable == 0)
	{
		unset_nth_bit_uint8(&dataTable[MA_IND_AUDIO_IN_OVERWRITE],bitNo);
	}
	else if(enable == 1) 
	{
		set_nth_bit_uint8(&dataTable[MA_IND_AUDIO_IN_OVERWRITE],bitNo);
	}
	else 
	{
		throwError(__LINE__);
	}
}

void ma_clearErrHandler()
{
	bitNo = MA_SHIFT_ERROR_HANDLER;
	unset_nth_bit_uint8(&dataTable[MA_IND_ERROR_HANDLER],bitNo);
}

void ma_setI2sFormat(uint8_t format)
{
	switch(format)
	{	
		case MA_I2S_STANDART :
			valToset = MA_I2S_STANDART;
			break; 
		case MA_I2S_LEFT :
			valToset = MA_I2S_LEFT;
			break; 
		case MA_I2S_RIGHT_16b :
			valToset = MA_I2S_RIGHT_16b;
			break; 
		case MA_I2S_RIGHT_18b :
			valToset = MA_I2S_RIGHT_18b;
			break; 
		case MA_I2S_RIGHT_20b :
			valToset = MA_I2S_RIGHT_20b;
			break; 
		case MA_I2S_RIGHT_24b :
			valToset = MA_I2S_RIGHT_24b;
			break; 
		default : 
			throwError(__LINE__); 
	}	
	bitStart = MA_SHIFT_PCM_WORD_FORMAT; 
	bitStop = bitStart + MA_LEN_PCM_WORD_FORMAT;
	set_bits_range_uint8(&dataTable[MA_IND_PCM_PROC_SET], bitStart, bitStop, valToset);						
}


void ma_setI2sRightFirst(uint8_t leftOrRight)
{
	bitNo = MA_SHIFT_I2S_RIGHT_FIRST;

	if (leftOrRight == 0)
	{
		unset_nth_bit_uint8(&dataTable[MA_IND_I2S_CONFIG],bitNo);
	}
	else if (leftOrRight == 1)
	{
		set_nth_bit_uint8(&dataTable[MA_IND_I2S_CONFIG],bitNo);
	}
	else 
	{
		throwError(__LINE__);
	}
}


void ma_setI2sFrameSize(uint8_t bits)
{
	switch (bits)
	{
		case 64 :
			valToset = 0;
			break;

		case 48 : 
			valToset = 1;
			break; 

		case 32 : 
			valToset = 2;
			break;  

		default : 
			  throwError(__LINE__); 	
	
	}
	bitStart = MA_SHIFT_I2S_FRAME_SIZE; 
	bitStop = bitStart + MA_LEN_I2S_FRAME_SIZE; 
	set_bits_range_uint8(&dataTable[MA_IND_I2S_CONFIG], bitStart, bitStop, valToset);
}


void ma_setI2sBitOrder(uint8_t mostOrLeast)
{
	bitNo = MA_SHIFT_I2S_ORDER;
	if (mostOrLeast == 0)
	{
		unset_nth_bit_uint8(&dataTable[MA_IND_I2S_CONFIG],bitNo);
	}
	else if (mostOrLeast == 1)
	{
		set_nth_bit_uint8(&dataTable[MA_IND_I2S_CONFIG],bitNo);
	}
	else 
	{
		throwError(__LINE__);
	}
}


void ma_setI2sWsPolarityHigh(uint8_t highOrLow)
{
	bitNo = MA_SHIFT_I2S_WS_POL;
	if (highOrLow == 0)
	{
		unset_nth_bit_uint8(&dataTable[MA_IND_I2S_CONFIG],bitNo);
	}
	else if (highOrLow == 1)
	{
		set_nth_bit_uint8(&dataTable[MA_IND_I2S_CONFIG],bitNo);
	}
	else 
	{
		throwError(__LINE__);
	}
}

void ma_setI2sSckPolarityFalling(uint8_t risingOrFalling)
{ 
	bitNo = MA_SHIFT_I2S_SCK_POL;
	if (risingOrFalling == 0)
	{
		unset_nth_bit_uint8(&dataTable[MA_IND_I2S_CONFIG],bitNo);
	}
	else if (risingOrFalling == 1)
	{
		set_nth_bit_uint8(&dataTable[MA_IND_I2S_CONFIG],bitNo);
	}
	else 
	{
		throwError(__LINE__);
	}
}



void ma_setProcReleaseLvl(uint8_t lvl)
{
	switch (lvl)
	{
		case MA_ATT_REL_SLOW :
			valToset = MA_ATT_REL_SLOW;
			break;

		case MA_ATT_REL_NORMAL : 
			valToset = MA_ATT_REL_NORMAL;
			break; 

		case MA_ATT_REL_FAST : 
			valToset = MA_ATT_REL_FAST;
			break;  

		default : 
			  throwError(__LINE__); 	
	
	}
	bitStart = MA_SHIFT_PROC_RELEASE; 
	bitStop = bitStart + MA_LEN_PROC_RELEASE;
	set_bits_range_uint8(&dataTable[MA_IND_PCM_PROC_SET], bitStart, bitStop, valToset);			 
}

void ma_setProcAttackLvl(uint8_t lvl)
{
	switch (lvl)
	{
		case MA_ATT_REL_SLOW :
			valToset = MA_ATT_REL_SLOW;
			break;

		case MA_ATT_REL_NORMAL : 
			valToset = MA_ATT_REL_NORMAL;
			break; 

		case MA_ATT_REL_FAST : 
			valToset = MA_ATT_REL_FAST;
			break;  

		default : 
			  throwError(__LINE__); 	
	
	}
	bitStart = MA_SHIFT_PROC_ATTACK; 
	bitStop = bitStart + MA_LEN_PROC_ATTACK;
	set_bits_range_uint8(&dataTable[MA_IND_PCM_PROC_SET], bitStart, bitStop, valToset);	
}


void ma_setProcEn(uint8_t enable)
{
	bitNo = MA_SHIFT_PROC_ENABLE;
	if (enable == 0)
	{
		unset_nth_bit_uint8(&dataTable[MA_IND_PCM_PROC_SET],bitNo);
	}
	else if (enable == 1)
	{
		set_nth_bit_uint8(&dataTable[MA_IND_PCM_PROC_SET],bitNo);
	}
	else 
	{
		throwError(__LINE__);
	}
}
 
// TODO : Direct update via i2c 
void ma_setProcMute(uint8_t mute)
{
	bitNo = MA_SHIFT_MUTE_EN;
	if (mute == 0)
	{
		unset_nth_bit_uint8(&dataTable[MA_IND_I2S_CONFIG],bitNo);
	}
	else if (mute == 1)
	{
		set_nth_bit_uint8(&dataTable[MA_IND_I2S_CONFIG],bitNo);
	}
	else 
	{
		throwError(__LINE__);
	}
}

void ma_setProcLimiter(uint8_t enable)
{
	bitNo = MA_SHIFT_LIMITER_EN;
	if (enable == 0)
	{
		unset_nth_bit_uint8(&dataTable[MA_IND_I2S_CONFIG],bitNo);
	}
	else if (enable == 1)
	{
		set_nth_bit_uint8(&dataTable[MA_IND_I2S_CONFIG],bitNo);
	}
	else 
	{
		throwError(__LINE__);
	}
}

/*
void ma_getVolume(void)
{
	ma
}
*/

int16_t ma_getVolumeDb(void)
{
	uint8_t DbFractionTab[3] = {25,50,75}; 
 	int16_t volume = 0; 	

	volume += (24 - dataTable[MA_IND_VOL_DB_MASTER]) * 100 - DbFractionTab[dataTable[MA_IND_VOL_LSB_MASTER]-1];    
			
	printf("\nVolume: %d\t\n", volume);
	return volume; 
}

void ma_setVolumeCh0(uint8_t db, uint8_t lsb)
{
	if(db >= 0 && db <=255 && lsb>= 0 && lsb <= 3)
	{
		dataTable[MA_IND_VOL_DB_CH0] = db;
		bitStart = MA_SHIFT_VOL_LSB_CH0; 
		bitStop = bitStart + MA_LEN_VOL_LSB_CH0;
		set_bits_range_uint8(&dataTable[MA_IND_VOL_LSB_CHX], bitStart, bitStop, lsb);	
	}
	else 
	{
		throwError(__LINE__); 
	}
}
// TODO : Direct update via i2c 
void ma_setVolumeCh1(uint8_t db, uint8_t lsb)
{
	if(db >= 0 && db <=255 && lsb>= 0 && lsb <= 3)
	{
		dataTable[MA_IND_VOL_DB_CH1] = db;
		bitStart = MA_SHIFT_VOL_LSB_CH1; 
		bitStop = bitStart + MA_LEN_VOL_LSB_CH1;
		set_bits_range_uint8(&dataTable[MA_IND_VOL_LSB_CHX], bitStart, bitStop, lsb);	
	}
	else 
	{
		throwError(__LINE__); 
	}
}
// TODO : Direct update via i2c 
void ma_setVolumeCh2(uint8_t db, uint8_t lsb)
{
	if(db >= 0 && db <=255 && lsb>= 0 && lsb <= 3)
	{
		dataTable[MA_IND_VOL_DB_CH2] = db;
		bitStart = MA_SHIFT_VOL_LSB_CH2; 
		bitStop = bitStart + MA_LEN_VOL_LSB_CH2;
		set_bits_range_uint8(&dataTable[MA_IND_VOL_LSB_CHX], bitStart, bitStop, lsb);	
	}
	else 
	{
		throwError(__LINE__); 
	}
}
// TODO : Direct update via i2c 
void ma_setVolumeCh3(uint8_t db, uint8_t lsb)
{
	if(db >= 0 && db <=255 && lsb>= 0 && lsb <= 3)
	{
		dataTable[MA_IND_VOL_DB_CH3] = db;
		bitStart = MA_SHIFT_VOL_LSB_CH3; 
		bitStop = bitStart + MA_LEN_VOL_LSB_CH3;
		set_bits_range_uint8(&dataTable[MA_IND_VOL_LSB_CHX], bitStart, bitStop, lsb);	
	}
	else 
	{
		throwError(__LINE__); 
	}
}
// TODO : Direct update via i2c 
void ma_setVolumeMaster(uint8_t db, uint8_t lsb)
{
	if(db >= 0 && db <=255 && lsb>= 0 && lsb <= 3)
	{
		dataTable[MA_IND_VOL_DB_MASTER] = db;
		bitStart = MA_SHIFT_VOL_LSB_MASTER; 
		bitStop = bitStart + MA_LEN_VOL_LSB_MASTER;
		set_bits_range_uint8(&dataTable[MA_IND_VOL_LSB_MASTER], bitStart, bitStop, lsb);

		i2cLenght = 2; 
		regBuffer[0]  = regTable[MA_IND_VOL_DB_MASTER];
		dataBuffer[0] = dataTable[MA_IND_VOL_DB_MASTER];
		regBuffer[1]  = regTable[MA_IND_VOL_LSB_MASTER];
		dataBuffer[1] = dataTable[MA_IND_VOL_LSB_MASTER];
		//ma.i2c_send(regBuffer,dataBuffer,i2cLenght,i2cLenght);
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void ma_setVolumeMasterDb(int16_t volume)
{
	int16_t DbBuff = 0; 
	uint8_t DbFraction = 0; 
	uint8_t DbNumber = 0; 
   		
	//printf("Volume: %d\t", volume); 
	
	if (volume >= 0)
	{
		if( volume <= MA_VOL_MAX)
		{
			DbFraction = (char) get_n_bits_lsb_int16(volume,2); 
			DbBuff = (volume/100); 
			
			if(DbFraction == 0)
			{
				DbBuff = (MA_VOL_MAX_DB) - DbBuff; 
			} else { DbFraction = (DbFraction^3) + 1; DbBuff = (MA_VOL_MAX_DB) - DbBuff -1; } DbNumber = (char)DbBuff; printf("Bdnumber: %u\tfraction: %u \n",DbNumber, DbFraction); 
			
			ma_setVolumeMaster(DbNumber, DbFraction);
		}
		else 
		{
			throwError(__LINE__); 
		}					
	} 
	else
	{	
		if(volume >= MA_VOL_MIN)
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
		   	//printf("Bdnumber: %u\tfraction: %u \n",DbNumber, DbFraction);
			ma_setVolumeMaster(DbNumber, DbFraction);
		}
		else
		{
			throwError(__LINE__); 
		}
	}
}
void ma_printCurrentCconf(void)
{
	printf("\n\n\t CURRENT CONFIGURATION OF MA12070P \n\n");
	printf("\r\nMA_REG_PWR_MODE_CTRL \t: "		,dataTable[MA_IND_PWR_MODE_CTRL]);
	printf("\r\nMA_REG_MTHR_1TO2 \t: "			,dataTable[MA_IND_MTHR_1TO2]);
	printf("\r\nMA_REG_MTHR_2TO1 \t: "			,dataTable[MA_IND_MTHR_2TO1]);
	printf("\r\nMA_REG_MTHR_2TO3 \t: "			,dataTable[MA_IND_MTHR_2TO3]);
	printf("\r\nMA_REG_MTHR_3TO2 \t: "			,dataTable[MA_IND_MTHR_3TO2]);
	printf("\r\nMA_REG_LATCH_CLAMP \t: "		,dataTable[MA_IND_LATCH_CLAMP]);
	printf("\r\nMA_REG_PM_PROFILE_MODE \t: "	,dataTable[MA_IND_PM_PROFILE_MODE]);
	printf("\r\nMA_REG_PM_PROFILE_CONF \t: "	,dataTable[MA_IND_PM_PROFILE_CONF]);
	printf("\r\nMA_REG_OCP_LATCH_CLEAR \t: "	,dataTable[MA_IND_OCP_LATCH_CLEAR]);
	printf("\r\nMA_REG_AUDIO_IN_MODE \t: "		,dataTable[MA_IND_AUDIO_IN_MODE]);
	printf("\r\nMA_REG_DC_PROTECTION \t: "		,dataTable[MA_IND_DC_PROTECTION]);
	printf("\r\nMA_REG_AUDIO_IN_OVERWRITE \t: "	,dataTable[MA_IND_AUDIO_IN_OVERWRITE]);
	printf("\r\nMA_REG_ERROR_HANDLER \t: "		,dataTable[MA_IND_ERROR_HANDLER]);
	printf("\r\nMA_REG_PCM_PROC_SET \t: "		,dataTable[MA_IND_PCM_PROC_SET]);
	printf("\r\nMA_REG_I2S_CONFIG \t: "			,dataTable[MA_IND_I2S_CONFIG]);
	printf("\r\nMA_REG_VOL_DB_MASTER \t: "		,dataTable[MA_IND_VOL_DB_MASTER]);
	printf("\r\nMA_REG_VOL_LSB_MASTER \t: "		,dataTable[MA_IND_VOL_LSB_MASTER]);
	printf("\r\nMA_REG_VOL_DB_CH0 \t: "			,dataTable[MA_IND_VOL_DB_CH0]);
	printf("\r\nMA_REG_VOL_DB_CH1 \t: "			,dataTable[MA_IND_VOL_DB_CH1]);
	printf("\r\nMA_REG_VOL_DB_CH2 \t: "			,dataTable[MA_IND_VOL_DB_CH2]);
	printf("\r\nMA_REG_VOL_DB_CH3 \t: "			,dataTable[MA_IND_VOL_DB_CH3]);
	printf("\r\nMA_REG_VOL_LSB_CHX \t: "		,dataTable[MA_IND_VOL_LSB_CHX]);
	printf("\r\nMA_REG_THR_DB_CH0 \t: "			,dataTable[MA_IND_THR_DB_CH0]);
	printf("\r\nMA_REG_THR_DB_CH1 \t: "			,dataTable[MA_IND_THR_DB_CH1]);
	printf("\r\nMA_REG_THR_DB_CH2 \t: "			,dataTable[MA_IND_THR_DB_CH2]);
	printf("\r\nMA_REG_THR_DB_CH3 \t: "			,dataTable[MA_IND_THR_DB_CH3]);
	printf("\r\nMA_REG_THR_LSB_CHX \t: "		,dataTable[MA_IND_THR_LSB_CHX]);
	printf("\r\nMA_REG_MON0_FREQ_PM \t: "		,dataTable[MA_IND_MON0_FREQ_PM]);
	printf("\r\nMA_REG_MON0 \t\t: "				,dataTable[MA_IND_MON0]);
	printf("\r\nMA_REG_MON0_MODUL \t: "			,dataTable[MA_IND_MON0_MODUL]);
	printf("\r\nMA_REG_MON1_FREQ_PM \t: "		,dataTable[MA_IND_MON1_FREQ_PM]);
	printf("\r\nMA_REG_MON1 \t\t: "				,dataTable[MA_IND_MON1]);
	printf("\r\nMA_REG_MON_CH1_MODUL \t: "		,dataTable[MA_IND_MON_CH1_MODUL]);
	printf("\r\nMA_REG_ERRO_ACC \t: "			,dataTable[MA_IND_ERRO_ACC]);
	printf("\r\nMA_REG_MON_MSEL \t: "			,dataTable[MA_IND_MON_MSEL]);
	printf("\r\nMA_REG_ERROR \t\t: "			,dataTable[MA_IND_ERROR]);
	printf("\r\nMA_REG_MON_LIMIT_CLI \t: "		,dataTable[MA_IND_MON_LIMIT_CLIP]);
}
