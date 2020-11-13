#include "amplifier.h" 

#define PIN_MUTE 17
#define PIN_ENABLE 27
#define PIN_POWER 22

#define OFF 0
#define ON 1

#define IN  0
#define OUT 1

#define LOW  0
#define HIGH 1

uint8_t readGpio(uint8_t pin);
uint8_t writeGpio(uint8_t pin, uint8_t val);
uint8_t setAmpMute(uint8_t onOff);
uint8_t getAmpMute();
uint8_t setAmpEnable(uint8_t onOff);
uint8_t getAmpEnable();
uint8_t setAmpPower(uint8_t onOff);
uint8_t getAmpPower();
uint8_t checkAmpPin(uint8_t pin);
uint8_t checkAmpPinSet(uint8_t set);
