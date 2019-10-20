#define MA12070_ADDR 0x20 // Device Adress
 
#define MA12070_VOL_MAX 2400
#define MA12070_VOL_MIN -14400
#define MA12070_VOL_MAX_DB 24
#define MA12070_VOL_MIN_DB -144

#define MA12070_REG_VOL_VAL 0x40
#define MA12070_REG_VOL_VAL_DEC 0x41

uint8_t ma12070_setVolume(int16_t volume); 
uint8_t ma12070_init(void); 
uint8_t ma12070_configure(uint8_t Default);
int16_t ma12070_getVolume(void); 
