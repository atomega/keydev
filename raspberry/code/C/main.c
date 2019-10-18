#include "main.h"
#include "bh1750/bh1750.h"
int main()
{
	bh1750_open(); 
	bh1750_oneShot(BH1750_ONE_TIME_HIGH_RES_MODE_1); 
	return 0; 
}
