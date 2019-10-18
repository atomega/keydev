


#include"main.h"
#include"i2c.h"

uint8_t ma12070_init()
{
	unsigned char volume[2];
		
	volume[0] = 0; 
	volume[1] = 0; 
	
	// Openning the i2c port for communication
	if(i2c_open_device(0x20))
	{
		return 1;	
	}
	else 
	{
		ma12070_configure(0); 
		return 0; 
	}

 
	volume[0] = i2c_read_8(0x40); 
 	volume[1] = i2c_read_8(0x41);
	printf(" Before 0x41+0x40:\t0x%x%x \n", volume[1] & 0xff, volume[0]& 0xff ); 
  	
	i2c_write_16(0x41, 0x01); 
 	volume[0] = i2c_read_8(0x40); 
 	volume[1] = i2c_read_8(0x41);
	printf("After 0x41+0x40:\t0x%x%x \n", volume[1] & 0xff, volume[0]& 0xff ); 
}

uint8_t ma12070_configure(uint8_t Default)
{
	//Set the device back to default setings
	if(Default)
	{	
	
	}
	else 
	{
		
	}
}

uint8_t ma12070_setVolume()
