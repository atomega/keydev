
uint8_t set_nth_bit_uint8( uint8_t value, uint8_t n); 
int8_t set_nth_bit_int8( int8_t value, uint8_t n); 
uint16_t set_nth_bit_uint16( uint16_t value, uint8_t n); 
int16_t set_nth_bit_int16( int16_t value, uint8_t n); 

uint8_t unset_nth_bit_uint8( uint8_t value, uint8_t n);
int8_t unset_nth_bit_int8( int8_t value, uint8_t n);
uint16_t unset_nth_bit_uint16( uint16_t value, uint8_t n);
int16_t unset_nth_bit_int16( int16_t value, uint8_t n);

uint8_t toggle_nth_bit_uint8( uint8_t value, uint8_t n); 
int8_t toggle_nth_bit_int8( int8_t value, uint8_t n); 
uint16_t toggle_nth_bit_uint16( uint16_t value, uint8_t n); 
int16_t toggle_nth_bit_int16( int16_t value, uint8_t n); 

uint8_t get_nth_bit_uint8( uint8_t value, uint8_t n); 
uint8_t get_nth_bit_int8( int8_t value, uint8_t n); 
uint8_t get_nth_bit_uint16( uint16_t value, uint8_t n); 
uint8_t get_nth_bit_int16( int16_t value, uint8_t n); 

uint8_t change_nth_bit_to_x_uint8( uint8_t value, uint8_t n, uint8_t x); 
int8_t change_nth_bit_to_x_int8( int8_t value, uint8_t n, uint8_t x); 
uint16_t change_nth_bit_to_x_uint16( uint16_t value, uint8_t n, uint8_t x); 
int16_t change_nth_bit_to_x_int16( int16_t value, uint8_t n, uint8_t x); 

uint8_t get_n_bits_lsb_uint8( uint8_t value, uint8_t bits); 
int8_t get_n_bits_lsb_int8(int8_t value, uint8_t bits); 
uint16_t get_n_bits_lsb_uint16( uint16_t value, uint8_t bits); 
int16_t get_n_bits_lsb_int16( int16_t value, uint8_t bits); 

uint8_t get_n_bits_msb_uint8( uint8_t value, uint8_t bits);
int8_t get_n_bits_msb_int8(int8_t value, uint8_t bits);
uint16_t get_n_bits_msb_uint16( uint16_t value, uint8_t bits);
int16_t get_n_bits_msb_int16( int16_t value, uint8_t bits);

uint8_t get_bits_range_uint8( uint8_t value, uint8_t startBit, uint8_t stopBit); 
int8_t get_bits_range_int8( int8_t value, uint8_t startBit, uint8_t stopBit); 
uint16_t get_bits_range_uint16( uint16_t value, uint8_t startBit, uint8_t stopBit); 
int16_t get_bits_range_int16( int16_t value, uint8_t startBit, uint8_t stopBit); 