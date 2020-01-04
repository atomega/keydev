#define MA12070_ADDR 0x20 // Device Adress
 
#define MA12070_VOL_MAX 2400
#define MA12070_VOL_MIN -14400
#define MA12070_VOL_MAX_DB 24
#define MA12070_VOL_MIN_DB -144


#define MA12070_REG_POWER_MODE_CONTROL 0x00 
#define MA12070_DEF_POWER_MODE_CONTROL 0x3D 
#define MA12070_POWER_MODE_LSB 4
#define MA12070_POWER_MODE_MSB 5
#define MA12070_POWER_MODE_1 1
#define MA12070_POWER_MODE_2 2
#define MA12070_POWER_MODE_3 3
#define MA12070_POWER_MODE_MAN 4
#define MA12070_POWER_MODE_DEFF 5	

#define MA12070_REG_MTHR_1TO2 0x01 
#define MA12070_DEF_MTHR_1TO2 0x3C 

#define MA12070_REG_MTHR_2TO1 0x02 
#define MA12070_DEF_MTHR_2TO1 0x32 

#define MA12070_REG_MTHR_2TO3 0x03 
#define MA12070_DEF_MTHR_2TO3 0x5A 

#define MA12070_REG_MTHR_3TO2 0x04 
#define MA12070_DEF_MTHR_3TO2 0x50 

#define MA12070_REG_SOFT_CILLIPNG 0x0A 
#define MA12070_DEF_SOFT_CILLIPNG 0xC 

#define MA12070_REG_PM_PROFILE_MODE 0x1D
#define MA12070_POWER_PROFILE_0 1
#define MA12070_POWER_PROFILE_1 2
#define MA12070_POWER_PROFILE_2 3
#define MA12070_POWER_PROFILE_3 4
#define MA12070_POWER_PROFILE_4 5
#define MA12070_DEF_PM_PROFILE_MODE 0x00

#define MA12070_REG_PM_PROFILE_CONF 0x1E
#define	MA12070_POWER_SCHEME_CUSTOM 1 
#define	MA12070_POWER_SCHEME_A 2
#define	MA12070_POWER_SCHEME_B 3
#define	MA12070_POWER_SCHEME_C 4
#define	MA12070_POWER_SCHEME_D 5

#define MA12070_DEF_PM_PROFILE_CONF 0x2F

#define MA12070_REG_OVER_CURR_PROT 0x20 
#define MA12070_DEF_OVER_CURR_PROT 0x1F 

#define MA12070_REG_AUDIO_IN_MODE 0x25
#define MA12070_DEF_AUDIO_IN_MODE 0x10

#define MA12070_REG_DC_PROTECTION 0x26 
#define MA12070_DEF_DC_PROTECTION 0x05 

#define MA12070_REG_AUDI_IN_OVERWRITE 0x27
#define MA12070_DEF_AUDI_IN_OVERWRITE 0X08

#define MA12070_REG_ERROR_HANDLER 0x2D
#define MA12070_DEF_ERROR_HANDLER 0x30

#define MA12070_REG_PCM_WORD_FORMAT 0x35
#define MA12070_DEF_PCM_WORD_FORMAT 0x01

#define MA12070_REG_I2S_CONFIG 0x36
#define MA12070_DEF_I2S_CONFIG 0x01

#define MA12070_REG_PROCESSOR_SET 0x35
#define MA12070_DEF_PROCESSOR_SET 0x01

#define MA12070_REG_LIMITER_SET 0x36
#define MA12070_DEF_LIMITER_SET 0x01

#define MA12070_REG_VOL_DB_MASTER 0x40
#define MA12070_DEF_VOL_DB_MASTER 0x18

#define MA12070_REG_VOL_LSB_MASTER 0x41
#define MA12070_DEF_VOL_LSB_MASTER 0x00

#define MA12070_REG_VOL_DB_CH0 0x42
#define MA12070_DEF_VOL_DB_CH0 0x18

#define MA12070_REG_VOL_DB_CH1 0x43
#define MA12070_DEF_VOL_DB_CH1 0x18

#define MA12070_REG_VOL_DB_CH2 0x44
#define MA12070_DEF_VOL_DB_CH2 0x18

#define MA12070_REG_VOL_DB_CH3 0x45
#define MA12070_DEF_VOL_DB_CH3 0x18

#define MA12070_REG_VOL_LSB_CHX 0x46
#define MA12070_DEF_VOL_LSB_CHX 0x00

#define MA12070_REG_THR_DB_CH0 0x47
#define MA12070_DEF_THR_DB_CH0 0x18

#define MA12070_REG_THR_DB_CH1 0x48
#define MA12070_DEF_THR_DB_CH1 0x18

#define MA12070_REG_THR_DB_CH2 0x49
#define MA12070_DEF_THR_DB_CH2 0x18

#define MA12070_REG_THR_DB_CH3 0x4A
#define MA12070_DEF_THR_DB_CH3 0x18

#define MA12070_REG_THR_LSB_CHX 0x4B
#define MA12070_DEF_THR_LSB_CHX 0x00

#define MA12070_REG_LIMITER_STATUS 0x7E
#define MA12070_DEF_LIMITER_STATUS 0x00 

#define MA12070_REG_CLIP_STAUTS 0x7E
#define MA12070_DEF_CLIP_STAUTS 0x00

#define MA12070_REG_MON_CH0_FREQ_POW 0x60
#define MA12070_DEF_MON_CH0_FREQ_POW 0x00

#define MA12070_REG_MON_CH0 0x61
#define MA12070_DEF_MON_CH0 0x00

#define MA12070_REG_MON_CH0_MODUL 0x62
#define MA12070_DEF_MON_CH0_MODUL 0x00

#define MA12070_REG_MON_CH1_FREQ_POW 0x64
#define MA12070_DEF_MON_CH1_FREQ_POW 0x00

#define MA12070_REG_MON_CH1 0x65
#define MA12070_DEF_MON_CH1 0x00

#define MA12070_REG_MON_CH1_MODUL 0x66
#define MA12070_DEF_MON_CH1_MODUL 0x00

#define MA12070_REG_ERRO_ACC 0x6D
#define MA12070_DEF_ERRO_ACC 0x00

#define MA12070_REG_MON_MSEL 0x75
#define MA12070_DEF_MON_MSEL 0x00

#define MA12070_REG_ERROR 0x7C
#define MA12070_DEF_ERROR 0x00


typedef struct MA12070 
{
	uint8_t power_mode;
	uint8_t treshold_1to2; 
	uint8_t treshold_2to1;
	uint8_t treshold_2to3;
	uint8_t treshold_3to2;
	uint8_t ifClampEn; 
	uint8_t ocpLatchEn; 
	uint8_t pmProfile; 
	uint8_t pm3_man; 
	uint8_t pm2_man; 
	uint8_t pm1_man;
	uint8_t ocp_latch_clear;
	uint8_t audio_in_mode;
	uint8_t eh_dc_shndn;
	uint8_t audio_in_mode_ext;
	uint8_t eh_clear;
	uint8_t i2s_format;
	uint8_t i2s_right_first;
	uint8_t i2s_frame_size;
	uint8_t i2s_order;
	uint8_t i2s_ws_pol;
	uint8_t i2s_sck_pol;
	uint8_t audio_proc_release;
	uint8_t audio_proc_attack;
	uint8_t audio_proc_enable;
	uint8_t audio_proc_mute;
	uint8_t audio_proc_limitter;
	uint8_t vol_db_master;
	uint8_t vol_lsb_master;
	uint8_t vol_db[3];
	uint8_t vol_lsb[3];
	uint8_t thr_db[3];
	uint8_t thr_lsb[3];
	uint8_t audio_porc_limiter_mon;
	uint8_t audio_proc_clip_mon;
	uint8_t dcu_frequency_mon[2];
	uint8_t dcu_power_mode_mon[2];
	uint8_t dcu_mute_mon[2];
	uint8_t dcu_vdd_ok_mon[2];
	uint8_t dcu_pvdd_ok_mon[2];
	uint8_t dcu_vcfly1_ok_mon[2];
	uint8_t dcu_vcfly2_ok_mon[2];
	uint8_t ocp_mon[2];
	uint8_t dcu_modulation_mon[2];
	uint8_t error_acc;
	uint8_t msel_mon;
	uint8_t error;
} S_MA12070;


uint8_t ma12070_setVolume(int16_t volume); 
uint8_t ma12070_init(void); 
uint8_t ma12070_configure(uint8_t Default);
int16_t ma12070_getVolume(void); 

uint8_t ma12070_setPowerMode(uint8_t mode); 
void ma12070_getCurrentDevInfo(void); 
uint8_t ma12070_setTreshold(uint8_t channel, uint8_t value);