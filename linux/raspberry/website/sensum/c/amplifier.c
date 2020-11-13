#include "amplifier.h" 
#include "amplifier_gpio.h" 
#include "amplifier_i2c.h" 

/**
 * List of commands that the user can give as grument
 */
char *argCommand[SIZE_OF_COMMANDS] = 
{
	"get", 
	"set", 
	"info"
};

/**
 * List of actions that the user can give as grument
 */
char *argAction[SIZE_OF_ACTIONS] = 
{
	"mute",
	"enable",
	"power",
	"limiter",
	"clipping",
	"channel0",
	"channel1", 
	"error",
	"output", 
	"error-history", 
	"info",
	"status", 
	"i2c", 
	"gpio"
};

/**
 * List of values that the user can give as grument
 */
char *argValue[SIZE_OF_VALUES] =
{
	"on",
	"off",
	"high",
	"low",
	"frequency",
	"power",
	"mute",
	"vdd",
	"pvdd",
	"cfly",
	"ocp",
	"modulation", 
	"up", 
	"down"
};

/**
 * Global Struct to define an amplifier channel
 */
typedef struct channel
{
	uint8_t frequency; 
	uint8_t powerMode; 
	uint8_t mute; 
	uint8_t vdd;
	uint8_t pVdd; 
	uint8_t Vclfy1; 
	uint8_t Vclfy2;
	uint8_t ovc;
	uint8_t modulation;
}chan; 

/**
 * Global Struct to define an amplifier 
 */
typedef struct amplifier
{
	uint8_t mute; 
	uint8_t enable; 
	uint8_t power; 
	uint8_t limiter; 
	uint8_t cipping;
	uint8_t error; 
	uint8_t memError; 
	chan channel0; 
	chan channel1; 
}amp;

/**
 *Global variable for i2c communication at which the corresponting argv values will be pased.
 */
char *i2cReg; 
char *i2cData; 


int main(int argc, char *argv[])
{
	uint8_t i = 0; 
	uint8_t varCommand = 99; 
	uint8_t varAction = 99; 
	uint16_t varValue = 99; 
	uint16_t varData = 99; 
	
	if(argc > ARGC_MIN && argc <= ARGC_MAX)
	{	
		varCommand = checkCommand(argv[ARGV_COMMAND]);
	
		if(varCommand == CMD_GET)
		{
			if(argc == 4)
			{
				varAction = checkAction(argv[ARGV_ACTION]);
				varValue = checkValue(argv[ARGV_VALUE], varAction);
				if(varValue == VAL_I2C_REG)
				{
					i2cReg = argv[ARGV_VALUE];
				}
				else if(varValue == VAL_GPIO_PIN)
				{
					varValue = atoi(argv[ARGV_VALUE]);
				}
				getFromAmp(argc, varAction, varValue);
			}
			else if (argc == 3)
			{
				varAction = checkAction(argv[ARGV_ACTION]);
				getFromAmp(argc, varAction, 0);
			}
			else 
			{
				printError(__LINE__,__FUNCTION__,__FILE__,ERROR_GET_ARGS);
			}
		}else if(varCommand == CMD_SET)
		{
			if (argc == 5)
			{
				varAction = checkAction(argv[ARGV_ACTION]);
				varValue = checkValue(argv[ARGV_VALUE], varAction);
				if(varValue == VAL_I2C_REG)
				{
					i2cReg = argv[ARGV_VALUE];
					i2cData = argv[ARGV_DATA];
				}
				else if(varValue == VAL_GPIO_PIN)
				{
					varValue = atoi(argv[ARGV_VALUE]);
					if(strcmp(argv[ARGV_DATA],"high") == 0)
					{
						varData = 1;
					}
					else if(strcmp(argv[ARGV_DATA],"low") == 0)
					{
						varData = 0;
					}
					else 
					{
						varData = atoi(argv[ARGV_DATA]);
					}
				}
				setToAmp(argc, varAction, varValue, varData);
			}
			else if (argc == 4)
			{
				varAction = checkAction(argv[ARGV_ACTION]);
				varValue = checkValue(argv[ARGV_VALUE], varAction);
				setToAmp(argc, varAction, varValue,0);
			}
			else 
			{
				printError(__LINE__,__FUNCTION__,__FILE__,ERROR_SET_ARGS);
			}
			
		}else if(varCommand == CMD_INFO)
		{
			if(argc == 3)
			{
				varAction = checkAction(argv[ARGV_ACTION]);
				getAmpInfo(varAction);
			}
			else 
			{
				printError(__LINE__,__FUNCTION__,__FILE__,ERROR_INFO_ARGS);
			}
		}
		else 
		{
			printError(__LINE__,__FUNCTION__,__FILE__,ERROR_CMD);
		}
	}
	else 
	{
		printHelp(); 
	}
	
	printError(__LINE__,__FUNCTION__,__FILE__,ERROR_UNHANDELT_FE);
	return -1; 
}


uint8_t ampGetFunctions(uint16_t argc, uint8_t act, uint16_t val)
{
	switch(act)
	{
		case ACT_MUTE : 
			printf("%d\n",getAmpMute());
			break;
		case ACT_ENABLE : 
			printf("%d\n",getAmpEnable());
			break; 
		case ACT_POWER : 
			printf("%d\n",getAmpPower());
			break; 
		case ACT_LIMITER : 
			getAmpLimiter(); 
			break; 
		case ACT_CLIPPING : 
			getAmpClipping();
			break;
		case ACT_CHANNEL0 : 
			getAmpChannel(0,val); 
			break;
		case ACT_CHANNEL1 : 
			getAmpChannel(1,val); 
			break;
		case ACT_ERROR : 
			getAmpError();
			break;
		case ACT_OUTPUT : 
			getAmpOutput();
			break; 
		case ACT_ERROR_HISTORY : 
			getAmpErrorHistory();
			break;  
		case ACT_INFO :
			//getAmpInfo(); 
			break;
		case ACT_STATUS : 
			//getAmpStatus(); 
			break; 
		default:
			printError(__LINE__,__FUNCTION__,__FILE__,ERROR_PASSED_ACTION);
			break;
	}
	exit(1);
}

uint8_t ampSetFunctions(uint16_t argc, uint8_t act, uint16_t val)
{
	uint8_t onOff = 10; 

	if(strcmp(argValue[val], "on") == 0)
	{
		onOff = ON;
	}
	else if(strcmp(argValue[val], "off") == 0)
	{
		onOff = OFF;
	}
	switch(act)
	{
		case ACT_MUTE : 
			setAmpMute(onOff);
			break;
		case ACT_ENABLE : 
			setAmpEnable(onOff);
			break; 
		case ACT_POWER : 
			setAmpPower(onOff);
			break; 
		default: 
			printError(__LINE__,__FUNCTION__,__FILE__,ERROR_UNHANDELT_FE);
		break;
	}
	exit(1);
}

uint8_t getFromAmp(uint16_t argc, uint8_t act, uint16_t val)
{
	if(act <= SIZE_OF_ACTIONS && act >= 0)
	{
		if(strcmp(argAction[act],"i2c") == 0)
		{
			ampI2cRead(i2cReg);
			exit(1); 
		}
		else if(strcmp(argAction[act],"gpio") == 0)
		{
			printf("%d\n",readGpio(val));
			exit(1); 
		}
		else 
		{
			ampGetFunctions(argc, act, val); 
		}
	}
	else 
	{
		printError(__LINE__,__FUNCTION__,__FILE__,ERROR_PASSED_ACTION);
	}
	
	printError(__LINE__,__FUNCTION__,__FILE__,ERROR_UNHANDELT_FE);
	return -1; 
}

uint8_t setToAmp(uint16_t argc, uint8_t act, uint16_t val, uint16_t d)
{
	if(act <= SIZE_OF_ACTIONS && act >= 0)
	{
		if(strcmp(argAction[act],"i2c") == 0)
		{
			ampI2cWrite(i2cReg,i2cData); 
			exit(1); 
		}
		else if(strcmp(argAction[act],"gpio") == 0)
		{
			writeGpio(val, d); 
			exit(1); 
		}
		else 
		{
			ampSetFunctions(argc, act, val); 
		}
	}
	else 
	{
		printError(__LINE__,__FUNCTION__,__FILE__,ERROR_PASSED_ACTION);
	}

	printError(__LINE__,__FUNCTION__,__FILE__,ERROR_UNHANDELT_FE);
	return -1; 
}

uint8_t getAmpInfo(uint8_t act)
{

	if(act <= SIZE_OF_ACTIONS && act >= 0)
	{
		if(strcmp(argAction[act],"i2c") == 0)
		{
			printf("I2c channel: %d | Device address: 0x%x\n",I2C_INTERFACE_NO, I2C_ADDRESS & 0xff);
		}
		else if(strcmp(argAction[act],"gpio") == 0)
		{
			printf("You are in gpio info\n"); 	
		}
		else 
		{
			printf("You are in normal info\n"); 	
		}
	}
	else 
	{
		printError(__LINE__,__FUNCTION__,__FILE__,ERROR_PASSED_ACTION);
	}
	printError(__LINE__,__FUNCTION__,__FILE__,ERROR_UNHANDELT_FE);
	return -1; 
}

uint8_t checkCommand(char *str)
{
	for(uint8_t i = 0; i < SIZE_OF_COMMANDS ; i++)
	{
		if(strcmp(str,argCommand[i]) == 0)
		{
			return i; 
		}
	}
	printError(__LINE__,__FUNCTION__,__FILE__,ERROR_CMD);
	return -1;
}

uint8_t checkAction(char *str)
{
	for(uint8_t i = 0; i < SIZE_OF_ACTIONS ; i++)
	{
		if(strcmp(str,argAction[i]) == 0)
		{
			return i; 
		}
	}
	printError(__LINE__,__FUNCTION__,__FILE__,ERROR_ACTION);
	return -1;
}

uint8_t checkValue(char *str, uint8_t act)
{	
	if(strcmp(argAction[act],"i2c") == 0)
	{
		return VAL_I2C_REG;	
	}else if(strcmp(argAction[act],"gpio") == 0)
	{
		return VAL_GPIO_PIN; 
	}
	else 
	{
		for(uint8_t i = 0; i < SIZE_OF_VALUES ; i++)
		{
			if(strcmp(str,argValue[i]) == 0)
			{
				return i; 
			}
		}
	}
	
	printError(__LINE__,__FUNCTION__,__FILE__,ERROR_VALUE);
	return -1;
}



uint8_t getPinState(char *stat)
{
	if(strcmp(stat,"on") == 0){
		return ON; 
	}
	else if(strcmp(stat,"off") == 0){
		return OFF; 
	}
	else{
		printError(__LINE__,__FUNCTION__,__FILE__,ERROR_INVALID_PIN_STATE);
	}
	printError(__LINE__,__FUNCTION__,__FILE__,ERROR_UNHANDELT_FE);
	return -1; 
}


uint8_t printError(uint16_t line, const char *func, const char *f, int8_t err)
{
	switch(err)
	{
		case ERROR_UNHANDELT_FE: 
			printf("Error: unhandled end of function | line:%d | func: %s | file: %s \n",line, func, f); 
			break;
		case ERROR_STDERR_OPEN:
			printf("Error: Failed to open the sysfile | line:%d | func: %s | file: %s \n",line, func, f);
			break;
		case ERROR_STDERR_WRITE:
			printf("Error: Failed to write to sysfile | line:%d | func: %s | file: %s \n",line, func, f);
			break;
		case ERROR_STDERR_READ:
			printf("Error: Failed to read to sysfile | line:%d | func: %s | file: %s \n",line, func, f);
			break; 
		case ERROR_NOT_HEX:
			printf("Error: Not an hexadecimal number ex : 0x4f | line:%d | func: %s | file: %s \n",line, func, f); 
			break; 
		case ERROR_NOT_HEX_RANGE:
			printf("Error: hexadecimal is too no in range : 0 to 255 | line:%d | func: %s | file: %s \n",line, func, f); 
			break; 
		case ERROR_INVALID_PIN_STATE: 
			printf("Error: invalid pin state : high or Low | line:%d | func: %s | file: %s \n",line, func, f); 
			break; 
		case ERROR_VALUE:
			printf("Error: invalid value | line:%d | func: %s | file: %s \n",line, func, f); 
			break; 
		case ERROR_ACTION:
			printf("Error: invalid action | line:%d | func: %s | file: %s \n",line, func, f); 
			break; 
		case ERROR_CMD:
			printf("Error: invalid command | line:%d | func: %s | file: %s \n",line, func, f); 
			break; 
		case ERROR_GET_ARGS:
			printf("Error: invalid argument count for \"get\" command | line:%d | func: %s | file: %s \n",line, func, f); 
			break;
		case ERROR_SET_ARGS:
			printf("Error: invalid argument count for \"set\" command | line:%d | func: %s | file: %s \n",line, func, f); 
			break;
		case ERROR_INFO_ARGS:
			printf("Error: invalid argument count for \"info\" command | line:%d | func: %s | file: %s \n",line, func, f); 
			break;
		case ERROR_INVALID_GPIO_NAME:
			printf("Error: invalid pin name | line:%d | func: %s | file: %s \n",line, func, f); 
			break;
		case ERROR_PASSED_ACTION: 
			printf("Error: passed action integer don't match | line:%d | func: %s | file: %s \n",line, func, f); 
			break;
		default:
			printf("Error: Error of Error Reached -> not Good | line:%d | func: %s | file: %s \n",line, func, f); 
			break;
	}
	exit(1);
}

uint8_t printHelp()
{
	printf("\nHelp For amcontrol\n"
			"ampcontrol [command] [action] [value] [data]\n"
			"\t command: get , set , info\n"
			"\t action: mute, enable ect..\n"
			"\t value: on off high low or a hexadecimal register like 0x45 for i2c\n"
			"\t data: only used for i2c communication as hexadecimal value\n"
			"Some examples\n"
			" > ./ampcontrol set mute on\n" 
			" > ./ampcontrol get enbale\n"
			" > ./ampcontrol set i2c 0x40 0x34\n"
			" > ./ampcontrol get i2c 0x40\n"
			" > ./ampcontrol get channel0 frequency" 
			" > ./ampcontrol info i2c\n"
			"the number of passed arguments will determine the right function calls\n"); 
	exit(1);
}
