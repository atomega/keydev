#include "amplifier_gpio.h"

uint8_t readGpio(uint8_t pin)
{
	char path[SNPRINTF_BUFF];
	char value_str[3];
	uint16_t fd;

	checkAmpPin(pin);

	snprintf(path, SNPRINTF_BUFF, "/sys/class/gpio/gpio%d/value", pin);
	fd = open(path, O_RDONLY);

	if (-1 == fd){
		return(ERROR_STDERR_OPEN);
	}
	
	if (-1 == read(fd, value_str, 3)) {
		return(ERROR_STDERR_READ);
	}

	close(fd);
	return(atoi(value_str));
}


uint8_t writeGpio(uint8_t pin, uint8_t val)
{
	static const char s_values_str[] = "01";

	char path[SNPRINTF_BUFF];
	uint16_t fd;

	checkAmpPin(pin);
	checkAmpPinSet(val);
	
	snprintf(path, SNPRINTF_BUFF, "/sys/class/gpio/gpio%d/value", pin);
	fd = open(path, O_WRONLY);

	if (-1 == fd) {
		return(ERROR_STDERR_OPEN);
	}

	if (1 != write(fd, &s_values_str[LOW == val ? 0 : 1], 1)) {
		return(ERROR_STDERR_WRITE);
	}

	close(fd);
	return(0);
}


uint8_t checkAmpPin(uint8_t pin)
{
	switch(pin)
	{
		case PIN_MUTE: 
			return 0;
			break; 
		case PIN_ENABLE: 
			return 0;
			break; 
		case PIN_POWER: 
			return 0;
			break; 
		default: 
			printError(__LINE__,__FUNCTION__,__FILE__,ERROR_INVALID_GPIO_NAME);
			break;
	}
	return ERROR_UNHANDELT_FE;
}


uint8_t checkAmpPinSet(uint8_t setAmp)
{
	switch(setAmp)
	{
		case ON: //will also cover HIGH 
 			return 0;
			break; 
		case OFF: //will also cover LOW 
			return 0;
			break; 
		default: 
			printError(__LINE__,__FUNCTION__,__FILE__,ERROR_NOTONOFF);
			break;
	}
	return ERROR_UNHANDELT_FE;
}


uint8_t setAmpMute(uint8_t onOff)
{
	uint8_t ret = 0; 
	if(onOff == ON){
		ret = writeGpio(PIN_MUTE,0);
	}
	else if(onOff == OFF){
		ret = writeGpio(PIN_MUTE,1);
	}
	else {
		return ERROR_NOTONOFF;
	}

	if (!ret){return 0;}
	else {return ret;}

	return ERROR_UNHANDELT_FE; 
}

uint8_t getAmpMute()
{
	if(readGpio(PIN_MUTE) == 1){return 0;}
	else if(readGpio(PIN_MUTE) == 0){return 1;}
	else {return ERROR_UNKNOWNPINVAL;}
	return ERROR_UNHANDELT_FE; 
}


uint8_t setAmpEnable(uint8_t onOff)
{
	uint8_t ret = 0; 
	if(onOff == ON){
		ret = writeGpio(PIN_ENABLE,0);
	}
	else if(onOff == OFF){
		ret = writeGpio(PIN_ENABLE,1);
	}
	else {
		return ERROR_NOTONOFF;
	}

	if (!ret){return 0;}
	else {return ret;}

	return ERROR_UNHANDELT_FE; 
}

uint8_t getAmpEnable()
{
	if(readGpio(PIN_ENABLE) == 1){return 0;}
	else if(readGpio(PIN_ENABLE) == 0){return 1;}
	else {return ERROR_UNKNOWNPINVAL;}

	return ERROR_UNHANDELT_FE; 
}

uint8_t setAmpPower(uint8_t onOff)
{
	uint8_t ret = 0; 
	if(onOff == ON){
		ret = writeGpio(PIN_POWER,0);
	}
	else if(onOff == OFF){
		ret = writeGpio(PIN_POWER,1);
	}
	else {
		return ERROR_NOTONOFF;
	}

	if (!ret){return 0;}
	else {return ret;}

	return ERROR_UNHANDELT_FE; 
}

uint8_t getAmpPower()
{
	if(readGpio(PIN_POWER) == 1){return 0;}
	else if(readGpio(PIN_POWER) == 0){return 1;}
	else {return ERROR_UNKNOWNPINVAL;}
}

