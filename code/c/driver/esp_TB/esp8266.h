/// MAIN INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>
#include <sys/types.h>
#include "dbcomm.h"

#define DEVICE_STATE        0x00
#define OVERCURRENT_VAL     0x01
#define OVERHEAT_VAL        0x02 
#define RELAY_STAUS         0x03
#define TEMP_HYST           0x04    
#define CURRENT_HYST        0x05 
#define TEMP_MSB            0x08
#define TEMP_LSB            0x09
#define CURRENT_MSB         0x10
#define CURRENT_LSB         0x11
#define TENSION_MSB         0x10
#define TENSION_LSB         0x11

		
//#define I2C_DEBUG 
//#define I2C_RELEASE 

//#define LCD_DEBUG 
//#define LCD_RELEASE 

//#define MAIN_DEBUG 
//#define MAIN_RELEASE 

//#define GETIP_DEBUG 
//#define IP_RELEASE 

//#define UART_DEBUG 
//#define UART_RELEASE 
