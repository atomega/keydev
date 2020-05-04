
void set_bits_range_uint16(uint16_t *value, uint8_t &startBit, uint8_t &stopBit, uint16_t &replace);
void set_bits_range_uint8(uint8_t *value, uint8_t &startBit, uint8_t &stopBit, uint8_t &replace);

void throwError( uint16_t error);

void set_nth_bit_uint8( uint8_t *value, uint8_t &n); 
void set_nth_bit_int8( int8_t *value, uint8_t &n); 
void set_nth_bit_uint16( uint16_t *value, uint8_t &n); 
void set_nth_bit_int16( int16_t *value, uint8_t &n); 

void unset_nth_bit_uint8( uint8_t *value, uint8_t &n);
void unset_nth_bit_int8( int8_t *value, uint8_t &n);
void unset_nth_bit_uint16( uint16_t *value, uint8_t &n);
void unset_nth_bit_int16( int16_t *value, uint8_t &n);

void toggle_nth_bit_uint8( uint8_t *value, uint8_t &n); 
void toggle_nth_bit_int8( int8_t *value, uint8_t &n); 
void toggle_nth_bit_uint16( uint16_t *value, uint8_t &n); 
void toggle_nth_bit_int16( int16_t *value, uint8_t &n); 

void get_nth_bit_uint8( uint8_t *value, uint8_t &n); 
void get_nth_bit_int8( int8_t *value, uint8_t &n); 
void get_nth_bit_uint16( uint16_t *value, uint8_t &n); 
void get_nth_bit_int16( int16_t *value, uint8_t &n); 

void change_nth_bit_to_x_uint8( uint8_t *value, uint8_t &n, uint8_t &x); 
void change_nth_bit_to_x_int8( int8_t *value, uint8_t &n, uint8_t &x); 
void change_nth_bit_to_x_uint16( uint16_t *value, uint8_t &n, uint8_t &x); 
void change_nth_bit_to_x_int16( int16_t *value, uint8_t &n, uint8_t &x); 

void get_n_bits_lsb_uint8( uint8_t *value, uint8_t &bits); 
void get_n_bits_lsb_int8(int8_t *value, uint8_t &bits); 
void get_n_bits_lsb_uint16( uint16_t *value, uint8_t &bits); 
void get_n_bits_lsb_int16( int16_t *value, uint8_t &bits); 

void get_n_bits_msb_uint8( uint8_t *value, uint8_t &bits);
void get_n_bits_msb_int8(int8_t *value, uint8_t &bits);
void get_n_bits_msb_uint16( uint16_t *value, uint8_t &bits);
void get_n_bits_msb_int16( int16_t *value, uint8_t &bits);

void get_bits_range_uint8( uint8_t *value, uint8_t &startBit, uint8_t &stopBit); 
void get_bits_range_int8( int8_t *value, uint8_t &startBit, uint8_t &stopBit); 
void get_bits_range_uint16( uint16_t *value, uint8_t &startBit, uint8_t &stopBit); 
void get_bits_range_int16( int16_t *value, uint8_t &startBit, uint8_t &stopBit); 
