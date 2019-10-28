#include "../main.h"
#include"bitgestion.h"

//SET N th bit to one 

uint8_t set_nth_bit_uint8( uint8_t value, uint8_t n)
{
	if (n <= 8 && n >=0)
	{
		value |= 1 << n; 
		return value ;	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

int8_t set_nth_bit_int8( int8_t value, uint8_t n)
{
	if (n <= 8 && n >=0)
	{
		value |= 1 << n; 
		return value ;	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

uint16_t set_nth_bit_uint16( uint16_t value, uint8_t n)
{
	if (n <= 16 && n >=0)
	{
		value |= 1 << n; 
		return value ;	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

int16_t set_nth_bit_int16( int16_t value, uint8_t n)
{
	if (n <= 16 && n >=0)
	{
		value |= 1 << n; 
		return value ;	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

//SET N th bit to 0 
uint8_t unset_nth_bit_uint8( uint8_t value, uint8_t n)
{
	if (n <= 8 && n >=0)
	{
		value &=~(1 << n);  
		return value;	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

int8_t unset_nth_bit_int8( int8_t value, uint8_t n)
{
	if (n <= 8 && n >=0)
	{
		value &=~(1 << n);  
		return value;	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

uint16_t unset_nth_bit_uint16( uint16_t value, uint8_t n)
{
	if (n <= 16 && n >=0)
	{
		value &=~(1 << n);  
		return value;	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

int16_t unset_nth_bit_int16( int16_t value, uint8_t n)
{
	if (n <= 16 && n >=0)
	{
		value &=~(1 << n);  
		return value;	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

//Toggle N th bit 
uint8_t toggle_nth_bit_uint8( uint8_t value, uint8_t n)
{
	if (n <= 8 && n >=0)
	{
		value ^= 1 << n; 
		return value ;	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

int8_t toggle_nth_bit_int8( int8_t value, uint8_t n)
{
	if (n <= 8 && n >=0)
	{
		value ^= 1 << n; 
		return value ;	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

uint16_t toggle_nth_bit_uint16( uint16_t value, uint8_t n)
{
	if (n <= 16 && n >=0)
	{
		value ^= 1 << n; 
		return value ;	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

int16_t toggle_nth_bit_int16( int16_t value, uint8_t n)
{
	if (n <= 16 && n >=0)
	{
		value ^= 1 << n; 
		return value ;	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

//Get N th bit
uint8_t get_nth_bit_uint8( uint8_t value, uint8_t n)
{
	if (n <= 8 && n >=0)
	{
		value = (value >> n) & 1; 
		return value ;	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

uint8_t get_nth_bit_int8( int8_t value, uint8_t n)
{
	if (n <= 8 && n >=0)
	{
		value = (value >> n) & 1; 
		return value ;	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

uint8_t get_nth_bit_uint16( uint16_t value, uint8_t n)
{
	if (n <= 16 && n >=0)
	{
		value = (value >> n) & 1; 
		return value ;	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

uint8_t get_nth_bit_int16( int16_t value, uint8_t n)
{
	if (n <= 16 && n >=0)
	{
		value = (value >> n) & 1; 
		return value ;	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}



//Change N th bit to x 
//number = (number & ~(1UL << n)) | (x << n);

uint8_t change_nth_bit_to_x_uint8( uint8_t value, uint8_t n, uint8_t x)
{
	if (n <= 8 && n >=0)
	{
		value = (value & ~(1 << n)) | (x << n);
		return value ;	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

int8_t change_nth_bit_to_x_int8( int8_t value, uint8_t n, uint8_t x)
{
	if (n <= 8 && n >=0)
	{
		value = (value & ~(1 << n)) | (x << n);
		return value ;	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

uint16_t change_nth_bit_to_x_uint16( uint16_t value, uint8_t n, uint8_t x)
{
	if (n <= 16 && n >=0)
	{
		value = (value & ~(1 << n)) | (x << n);
		return value ;	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

int16_t change_nth_bit_to_x_int16( int16_t value, uint8_t n, uint8_t x)
{
	if (n <= 16 && n >=0)
	{
		value = (value & ~(1 << n)) | (x << n);
		return value ;	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}




//GET N numer of least significant bits
uint8_t get_n_bits_lsb_uint8( uint8_t value, uint8_t bits)
{
	if (bits <= 8 && bits >=0)
	{
		return value & ((1 << bits)-1);	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

int8_t get_n_bits_lsb_int8(int8_t value, uint8_t bits)
{
	if (bits <= 8 && bits >=0)
	{
		return value & ((1 << bits)-1);	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

uint16_t get_n_bits_lsb_uint16( uint16_t value, uint8_t bits)
{
	if (bits <= 8 && bits >=0)
	{
		return value & ((1 << bits)-1);	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

int16_t get_n_bits_lsb_int16( int16_t value, uint8_t bits)
{
	if (bits <= 16 && bits >=0)
	{
		return value & ((1 << bits)-1);	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}


//Get N number of most signigiant bit.
uint8_t get_n_bits_msb_uint8( uint8_t value, uint8_t bits)
{
	if (bits <= 8 && bits >=0)
	{
		return value >> (8-bits);	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

int8_t get_n_bits_msb_int8(int8_t value, uint8_t bits)
{
	if (bits <= 8 && bits >=0)
	{
		return value >> (8-bits);	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

uint16_t get_n_bits_msb_uint16( uint16_t value, uint8_t bits)
{
	if (bits <= 16 && bits >=0)
	{
		return value >> (16-bits);	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

int16_t get_n_bits_msb_int16( int16_t value, uint8_t bits)
{
	if (bits <= 16 && bits >=0)
	{
		return value >> (16-bits);	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

// Get Bits range from startBit to stopBit and return them shifted.  


uint8_t get_bits_range_uint8( uint8_t value, uint8_t startBit, uint8_t stopBit)
{
	if (startBit <= 8 && bits >=0)
	{
		if(startBit <= 8 && bits >=0)
		{
			if(startBit < stopBit)
			{
				uint8_t mask = 0;
				uint8_t i = 0; 
				for(i = startBit; i <= stopBit; i++ )
        		{
                	mask |= (1 << i);
        		}
        		return (value & mask) >> startBit; 
			}
		}	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

int8_t get_bits_range_int8( int8_t value, uint8_t startBit, uint8_t stopBit)
{
	if (startBit <= 8 && bits >=0)
	{
		if(startBit <= 8 && bits >=0)
		{
			if(startBit < stopBit)
			{
				uint8_t mask = 0;
				uint8_t i = 0; 
				for(i = startBit; i <= stopBit; i++ )
        		{
                	mask |= (1 << i);
        		}
        		return (value & mask) >> startBit; 
			}
		}	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

uint16_t get_bits_range_uint16( uint16_t value, uint8_t startBit, uint8_t stopBit)
{
	if (startBit <= 16 && bits >=0)
	{
		if(startBit <= 16 && bits >=0)
		{
			if(startBit < stopBit)
			{
				uint8_t mask = 0;
				uint8_t i = 0; 
				for(i = startBit; i <= stopBit; i++ )
        		{
                	mask |= (1 << i);
        		}
        		return (value & mask) >> startBit; 
			}
		}	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}



int16_t get_bits_range_int16( int16_t value, uint8_t startBit, uint8_t stopBit)
{
	if (startBit <= 16 && bits >=0)
	{
		if(startBit <= 16 && bits >=0)
		{
			if(startBit < stopBit)
			{
				uint8_t mask = 0;
				uint8_t i = 0; 
				for(i = startBit; i <= stopBit; i++ )
        		{
                	mask |= (1 << i);
        		}
        		return (value & mask) >> startBit; 
			}
		}	
	}
	else 
	{
		return 0; 
	}
	return 0; 
}