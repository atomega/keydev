#include"../main.h"
#include"../i2c/i2c.h"
#include"../algorithms/bitgestion.h"
#include"ma12070.h"

int curretnVolume = 0; 

uint8_t Buffer = 0; 
S_MA12070 amp; 

uint8_t ma12070_init(void)
{
// Openning the i2c port for communication
i2c_open_device(0x2); 
return 1;
}

int16_t ma12070_getVolume(void)
{
uint8_t DbFraction = 0; 
uint8_t DbFractionTab[3] = {25,50,75}; 
uint8_t DbNumber = 0; 
 int16_t volume = 0; 

DbNumber = 23; 
// amp.vol_db_master = i2c_read_8(MA12070_REG_VOL_VA); 
 DbFraction = 3; 
// amp.vol_lsb_master = i2c_read_8(MA12070_REG_VOL_VAL_DE);

volume += (24 - DbNumber) * 100 - DbFractionTab[DbFraction-1];    

printf("Volume: %d\t", volum); 
return 1; 
}

void ma12070_printCurrentCconf(void)
{
	printf("\n\n\t CURRENT CONFIGURATION OF MA12070P \n\n");
	printf("power_mode = %d\n", amp.power_mode);
	printf("treshold_1to2 = %d\n", amp.treshold_1to2);
	printf("treshold_2to1 = %d\n", amp.treshold_2to1);
	printf("treshold_2to3 = %d\n", amp.treshold_2to3);
	printf("treshold_3to2 = %d\n", amp.treshold_3to2);
	printf("ifClampEn = %d\n", amp.ifClampEn);
	printf("ocpLatchEn = %d\n", amp.ocpLatchEn);
	printf("pmProfile = %d\n", amp.pmProfile);
	printf("pm3_man = %d\n", amp.pm3_man);
	printf("pm2_man = %d\n", amp.pm2_man);
	printf("pm1_man = %d\n", amp.pm1_man);
	printf("ocp_latch_clear = %d\n", amp.ocp_latch_clear);
	printf("audio_in_mode = %d\n", amp.audio_in_mode);
	printf("eh_dc_shndn = %d\n", amp.eh_dc_shndn);
	printf("audio_in_mode_ext = %d\n", amp.audio_in_mode_ext);
	printf("eh_clear = %d\n", amp.eh_clear);
	printf("i2s_format = %d\n", amp.i2s_format);
	printf("i2s_right_first = %d\n", amp.i2s_right_first);
	printf("i2s_frame_size = %d\n", amp.i2s_frame_size);
	printf("i2s_order = %d\n", amp.i2s_order);
	printf("i2s_ws_pol = %d\n", amp.i2s_ws_pol);
	printf("i2s_sck_pol = %d\n", amp.i2s_sck_pol);
	printf("audio_proc_release = %d\n", amp.audio_proc_release);
	printf("audio_proc_attack = %d\n", amp.audio_proc_attack);
	printf("audio_proc_enable = %d\n", amp.audio_proc_enable);
	printf("audio_proc_mute = %d\n", amp.audio_proc_mute);
	printf("audio_proc_limitter = %d\n", amp.audio_proc_limitter);
	printf("vol_db_master = %d\n", amp.vol_db_master);
	printf("vol_lsb_master = %d\n", amp.vol_lsb_master);
	printf("vol_db[0] = %d\n", amp.vol_db[0]);
	printf("vol_db[1] = %d\n", amp.vol_db[1]);
	printf("vol_db[2] = %d\n", amp.vol_db[2]);
	printf("vol_db[3] = %d\n", amp.vol_db[3]);
	printf("vol_lsb[0] = %d\n", amp.vol_lsb[0]);
	printf("vol_lsb[1] = %d\n", amp.vol_lsb[1]);
	printf("vol_lsb[2] = %d\n", amp.vol_lsb[2]);
	printf("vol_lsb[3] = %d\n", amp.vol_lsb[3]);
	printf("thr_db[0] = %d\n", amp.thr_db[0]);
	printf("thr_db[1] = %d\n", amp.thr_db[1]);
	printf("thr_db[2] = %d\n", amp.thr_db[2]);
	printf("thr_db[3] = %d\n", amp.thr_db[3]);
	printf("thr_lsb[0] = %d\n", amp.thr_lsb[0]);
	printf("thr_lsb[1] = %d\n", amp.thr_lsb[1]);
	printf("thr_lsb[2] = %d\n", amp.thr_lsb[2]);
	printf("thr_lsb[3]  = %d\n", amp.thr_lsb[3] );
	printf("audio_porc_limiter_mon = %d\n", amp.audio_porc_limiter_mon);
	printf("audio_proc_clip_mon = %d\n", amp.audio_proc_clip_mon);
	printf("dcu_frequency_mon[0] = %d\n", amp.dcu_frequency_mon[0]);
	printf("dcu_power_mode_mon[0] = %d\n", amp.dcu_power_mode_mon[0]);
	printf("dcu_frequency_mon[1] = %d\n", amp.dcu_frequency_mon[1]);
	printf("dcu_power_mode_mon[1] = %d\n", amp.dcu_power_mode_mon[1]);
	printf("dcu_mute_mon[0] = %d\n", amp.dcu_mute_mon[0]);
	printf("dcu_vdd_ok_mon[0] = %d\n", amp.dcu_vdd_ok_mon[0]);
	printf("dcu_pvdd_ok_mon[0] = %d\n", amp.dcu_pvdd_ok_mon[0]);
	printf("dcu_vcfly2_ok_mon[0] = %d\n", amp.dcu_vcfly2_ok_mon[0]);
	printf("dcu_vcfly1_ok_mon[0] = %d\n", amp.dcu_vcfly1_ok_mon[0]);
	printf("ocp_mon[0] = %d\n", amp.ocp_mon[0]);
	printf("dcu_mute_mon[1] = %d\n", amp.dcu_mute_mon[1]);
	printf("dcu_vdd_ok_mon[1] = %d\n", amp.dcu_vdd_ok_mon[1]);
	printf("dcu_pvdd_ok_mon[1] = %d\n", amp.dcu_pvdd_ok_mon[1]);
	printf("dcu_vcfly2_ok_mon[1] = %d\n", amp.dcu_vcfly2_ok_mon[1]);
	printf("dcu_vcfly1_ok_mon[1] = %d\n", amp.dcu_vcfly1_ok_mon[1]);
	printf("ocp_mon[1] = %d\n", amp.ocp_mon[1]);
	printf("dcu_modulation_mon[0] = %d\n", amp.dcu_modulation_mon[0]);
	printf("dcu_modulation_mon[1] = %d\n", amp.dcu_modulation_mon[1]);
	printf("error_acc = %d\n", amp.error_acc);
	printf("msel_mon = %d\n", amp.msel_mon);
	printf("error = %d\n", amp.error);
} 


void ma12070_getCurrentDevInfo(void)
{
Buffer = i2c_read_8(MA12070_REG_POWER_MODE_CONTRO);
amp.power_mode = get_bits_range_uint8(Buffer,4,); 

amp.treshold_1to2 = i2c_read_8(MA12070_REG_MTHR_1TO);
amp.treshold_2to1 = i2c_read_8(MA12070_REG_MTHR_2TO);
amp.treshold_2to3 = i2c_read_8(MA12070_REG_MTHR_2TO);
amp.treshold_3to2 = i2c_read_8(MA12070_REG_MTHR_3TO);

Buffer = i2c_read_8(MA12070_REG_SOFT_CILLIPN); 
amp.ifClampEn = get_nth_bit_uint8(Buffer,);
amp.ocpLatchEn = get_nth_bit_uint8(Buffer,);
 
Buffer = i2c_read_8(MA12070_REG_PM_PROFILE_MOD);
amp.pmProfile = get_n_bits_lsb_uint8(Buffer, ); 

Buffer = i2c_read_8(MA12070_REG_PM_PROFILE_CON);
amp.pm3_man = get_bits_range_uint8(Buffer,4,); 
amp.pm2_man = get_bits_range_uint8(Buffer,2,); 
amp.pm1_man = get_n_bits_lsb_uint8(Buffer,);  

Buffer = i2c_read_8(MA12070_REG_OVER_CURR_PRO);
amp.ocp_latch_clear =  get_nth_bit_uint8(Buffer,);

Buffer = i2c_read_8(MA12070_REG_AUDIO_IN_MOD);
amp.audio_in_mode = get_bits_range_uint8(Buffer,5,);
Buffer = i2c_read_8(MA12070_REG_DC_PROTECTIO);
amp.eh_dc_shndn = get_nth_bit_uint8(Buffer,);

Buffer = i2c_read_8(MA12070_REG_AUDI_IN_OVERWRIT);
amp.audio_in_mode_ext = get_nth_bit_uint8(Buffer,);

Buffer = i2c_read_8(MA12070_REG_ERROR_HANDLE);
amp.eh_clear = get_nth_bit_uint8(Buffer,);

Buffer = i2c_read_8(MA12070_REG_PCM_WORD_FORMA);
amp.i2s_format = get_n_bits_lsb_uint8(Buffer,);

Buffer = i2c_read_8(MA12070_REG_I2S_CONFI);
amp.i2s_right_first = get_nth_bit_uint8(Buffer,);
amp.i2s_frame_size = get_bits_range_uint8(Buffer,3,);
amp.i2s_order = get_nth_bit_uint8(Buffer,);
amp.i2s_ws_pol = get_nth_bit_uint8(Buffer,);
amp.i2s_sck_pol = get_nth_bit_uint8(Buffer,);

Buffer = i2c_read_8(MA12070_REG_PROCESSOR_SE);
amp.audio_proc_release = get_bits_range_uint8(Buffer,6,);
amp.audio_proc_attack = get_bits_range_uint8(Buffer,4,);
amp.audio_proc_enable = get_nth_bit_uint8(Buffer,);

Buffer = i2c_read_8(MA12070_REG_LIMITER_SE);
amp.audio_proc_mute = get_nth_bit_uint8(Buffer,);
amp.audio_proc_limitter = get_nth_bit_uint8(Buffer,);

amp.vol_db_master = i2c_read_8(MA12070_REG_VOL_DB_MASTE);

Buffer = i2c_read_8(MA12070_REG_VOL_LSB_MASTE);
amp.vol_lsb_master = get_n_bits_lsb_uint8(Buffer,);

amp.vol_db[0] = i2c_read_8(MA12070_REG_VOL_DB_CH);
amp.vol_db[1] = i2c_read_8(MA12070_REG_VOL_DB_CH);
amp.vol_db[2] = i2c_read_8(MA12070_REG_VOL_DB_CH);
amp.vol_db[3] = i2c_read_8(MA12070_REG_VOL_DB_CH);
Buffer = i2c_read_8(MA12070_REG_VOL_LSB_CH);
amp.vol_lsb[0] = get_n_bits_lsb_uint8(Buffer,);
amp.vol_lsb[1] = get_bits_range_uint8(Buffer,2,);
amp.vol_lsb[2] = get_bits_range_uint8(Buffer,4,);
amp.vol_lsb[3] = get_n_bits_msb_uint8(Buffer,);

amp.thr_db[0] = i2c_read_8(MA12070_REG_THR_DB_CH);
amp.thr_db[1] = i2c_read_8(MA12070_REG_THR_DB_CH);
amp.thr_db[2] = i2c_read_8(MA12070_REG_THR_DB_CH);
amp.thr_db[3] = i2c_read_8(MA12070_REG_THR_DB_CH);
Buffer = i2c_read_8(MA12070_REG_THR_LSB_CH);
amp.thr_lsb[0] = get_n_bits_lsb_uint8(Buffer,);
amp.thr_lsb[1] = get_bits_range_uint8(Buffer,2,);
amp.thr_lsb[2] = get_bits_range_uint8(Buffer,4,);
amp.thr_lsb[3] = get_n_bits_msb_uint8(Buffer,);

Buffer = i2c_read_8(MA12070_REG_LIMITER_STATU);
amp.audio_porc_limiter_mon = get_bits_range_uint8(Buffer,4,);
Buffer = i2c_read_8(MA12070_REG_CLIP_STAUT);
amp.audio_proc_clip_mon = get_n_bits_lsb_uint8(Buffer,);

Buffer = i2c_read_8(MA12070_REG_MON_CH0_FREQ_PO);
amp.dcu_frequency_mon[0] = get_bits_range_uint8(Buffer,4,);
amp.dcu_power_mode_mon[0] = get_n_bits_lsb_uint8(Buffer,);

Buffer = i2c_read_8(MA12070_REG_MON_CH1_FREQ_PO);
amp.dcu_frequency_mon[1] = get_bits_range_uint8(Buffer,4,);
amp.dcu_power_mode_mon[1] = get_n_bits_lsb_uint8(Buffer,);

Buffer = i2c_read_8(MA12070_REG_MON_CH);
amp.dcu_mute_mon[0] = get_nth_bit_uint8(Buffer,);
amp.dcu_vdd_ok_mon[0] = get_nth_bit_uint8(Buffer,);
amp.dcu_pvdd_ok_mon[0] = get_nth_bit_uint8(Buffer,);
amp.dcu_vcfly2_ok_mon[0] = get_nth_bit_uint8(Buffer,);
amp.dcu_vcfly1_ok_mon[0] = get_nth_bit_uint8(Buffer,);
amp.ocp_mon[0] = get_nth_bit_uint8(Buffer,);

Buffer = i2c_read_8(MA12070_REG_MON_CH);
amp.dcu_mute_mon[1] = get_nth_bit_uint8(Buffer,);
amp.dcu_vdd_ok_mon[1] = get_nth_bit_uint8(Buffer,);
amp.dcu_pvdd_ok_mon[1] = get_nth_bit_uint8(Buffer,);
amp.dcu_vcfly2_ok_mon[1] = get_nth_bit_uint8(Buffer,);
amp.dcu_vcfly1_ok_mon[1] = get_nth_bit_uint8(Buffer,);
amp.ocp_mon[1] = get_nth_bit_uint8(Buffer,);

amp.dcu_modulation_mon[0] = i2c_read_8(MA12070_REG_MON_CH0_MODU);
amp.dcu_modulation_mon[1] = i2c_read_8(MA12070_REG_MON_CH1_MODU);

amp.error_acc = i2c_read_8(MA12070_REG_ERRO_AC);

Buffer = i2c_read_8(MA12070_REG_MON_MSE);
amp.msel_mon = get_n_bits_lsb_uint8(Buffer,);

amp.error = i2c_read_8(MA12070_REG_ERRO);
}


uint8_t ma12070_setPowerMode(uint8_t mode)
{
Buffer = 0; //i2c_read_8(MA12070_REG_POWER_MODE_CONTRO);
  
switch(mode)
{
case MA12070_POWER_MODE_1:
 Buffer = set_nth_bit_uint8(Buffer,); 
 Buffer = unset_nth_bit_uint8(Buffer,); 
amp.power_mode = get_bits_range_uint8(Buffer,4,); 
i2c_write_16(MA12070_REG_POWER_MODE_CONTROL,Buffe); 
return 0; 

case MA12070_POWER_MODE_2: 
 Buffer = unset_nth_bit_uint8(Buffer,); 
 Buffer = set_nth_bit_uint8(Buffer,); 
amp.power_mode = get_bits_range_uint8(Buffer,4,); 
i2c_write_16(MA12070_REG_POWER_MODE_CONTROL,Buffe); 
return 0; 

case MA12070_POWER_MODE_3: 
 Buffer = set_nth_bit_uint8(Buffer,); 
 Buffer = set_nth_bit_uint8(Buffer,); 
amp.power_mode = get_bits_range_uint8(Buffer,4,); 
i2c_write_16(MA12070_REG_POWER_MODE_CONTROL,Buffe); 
return 0; 

case MA12070_POWER_MODE_MAN:
 Buffer = set_nth_bit_uint8(Buffer,); 
amp.power_mode = get_bits_range_uint8(Buffer,4,); 
i2c_write_16(MA12070_REG_POWER_MODE_CONTROL,Buffe); 
return 0; 

case MA12070_POWER_MODE_DEFF:
amp.power_mode = get_bits_range_uint8(Buffer,4,); 
i2c_write_16(MA12070_REG_POWER_MODE_CONTROL,Buffe); 
return 0; 

default: 
return 1; 
}
}


uint8_t ma12070_setVolume(int16_t volume)
{
int16_t DbBuff = 0; 
uint8_t DbFraction = 0; 
uint8_t DbNumber = 0; 
   
//printf("Volume: %d\t", volum); 

if (volume >= 0)
{
if( volume <= MA12070_VOL_MAX)
{
DbFraction = (char) get_n_bits_lsb_int16(volume,); 
DbBuff = (volume/10); 

if(DbFraction == 0)
{
DbBuff = (MA12070_VOL_MAX_DB) - DbBuff; 
}
else 
{
DbFraction = (DbFraction^3) + 1; 
DbBuff = (MA12070_VOL_MAX_DB) - DbBuff -1; 
}

DbNumber = (char)DbBuff; 
//printf("Bdnumber: %u\tfraction: %u \n",DbNumber, DbFractio); 


i2c_write_16(MA12070_REG_VOL_DB_MASTER, DbNumbe); 
i2c_write_16(MA12070_REG_VOL_LSB_MASTER, DbFractio); 

return 0; 
}
else 
{

return 1; 
}
return 1; 
} 
else
{
if(volume >= MA12070_VOL_MIN)
{
DbFraction = (char) get_n_bits_lsb_int16(volume,); 
DbBuff = (volume/10); 

if(DbFraction == 0)
{
DbBuff = abs(DbBuff) + 24;
}
else 
{ 
DbFraction = (DbFraction^3) + 1; 
DbBuff = abs(DbBuff) + 24 ;
}

DbNumber = (char)DbBuff; 
//printf("Bdnumber: %u\tfraction: %u \n",DbNumber, DbFractio);

i2c_write_16(MA12070_REG_VOL_DB_MASTER, DbNumbe); 
i2c_write_16(MA12070_REG_VOL_LSB_MASTER, DbFractio); 

return 0; 
}
else
{
return 1; 
}
}
}



uint8_t ma12070_configure(uint8_t Default)
{
//Set the device back to default setings
if(Default)
{
return 0; 
}
else 
{
return 0; 
}
return 1; 
}

