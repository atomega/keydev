#include <errno.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define SNPRINTF_BUFF 30

#define I2C_INTERFACE_NO 1


#define ARGC_MAX 5 
#define ARGC_MIN 2 

#define ARGC_SELF 1
#define ARGC_COMMAND 2
#define ARGC_ACTION 3
#define ARGC_VALUE 4
#define ARGC_DATA 5

#define ARGV_COMMAND ARGC_COMMAND-1
#define ARGV_ACTION ARGC_ACTION-1
#define ARGV_VALUE ARGC_VALUE-1
#define ARGV_DATA ARGC_DATA-1

#define ERROR_STDERR_OPEN -10
#define ERROR_STDERR_WRITE -11
#define ERROR_STDERR_READ -12

#define ERROR_UNHANDELT_FE -20 

#define ERROR_NOTONOFF -30 
#define ERROR_UNKNOWNPINVAL -31 
#define ERROR_VALUE -32
#define ERROR_ACTION -33
#define ERROR_CMD -34
#define ERROR_NOT_HEX -35
#define ERROR_GET_ARGS -36
#define ERROR_SET_ARGS -37
#define ERROR_INFO_ARGS -38
#define ERROR_NOT_HEX_RANGE -39
#define ERROR_INVALID_PIN_STATE -40
#define ERROR_INVALID_GPIO_NAME -41
#define ERROR_PASSED_ACTION -42
#define ERROR_I2C_REG_VAL -43
#define ERROR_GPIO_REG_VAL -44

#define CMD_GET 0 
#define CMD_SET 1
#define CMD_INFO 2


#define SIZE_OF_COMMANDS 3

#define ACT_MUTE 0
#define ACT_ENABLE 1 
#define ACT_POWER 2 
#define ACT_LIMITER 3 
#define ACT_CLIPPING 4
#define ACT_CHANNEL0 5
#define ACT_CHANNEL1 6
#define ACT_ERROR 7
#define ACT_OUTPUT 8 
#define ACT_ERROR_HISTORY 9  
#define ACT_INFO 10
#define ACT_STATUS 11 
#define ACT_I2C 12
#define ACT_GPIO 13
#define SIZE_OF_ACTIONS 14

#define VAL_ON 0
#define VAL_OFF 1
#define VAL_HIGH 2
#define VAL_LOW 3
#define VAL_FREQUENCY 4 
#define VAL_POWER 5
#define VAL_MUTE 6
#define VAL_VDD 7
#define VAL_PVDD 8
#define VAL_CFLY 9
#define VAL_OCP 10
#define VAL_MODULATION 11 
#define VAL_UP 12
#define VAL_DOWN 13
#define SIZE_OF_VALUES 14
#define VAL_I2C_REG SIZE_OF_VALUES + 1
#define VAL_GPIO_PIN VAL_I2C_REG + 1

uint8_t checkCommand(char *str);
uint8_t checkAction(char *str);
uint8_t checkValue(char *str, uint8_t act);

uint8_t getPinState(char *stat);
uint8_t chechHexAndReturn(char *hex); 
uint8_t printHelp();
uint8_t printError(uint16_t line, const char *func, const char *f, int8_t err);
uint8_t getFromAmp(uint16_t argc, uint8_t act, uint16_t val);
uint8_t setToAmp(uint16_t argc, uint8_t act, uint16_t val, uint16_t d);
uint8_t getAmpInfo(uint8_t act);
uint8_t ampGetFunctions(uint16_t argc, uint8_t act, uint16_t val);
uint8_t ampSetFunctions(uint16_t argc, uint8_t act, uint16_t val);
