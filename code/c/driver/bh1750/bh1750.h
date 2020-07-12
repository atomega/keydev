//Start measurement at 4lx resolution. Time typically 16ms.
#define BH1750_CONTINUOUS_LOW_RES_MODE 0x13
//Start measurement at 1lx resolution. Time typically 120ms
#define BH1750_CONTINUOUS_HIGH_RES_MODE_1 0x10
//Start measurement at 0.5lx resolution. Time typically 120ms
#define BH1750_CONTINUOUS_HIGH_RES_MODE_2 0x11
//Start measurement at 1lx resolution. Time typically 120ms
//Device is automatically set to Power Down after measurement.
#define BH1750_ONE_TIME_HIGH_RES_MODE_1 0x20
//Start measurement at 0.5lx resolution. Time typically 120ms
//Device is automatically set to Power Down after measurement.
#define BH1750_ONE_TIME_HIGH_RES_MODE_2 0x21
//Start measurement at 1lx resolution. Time typically 120ms
//Device is automatically set to Power Down after measurement.
#define BH1750_ONE_TIME_LOW_RES_MODE 0x23

#define BH1750_POWER_DOWN  0x00 // No active state
#define BH1750_POWER_ON    0x01 // Power on
#define BH1750_RESET       0x07 // Reset data register value

#define BH1750_ADDR 0x23 // Device Adress 

uint8_t bh1750_sleep(void); 
uint8_t bh1750_wake(void); 
void bh1750_open(void); 
uint8_t bh1750_reset(void); 
uint8_t bh1750_set_mode(uint8_t mode); 
uint16_t bh1750_oneShot(uint8_t mode);
int16_t bh1750_calculateLumen(int16_t measured); 
