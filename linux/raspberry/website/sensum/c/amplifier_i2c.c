#include "amplifier_i2c.h"

uint8_t ampI2cRead(char *reg)
{
	char execBuffer [50];
	int i2cRegister = chechHexAndReturn(reg); 
	sprintf (execBuffer, "i2cget -y %d %d %d", I2C_INTERFACE_NO, I2C_ADDRESS, i2cRegister); 
	system(execBuffer); 
	exit(1);
}

uint8_t ampI2cWrite(char *reg, char *data) 
{
	char execBuffer [50];
	int i2cRegister = chechHexAndReturn(reg); 
	int i2cData = chechHexAndReturn(data); 
	sprintf(execBuffer, "i2cset -y %d %d %d %d",I2C_INTERFACE_NO, I2C_ADDRESS, i2cRegister, i2cData); 
	system(execBuffer); 
	exit(1);
}

uint8_t ampI2cDecimalRead(uint8_t reg)
{
	char execBuffer [50];
	sprintf (execBuffer, "i2cget -y %d %d %d", I2C_INTERFACE_NO, I2C_ADDRESS, reg); 
	system(execBuffer); 
	exit(1);
}


uint8_t chechHexAndReturn(char *hex)
{
	if (strlen(hex) == 4)
	{
		if( hex[1] == 'x')
		{
			long deci = strtol(hex, NULL, 16);
			if(deci >= 0 && deci <=255)
			{
				return (int)deci; 
			}
			{
				printError(__LINE__,__FUNCTION__,__FILE__, ERROR_NOT_HEX_RANGE); 
			}
		}
		else 
		{
			printError(__LINE__,__FUNCTION__,__FILE__, ERROR_NOT_HEX); 
		}
	}
	else 
	{
		printError(__LINE__,__FUNCTION__,__FILE__, ERROR_NOT_HEX); 
	}
	printError(__LINE__,__FUNCTION__,__FILE__,ERROR_VALUE);
	return -1;
}

uint8_t getAmpLimiter()
{
	ampI2cDecimalRead(MA_REG_MON_LIMIT_CLIP);
	return 0; 
} 
uint8_t getAmpClipping()
{
	ampI2cDecimalRead(MA_REG_MON_LIMIT_CLIP);
	return 0; 
}
uint8_t getAmpChannel(uint8_t chan , uint16_t val)
{
	if (chan == 0)
	{
		switch(val)
		{
			case VAL_FREQUENCY : 
				ampI2cDecimalRead(MA_REG_MON0_FREQ_PM);
				break; 
			case VAL_POWER : 
				ampI2cDecimalRead(MA_REG_MON0_FREQ_PM);
				break;
			case VAL_MUTE : 
				ampI2cDecimalRead(MA_REG_MON0);
				break;
			case VAL_VDD : 
				ampI2cDecimalRead(MA_REG_MON0);
				break;
			case VAL_PVDD : 
				ampI2cDecimalRead(MA_REG_MON0);
				break;
			case VAL_CFLY : 
				ampI2cDecimalRead(MA_REG_MON0);
				break;
			case VAL_OCP : 
				ampI2cDecimalRead(MA_REG_MON0);
				break;
			case VAL_MODULATION : 
				ampI2cDecimalRead(MA_REG_MON0_MODUL);
				break; 
			default: 
				printError(__LINE__,__FUNCTION__,__FILE__,ERROR_UNHANDELT_FE);
				break;
		}
	}
	else if (chan == 1)
	{
		switch(val)
		{
			case VAL_FREQUENCY : 
				ampI2cDecimalRead(MA_REG_MON1_FREQ_PM);
				break; 
			case VAL_POWER : 
				ampI2cDecimalRead(MA_REG_MON1_FREQ_PM);
				break;
			case VAL_MUTE : 
				ampI2cDecimalRead(MA_REG_MON1);
				break;
			case VAL_VDD : 
				ampI2cDecimalRead(MA_REG_MON1);
				break;
			case VAL_PVDD : 
				ampI2cDecimalRead(MA_REG_MON1);
				break;
			case VAL_CFLY : 
				ampI2cDecimalRead(MA_REG_MON1);
				break;
			case VAL_OCP : 
				ampI2cDecimalRead(MA_REG_MON1);
				break;
			case VAL_MODULATION : 
				ampI2cDecimalRead(MA_REG_MON_CH1_MODUL);
				break; 
			default: 
				printError(__LINE__,__FUNCTION__,__FILE__,ERROR_UNHANDELT_FE);
				break;
		}
	}
	printError(__LINE__,__FUNCTION__,__FILE__,ERROR_UNHANDELT_FE);
	return -1;
} 
uint8_t getAmpError()
{
	ampI2cDecimalRead(MA_REG_ERROR);
	return 0;
}
uint8_t getAmpOutput()
{
	ampI2cDecimalRead(MA_REG_MON_MSEL);
	return 0;
}
uint8_t getAmpErrorHistory()
{
	ampI2cDecimalRead(MA_REG_ERRO_ACC);
	return 0;
}
