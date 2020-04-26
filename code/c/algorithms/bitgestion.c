#include "../main.h"
#include"bitgestion.h"

//SET N th bit to one 


void throwError( uint16_t error)
{
	printf("\n\rAglorithm.c : An Error has been generated on line : >>%d<<\n\r",error);
}


void set_nth_bit_uint8( uint8_t *value, uint8_t &n)
{
	if (n < 8 && n >=0)
	{
		*value|= 1 << n; 
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void set_nth_bit_int8( int8_t *value, uint8_t &n)
{
	if (n < 8 && n >=0)
	{
		*value|= 1 << n; 
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void set_nth_bit_uint16( uint16_t *value, uint8_t &n)
{
	if (n < 16 && n >=0)
	{
		*value|= 1 << n; 
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void set_nth_bit_int16( int16_t *value, uint8_t &n)
{
	if (n < 16 && n >=0)
	{
		*value|= 1 << n; 
	}
	else 
	{
		throwError(__LINE__); 
	}
}

//SET N th bit to 0 
void unset_nth_bit_uint8( uint8_t *value, uint8_t &n)
{
	if (n < 8 && n >=0)
	{
		*value&=~(1 << n);  
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void unset_nth_bit_int8( int8_t *value, uint8_t &n)
{
	if (n < 8 && n >=0)
	{
		*value&=~(1 << n);  
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void unset_nth_bit_uint16( uint16_t *value, uint8_t &n)
{
	if (n < 16 && n >=0)
	{
		*value&=~(1 << n);  
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void unset_nth_bit_int16( int16_t *value, uint8_t &n)
{
	if (n < 16 && n >=0)
	{
		*value&=~(1 << n);  
	}
	else 
	{
		throwError(__LINE__); 
	}
}

//Toggle N th bit 
void toggle_nth_bit_uint8( uint8_t *value, uint8_t &n)
{
	if (n < 8 && n >=0)
	{
		*value^= 1 << n; 
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void toggle_nth_bit_int8( int8_t *value, uint8_t &n)
{
	if (n < 8 && n >=0)
	{
		*value^= 1 << n; 
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void toggle_nth_bit_uint16( uint16_t *value, uint8_t &n)
{
	if (n < 16 && n >=0)
	{
		*value^= 1 << n; 
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void toggle_nth_bit_int16( int16_t *value, uint8_t &n)
{
	if (n < 16 && n >=0)
	{
		*value^= 1 << n; 
	}
	else 
	{
		throwError(__LINE__); 
	}
}

//Get N th bit
void get_nth_bit_uint8( uint8_t *value, uint8_t &n)
{
	if (n < 8 && n >=0)
	{
		*value= (*value>> n) & 1; 
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void get_nth_bit_int8( int8_t *value, uint8_t &n)
{
	if (n < 8 && n >=0)
	{
		*value= (*value>> n) & 1; 
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void get_nth_bit_uint16( uint16_t *value, uint8_t &n)
{
	if (n < 16 && n >=0)
	{
		*value= (*value>> n) & 1; 
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void get_nth_bit_int16( int16_t *value, uint8_t &n)
{
	if (n < 16 && n >=0)
	{
		*value= (*value>> n) & 1; 
	}
	else 
	{
		throwError(__LINE__); 
	}
}



//Change N th bit to x 
//number = (number & ~(1UL << n)) | (x << n);

void change_nth_bit_to_x_uint8( uint8_t *value, uint8_t &n, uint8_t &x)
{
	if (n < 8 && n >=0)
	{
		*value= (*value& ~(1 << n)) | (x << n);
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void change_nth_bit_to_x_int8( int8_t *value, uint8_t &n, uint8_t &x)
{
	if (n < 8 && n >=0)
	{
		*value= (*value& ~(1 << n)) | (x << n);
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void change_nth_bit_to_x_uint16( uint16_t *value, uint8_t &n, uint8_t &x)
{
	if (n < 16 && n >=0)
	{
		*value= (*value& ~(1 << n)) | (x << n);
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void change_nth_bit_to_x_int16( int16_t *value, uint8_t &n, uint8_t &x)
{
	if (n < 16 && n >=0)
	{
		*value= (*value& ~(1 << n)) | (x << n);
	}
	else 
	{
		throwError(__LINE__); 
	}
}




//GET N numer of least significant bits
void get_n_bits_lsb_uint8( uint8_t *value, uint8_t &bits)
{
	if (bits < 8 && bits >=0)
	{
		*value= *value& ((1 << bits)-1);	
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void get_n_bits_lsb_int8(int8_t *value, uint8_t &bits)
{
	if (bits < 8 && bits >=0)
	{
		*value= *value& ((1 << bits)-1);	
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void get_n_bits_lsb_uint16( uint16_t *value, uint8_t &bits)
{
	if (bits < 8 && bits >=0)
	{
		*value= *value& ((1 << bits)-1);	
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void get_n_bits_lsb_int16( int16_t *value, uint8_t &bits)
{
	if (bits < 16 && bits >=0)
	{
		*value= *value& ((1 << bits)-1);	
	}
	else 
	{
		throwError(__LINE__); 
	}
}


//Get N number of most signigiant bit.
void get_n_bits_msb_uint8( uint8_t *value, uint8_t &bits)
{
	if (bits < 8 && bits >=0)
	{
		*value= *value>> (8-bits);	
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void get_n_bits_msb_int8(int8_t *value, uint8_t &bits)
{
	if (bits < 8 && bits >=0)
	{
		*value=	*value>> (8-bits);	
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void get_n_bits_msb_uint16( uint16_t *value, uint8_t &bits)
{
	if (bits < 16 && bits >=0)
	{
		*value= *value>> (16-bits);	
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void get_n_bits_msb_int16( int16_t *value, uint8_t &bits)
{
	if (bits < 16 && bits >=0)
	{
		*value= *value>> (16-bits);	
	}
	else 
	{
		throwError(__LINE__); 
	}
}

// Get Bits range from startBit to stopBit and *value= them shifted.  
void get_bits_range_uint8( uint8_t *value, uint8_t &startBit, uint8_t &stopBit)
{
	if (startBit < 8 && startBit >=0)
	{
		if(stopBit < 8 && stopBit >=0)
		{
			if(startBit < stopBit)
			{
				uint8_t mask = 0;
				uint8_t i = 0; 
				for(i = startBit; i < stopBit; i++ )
        		{
                	mask |= (1 << i);
        		}
        		*value= ((*value& mask) >> startBit); 
			}
		}	
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void get_bits_range_int8( int8_t *value, uint8_t &startBit, uint8_t &stopBit)
{
	if (startBit < 8 && startBit >=0)
	{
		if(stopBit < 8 && stopBit >=0)
		{
			if(startBit < stopBit)
			{
				uint8_t mask = 0;
				uint8_t i = 0; 
				for(i = startBit; i < stopBit; i++ )
        		{
                	mask |= (1 << i);
        		}
        		*value= (*value& mask) >> startBit; 
			}
		}	
	}
	else 
	{
		throwError(__LINE__); 
	}
}

void get_bits_range_uint16( uint16_t *value, uint8_t &startBit, uint8_t &stopBit)
{
	if (startBit < 16 && startBit >=0)
	{
		if(stopBit < 16 && stopBit >=0)
		{
			if(startBit < stopBit)
			{
				uint8_t mask = 0;
				uint8_t i = 0; 
				for(i = startBit; i < stopBit; i++ )
        		{
                	mask |= (1 << i);
        		}
        		*value= (*value& mask) >> startBit; 
			}
		}	
	}
	else 
	{
		throwError(__LINE__); 
	}
}



void get_bits_range_int16( int16_t *value, uint8_t &startBit, uint8_t &stopBit)
{
	if (startBit < 16 && startBit >=0)
	{
		if(stopBit < 16 && stopBit >=0)
		{
			if(startBit < stopBit)
			{
				uint8_t mask = 0;
				uint8_t i = 0; 
				for(i = startBit; i < stopBit; i++ )
        		{
                	mask |= (1 << i);
        		}
        		*value= (*value& mask) >> startBit; 
			}
		}	
	}
	else 
	{
		throwError(__LINE__); 
	}
}


void set_bits_range_uint8(uint8_t *value, uint8_t &startBit, uint8_t &stopBit, uint8_t &replace)
{ 
	if (startBit < 8 && startBit >=0)
	{
		if(stopBit < 8 && stopBit >=0)
		{
			if(startBit < stopBit)
			{
				uint8_t mask = 0;
				uint8_t i = 0; 
				for(i = startBit; i < stopBit; i++ )
        		{
                	mask |= (1 << i);
        		}
        		*value= (*value & ~mask) | replace << startBit; 
			}
		}	
	}
	else 
	{
		throwError(__LINE__); 
	}
} 

void set_bits_range_uint16(uint16_t *value, uint8_t &startBit, uint8_t &stopBit, uint16_t &replace)
{ 
	if (startBit < 16 && startBit >=0)
	{
		if(stopBit < 16 && stopBit >=0)
		{
			if(startBit < stopBit)
			{
				uint8_t mask = 0;
				uint8_t i = 0; 
				for(i = startBit; i < stopBit; i++ )
        		{
                	mask |= (1 << i);
        		}
        		*value= (*value & ~mask) | replace << startBit; 
			}
		}	
	}
	else 
	{
		throwError(__LINE__); 
	}
} 
