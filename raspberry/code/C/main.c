#include "main.h"
#include "bh1750/bh1750.h"
#include "algorithms/bitgestion.h"
#include "ma12070/ma12070.h"

int main(int argc, char *argv[])
{
	ma12070_configure(0); 
	ma12070_getCurrentDevInfo(); 
	ma12070_printCurrentCconf();
	return 0; 
}
