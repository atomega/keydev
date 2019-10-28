#include "main.h"
#include "bh1750/bh1750.h"
#include "algorithms/bitgestion.h"
#include "ma12070/ma12070.h"

int main(int argc, char *argv[])
{
//	bh1750_open(); 
//	bh1750_oneShot(BH1750_ONE_TIME_HIGH_RES_MODE_1);  

//	uint8_t utest8 = 48; //255; 
//	int8_t test8 = 0; //127; 
	//uint16_t utest16 = 4; //65535; 
	//int16_t test16 = 4; //32767; 
	//uint8_t n = 1;
	//ma12070_getVolume();  
 
	ma12070_setPowerMode(MA12070_POWER_MODE_2); 
	ma12070_printCurrentCconf(); 
	return 0; 
}
