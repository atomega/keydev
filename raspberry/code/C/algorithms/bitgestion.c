#include "../main.h"
#include"bitgestion.h"
 
//Get N numer of least significant bits
uint8_t glnb_uint8( uint8_t value, uint8_t bits)
{
	if (bits <= 8 && bits >=0)
	{
		return value & ((1 << bits)-1);	
	}
	else 
	{
		return 0; 
	}
}

uint8_t glnb_int8(int8_t value, uint8_t bits)
{
	if (bits <= 8 && bits >=0)
	{
		return value & ((1 << bits)-1);	
	}
	else 
	{
		return 0; 
	}
}

uint16_t glnb_uint16( uint16_t value, uint8_t bits)
{
	if (bits <= 16 && bits >=0)
	{
		return value & ((1 << bits)-1);	
	}
	else 
	{
		return 0; 
	}
}

int16_t glnb_int16( int16_t value, uint8_t bits)
{
	if (bits <= 16 && bits >=0)
	{
		return value & ((1 << bits)-1);	
	}
	else 
	{
		return 0; 
	}
}


//Get N number of most signigiant bit.
uint8_t gmnb_uint8( uint8_t value, uint8_t bits)
{
	if (bits <= 8 && bits >=0)
	{
		return value >> (8-bits);	
	}
	else 
	{
		return 0; 
	}
}

uint8_t gmnb_int8(int8_t value, uint8_t bits)
{
	if (bits <= 8 && bits >=0)
	{
		return value >> (8-bits);	
	}
	else 
	{
		return 0; 
	}
}

uint16_t gmnb_uint16( uint16_t value, uint8_t bits)
{
	if (bits <= 16 && bits >=0)
	{
		return value >> (16-bits);	
	}
	else 
	{
		return 0; 
	}
}

int16_t gmnb_int16( int16_t value, uint8_t bits)
{
	if (bits <= 16 && bits >=0)
	{
		return value >> (16-bits);	
	}
	else 
	{
		return 0; 
	}
}
