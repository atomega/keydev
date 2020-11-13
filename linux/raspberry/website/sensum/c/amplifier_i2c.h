#include"amplifier.h"
#include"ma120x0/ma120x0.h"

#define I2C_INTERFACE_NO 1
#define I2C_ADDRESS  0x20

uint8_t ampI2cRead(char *reg);
uint8_t ampI2cWrite(char *reg, char *data);
uint8_t chechHexAndReturn(char *hex);
uint8_t getAmpLimiter();
uint8_t getAmpClipping();
uint8_t getAmpChannel(uint8_t chan , uint16_t val);
uint8_t getAmpError();
uint8_t getAmpOutput();
uint8_t getAmpErrorHistory();
uint8_t ampI2cDecimalRead(uint8_t reg);
