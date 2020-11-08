
#define VALUE_MAX 30
#include "gpio.h"

int readGpio(char pin)
{
	char path[VALUE_MAX];
	char value_str[3];
	int fd;

	snprintf(path, VALUE_MAX, "/sys/class/gpio/gpio%d/value", pin);
	fd = open(path, O_RDONLY);
	if (-1 == fd) {
		fprintf(stderr, "Failed to open gpio value for reading!\n");
		return(-1);
	}

	if (-1 == read(fd, value_str, 3)) {
		fprintf(stderr, "Failed to read value!\n");
		return(-1);
	}

	close(fd);
	return(atoi(value_str));
}

int getPinNo(char *pinName)
{
		if(strcmp(pinName,"mute") == 0)
		{
			return PIN_MUTE; 
		}
		else if(strcmp(pinName,"enable") == 0)
		{
			return PIN_ENABLE; 
		}
		else if(strcmp(pinName,"power") == 0)
		{
			return PIN_POWER;
		}
		else
		{
			return -1;
		}
		return -1;
}


int getPinVal(char *pinVal)
{
		if(strcmp(pinVal,"high") == 0)
		{
			return HIGH; 
		}
		else if(strcmp(pinVal,"low") == 0)
		{
			return LOW; 
		}
		else
		{
			return -1;
		}
		return -1;
}

int writeGpio(int pin, int value)
{
	static const char s_values_str[] = "01";

	char path[VALUE_MAX];
	int fd;

	snprintf(path, VALUE_MAX, "/sys/class/gpio/gpio%d/value", pin);
	fd = open(path, O_WRONLY);
	if (-1 == fd) {
		fprintf(stderr, "Failed to open gpio value for writing!\n");
		return(-1);
	}

	if (1 != write(fd, &s_values_str[LOW == value ? 0 : 1], 1)) {
		fprintf(stderr, "Failed to write value!\n");
		return(-1);
	}

	close(fd);
	return(0);
}


int main(int argc, char *argv[])
{
	int result = 0; 
	if(argc > 2 && argc <= 4)
	{
		int pin = -1; 
		int pinVal = -1; 
		if(strcmp(argv[1],"get") == 0)
		{
			pin = getPinNo(argv[2]); 
			if(pin >= 0)
			{
				printf("%d\n", readGpio(pin));
				return 1;
			}
			else 
			{
				printf("Error: invalid pin name\n");
				return -1;
			}
		}
		else if(strcmp(argv[1],"set") == 0)		
		{
			pin = getPinNo(argv[2]); 
			pinVal = getPinVal(argv[3]);
			if(pin >= 0)
			{
				if(pinVal >= 0)
				{
					writeGpio(pin, pinVal);
					return 1;
				}
				else 
				{
					printf("Error: invalid pin output value\n");
					return -1;
				}
			}
			else 
			{
				printf("Error: invalid pin name\n");
				return -1;
			}
		}
		else if(strcmp(argv[1],"import") == 0)  
		{
			printf("ToDo: Import fucntion\n");
			return 1; 
		}
		else if(strcmp(argv[1],"export") == 0)
		{
			printf("ToDo: export fucntion\n");
			return 1; 
		}
		else
		{
			printf("Error: invalid argument name\n");
			return -1; 
		}
	}
	else
	{
		printf("Error: Invalid Arguments/Count\n");
		return -1;
	}
	printf("Error: Unhandled exeption\n");
	return -1;
}
