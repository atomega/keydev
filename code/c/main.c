#include "main.h"
#include "algorithms/bitgestion.h"
#include "driver/ma12070/ma12070.h"
#include "baremetal/i2c_raspberry/i2c/i2c.h"
#include "driver/bh1750/bh1750.h"

int main(int argc, char *argv[])
{ 
//	ma12070_initI2c(); 
//	ma12070_configure(1); 
//	ma12070_getCurrentDevInfo(); 
//	ma12070_printCurrentCconf();
	bh1750_open(); 
	bh1750_set_mode(BH1750_ONE_TIME_HIGH_RES_MODE_1);
	bh1750_oneShot(BH1750_ONE_TIME_HIGH_RES_MODE_1);
	return 0; 
}
