#include <stdio.h>
#include <stdlib.h>     /* abs */
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include"../../lowlayer/i2c/ll_i2c.h"
#include"../../../c/algorithms/bitgestion.h"

#define MA_ADDR 0x20 // Device Adress
#define STRSIZE 30


//--------------------------------------------------------------- POWER MODE CONTROL
#define MA_IND_PWR_MODE_CTRL 0
#define MA_REG_PWR_MODE_CTRL 0x00 
#define MA_DEF_PWR_MODE_CTRL 0x3D 
#define MA_SHIFT_PWR_MODE_MAN 0x06
#define MA_MSK_PWR_MODE_MAN 0x40
#define MA_LEN_PWR_MODE_MAN 1

#define MA_SHIFT_PWR_MODE_SEL 0x04
#define MA_MSK_PWR_MODE_SEL 0x30
#define MA_LEN_PWR_MODE_SEL 2
#define MA_PWR_MODE_1 1
#define MA_PWR_MODE_2 2
#define MA_PWR_MODE_3 3
#define MA_PWR_MODE_MAN 4
#define MA_PWR_MODE_AUTO 5
#define MA_PWR_MODE_DEFF 6

//--------------------------------------------------------------- THRESHOLD FOR POWER MODE CHANGES
#define MA_IND_MTHR_1TO2 1
#define MA_REG_MTHR_1TO2 0x01
#define MA_DEF_MTHR_1TO2 0x3C
#define MA_SHIFT_MTHR_1TO2 0x00
#define MA_MSK_MTHR_1TO2 0xFF
#define MA_LEN_MTHR_1TO2 8

#define MA_IND_MTHR_2TO1 2
#define MA_REG_MTHR_2TO1 0x02 
#define MA_DEF_MTHR_2TO1 0x32 
#define MA_SHIFT_MTHR_2TO1 0x00
#define MA_MSK_MTHR_2TO1 0xFF
#define MA_LEN_MTHR_2TO1 8

#define MA_IND_MTHR_2TO3 3
#define MA_REG_MTHR_2TO3 0x03 
#define MA_DEF_MTHR_2TO3 0x5A 
#define MA_SHIFT_MTHR_2TO3 0x00
#define MA_MSK_MTHR_2TO3 0xFF
#define MA_LEN_MTHR_2TO3 8

#define MA_IND_MTHR_3TO2 4
#define MA_REG_MTHR_3TO2 0x04 
#define MA_DEF_MTHR_3TO2 0x50 
#define MA_SHIFT_MTHR_3TO2 0x00
#define MA_MSK_MTHR_3TO2 0xFF
#define MA_LEN_MTHR_3TO2 8

#define MA_MTHR_1TO2 1
#define MA_MTHR_2TO1 2
#define MA_MTHR_2TO3 3
#define MA_MTHR_3TO2 4

//--------------------------------------------------------------- SOFT CLIPPING OND OVECURRENT PTOTECTION
// SOFT CLIPPING AND OVECURRENT PROTECHTION LATCH
// HIGH (DEFAULT) TO ENABLE LF INT2+3 CLAMPING ON CLIP
// HIGH TO USE PERMANENTLY LATCHING LEVEL-2 OCP
#define MA_IND_LATCH_CLAMP 5
#define MA_REG_LATCH_CLAMP 0x0A 
#define MA_DEF_LATCH_CLAMP 0xC 
#define MA_SHIFT_SOFT_CLAMP 0x07	
#define MA_MSK_SOFT_CLAMP 0x80
#define MA_LEN_SOFT_CLAMP 1
#define MA_SHIFT_OCP_LATCH 0x01 	
#define MA_MSK_OCP_LATCH 0x02
#define MA_LEN_OCP_LATCH 1
#define MA_LATCH_CLAMP 0x00 
#define MA_CLIPPING_EN 0x1 

//--------------------------------------------------------------- SELECT POWER MODE PROFILE SETTINGS
// PM PROFILE SELECT. VALID PRESETS: 0-1-2-3-4. 5=> CUSTOM PROFILE.
#define MA_IND_PM_PROFILE_MODE 6 
#define MA_REG_PM_PROFILE_MODE 0x1D
#define MA_DEF_PM_PROFILE_MODE 0x00
#define MA_SHIFT_PM_PROFILE_MODE 0x00
#define MA_MSK_PM_PROFILE_MODE 0x07
#define MA_LEN_PM_PROFILE_MODE 3
#define MA_POWER_PROFILE_0 0
#define MA_POWER_PROFILE_1 1
#define MA_POWER_PROFILE_2 2
#define MA_POWER_PROFILE_3 3
#define MA_POWER_PROFILE_4 4

//--------------------------------------------------------------- POWER MODE PROFILE CONFIGURATION
// CUSTOM PROFILE PM3 CONTENTS. 0=>A,  1=>B,  2=>C,  3=>D
#define MA_IND_PM_PROFILE_CONF 7
#define MA_REG_PM_PROFILE_CONF 0x1E
#define MA_DEF_PM_PROFILE_CONF 0x2F

#define MA_SHIFT_PM_PROFILE_PM3 0x04
#define MA_MSK_PM_PROFILE_PM3 0x30
#define MA_LEN_PM_PROFILE_PM3 2

#define MA_SHIFT_PM_PROFILE_PM2 0x02
#define MA_MSK_PM_PROFILE_PM2 0x0C
#define MA_LEN_PM_PROFILE_PM2 2

#define MA_SHIFT_PM_PROFILE_PM1 0x00
#define MA_MSK_PM_PROFILE_PM1 0x03
#define MA_LEN_PM_PROFILE_PM1 2

#define	MA_PM_MODE_1 2
#define	MA_PM_MODE_2 3
#define	MA_PM_MODE_3 4

#define	MA_POWER_SCHEME_A 0
#define	MA_POWER_SCHEME_B 1
#define	MA_POWER_SCHEME_C 2
#define	MA_POWER_SCHEME_D 3
#define MA_POWER_SCHEME_CUSTOM 6

//--------------------------------------------------------------- OVER CURRENT PROTECTION LATCH CLEAR
#define MA_IND_OCP_LATCH_CLEAR 8
#define MA_REG_OCP_LATCH_CLEAR 0x20 
#define MA_DEF_OCP_LATCH_CLEAR 0x1F 
#define MA_SHIFT_OCP_LATCH_CLEAR 0x07
#define MA_MSK_OCP_LATCH_CLEAR 0x80
#define MA_LEN_OCP_LATCH_CLEAR 1
//--------------------------------------------------------------- AUDIO IN MODE
//HIGH 26 DB GAIN
//LOW 20 B GAIN
#define MA_IND_AUDIO_IN_MODE 9
#define MA_REG_AUDIO_IN_MODE 0x25
#define MA_DEF_AUDIO_IN_MODE 0x10
#define MA_SHIFT_AUDIO_IN_MODE 0x05
#define MA_MSK_AUDIO_IN_MODE 0x60
#define MA_LEN_AUDIO_IN_MODE 2
#define MA_AUDIO_IN_MODE_0 0 
#define MA_AUDIO_IN_MODE_1 1
#define MA_AUDIO_IN_MODE_DEFF 2
//--------------------------------------------------------------- ENABLE DC PROTECTION
#define MA_IND_DC_PROTECTION 10
#define MA_REG_DC_PROTECTION 0x26 
#define MA_DEF_DC_PROTECTION 0x05 
#define MA_SHIFT_DC_PROTECTION 0x02
#define MA_MSK_DC_PROTECTION 0x04
#define MA_LEN_DC_PROTECTION 1
//--------------------------------------------------------------- AUDIO IN MODE OVERWRITE
// IF SET,  AUDIO_IN_MODE IS CONTROLLED FROM AUDIO_IN_MODE REGISTER. IF NOT SET
//AUDIO_IN_MODE IS SET FROM FUSE BANK SETTING
#define MA_IND_AUDIO_IN_OVERWRITE 11
#define MA_REG_AUDIO_IN_OVERWRITE 0x27
#define MA_DEF_AUDIO_IN_OVERWRITE 0x08
#define MA_SHIFT_AUDIO_IN_OVERWRITE 0x05
#define MA_MSK_AUDI_IN_OVERWRITE 0x20
#define MA_LEN_AUDI_IN_OVERWRITE 1
//--------------------------------------------------------------- ERROR HANDLER CLEAR
#define MA_IND_ERROR_HANDLER 12
#define MA_REG_ERROR_HANDLER 0x2D
#define MA_DEF_ERROR_HANDLER 0x30
#define MA_SHIFT_ERROR_HANDLER 0x02
#define MA_MSK_ERROR_HANDLER 0x04
#define MA_LEN_ERROR_HANDLER 1
//--------------------------------------------------------------- AUDIO PROCESSOR AND WORD FORMAT
#define MA_IND_PCM_PROC_SET 13
#define MA_REG_PCM_PROC_SET 0x35
#define MA_DEF_PCM_PROC_SET 0x01
// 00:SLOW,  01:NORMAL,  10:FAST
#define MA_SHIFT_PROC_ATTACK 0x06
#define MA_MSK_PROC_ATTACK 0xC0
#define MA_LEN_PROC_ATTACK 2
// 00:SLOW,  01:NORMAL,  10:FAST
#define MA_SHIFT_PROC_RELEASE 0x04
#define MA_MSK_PROC_RELEASE 0x30
#define MA_LEN_PROC_RELEASE 2
// ENABLE AUDIO PROC,  BYPASS IF NOT ENABLED
#define MA_SHIFT_PROC_ENABLE 0x03
#define MA_MSK_PROC_ENABLE 0x08
#define MA_LEN_PROC_ENABLE 1

#define MA_SHIFT_PCM_WORD_FORMAT 0x00
#define MA_MSK_PCM_WORD_FORMAT 0x07
#define MA_LEN_PCM_WORD_FORMAT 3

#define MA_I2S_STANDART 0
#define MA_I2S_LEFT_JUSTIFIED 1
#define MA_I2S_RIGHT_JUSTIFIED_16b 4
#define MA_I2S_RIGHT_JUSTIFIED_18b 6
#define MA_I2S_RIGHT_JUSTIFIED_20b 5
#define MA_I2S_RIGHT_JUSTIFIED_24b 7

#define MA_ATT_REL_FAST 2
#define MA_ATT_REL_NORMAL 1
#define MA_ATT_REL_SLOW 0

//---------------------------------------------------------------  I2S CONTROL & MUTE + BYPASS 
#define MA_IND_I2S_CONFIG 14
#define MA_REG_I2S_CONFIG 0x36
#define MA_DEF_I2S_CONFIG 0x01
// I2S L/R WORD ORDER. 0 = LEFT FIRST
#define MA_SHIFT_I2S_RIGHT_FIRST 0x05
#define MA_MSK_I2S_RIGHT_FIRST 0x20
#define MA_LEN_I2S_RIGHT_FIRST 1
// I2S WORD LENGTH. 0 = 32BIT,  1 = 24BIT
#define MA_SHIFT_I2S_FRAME_SIZE 0x03
#define MA_MSK_I2S_FRAME_SIZE 0x18
#define MA_LEN_I2S_FRAME_SIZE 2
// I2S WORD BIT ORDER. 0 = MSB FIRST
#define MA_SHIFT_I2S_ORDER 0x02
#define MA_MSK_I2S_ORDER 0x04
#define MA_LEN_I2S_ORDER 1
// I2S WS POLARITY. 0 = LOW FIRST
#define MA_SHIFT_I2S_WS_POL 0x01
#define MA_MSK_I2S_WS_POL 0x02 
#define MA_LEN_I2S_WS_POL 1
// I2S SCK POLARITY CFG. 0 = RISING EDGE DATA CHANGE
#define MA_SHIFT_I2S_SCK_POL 0x00
#define MA_MSK_I2S_SCK_POL 0x01 
#define MA_LEN_I2S_SCK_POL 1 
// 1 = MUTE
#define MA_SHIFT_MUTE_EN 0x07
#define MA_MSK_MUTE_EN 0x80
#define MA_LEN_MUTE_EN 1
// 1 = BYPASS
#define MA_SHIFT_LIMITER_EN 0x06
#define MA_MSK_LIMITER_EN 0x40
#define MA_LEN_LIMITER_EN 1

#define I2S_SCK_POL_RISING 0
#define I2S_SCK_POL_FALLING 1

#define I2S_WS_POL_HIGH 1
#define I2S_WS_POL_LOW 0
//--------------------------------------------------------------- MASTER INTEGER VOLUME dB
#define MA_IND_VOL_DB_MASTER 15
#define MA_REG_VOL_DB_MASTER 0x40
#define MA_DEF_VOL_DB_MASTER 0x18
#define MA_SHIFT_VOL_DB_MASTER 0x00
#define MA_MSK_VOL_DB_MASTER 0xFF
#define MA_LEN_VOL_DB_MASTER 8
//--------------------------------------------------------------- MASTER FRACTION VOLUME dB 1/4
#define MA_IND_VOL_LSB_MASTER 16
#define MA_REG_VOL_LSB_MASTER 0x41
#define MA_DEF_VOL_LSB_MASTER 0x00
#define MA_SHIFT_VOL_LSB_MASTER 0x00
#define MA_MSK_VOL_LSB_MASTER 0x03
#define MA_LEN_VOL_LSB_MASTER 2
//--------------------------------------------------------------- CH0L INTEGER VOLUME dB
#define MA_IND_VOL_DB_CH0 17
#define MA_REG_VOL_DB_CH0 0x42
#define MA_DEF_VOL_DB_CH0 0x18
#define MA_SHIFT_VOL_DB_CH0 0x00
#define MA_MSK_VOL_DB_CH0 0xFF
#define MA_LEN_VOL_DB_CH0 8
//--------------------------------------------------------------- CH0R INTEGER VOLUME dB
#define MA_IND_VOL_DB_CH1 18
#define MA_REG_VOL_DB_CH1 0x43
#define MA_DEF_VOL_DB_CH1 0x18
#define MA_SHIFT_VOL_DB_CH1 0x00
#define MA_MSK_VOL_DB_CH1 0xFF
#define MA_LEN_VOL_DB_CH1 8
//--------------------------------------------------------------- CH1L INTEGER VOLUME dB
#define MA_IND_VOL_DB_CH2 19
#define MA_REG_VOL_DB_CH2 0x44
#define MA_DEF_VOL_DB_CH2 0x18
#define MA_SHIFT_VOL_DB_CH2 0x00
#define MA_MSK_VOL_DB_CH2 0xFF
#define MA_LEN_VOL_DB_CH2 8
//--------------------------------------------------------------- CH1R INTEGER VOLUME dB
#define MA_IND_VOL_DB_CH3 20
#define MA_REG_VOL_DB_CH3 0x45
#define MA_DEF_VOL_DB_CH3 0x18
#define MA_SHIFT_VOL_DB_CH3 0x00
#define MA_MSK_VOL_DB_CH3 0xFF
#define MA_LEN_VOL_DB_CH3 8
//--------------------------------------------------------------- CHX FRACTION VOLUME dB 1/4
#define MA_IND_VOL_LSB_CHX 21
#define MA_REG_VOL_LSB_CHX 0x46
#define MA_DEF_VOL_LSB_CHX 0x00

#define MA_SHIFT_VOL_LSB_CH0 0x00
#define MA_MSK_VOL_LSB_CH0 0x03
#define MA_LEN_VOL_LSB_CH0 2

#define MA_SHIFT_VOL_LSB_CH1 0x02
#define MA_MSK_VOL_LSB_CH1 0x0C
#define MA_LEN_VOL_LSB_CH1 2

#define MA_SHIFT_VOL_LSB_CH2 0x04
#define MA_MSK_VOL_LSB_CH2 0x30
#define MA_LEN_VOL_LSB_CH2 2

#define MA_SHIFT_VOL_LSB_CH3 0x06
#define MA_MSK_VOL_LSB_CH3 0xC0
#define MA_LEN_VOL_LSB_CH3 2
//--------------------------------------------------------------- CH0L INTEGER LIMITER THRESHOLD dB
#define MA_IND_THR_DB_CH0 22
#define MA_REG_THR_DB_CH0 0x47
#define MA_DEF_THR_DB_CH0 0x18
#define MA_SHIFT_THR_DB_CH0 0x00
#define MA_MSK_THR_DB_CH0 0xFF
#define MA_LEN_THR_DB_CH0 8
//--------------------------------------------------------------- CH0R INTEGER LIMITER THRESHOLD dB
#define MA_IND_THR_DB_CH1 23
#define MA_REG_THR_DB_CH1 0x48
#define MA_DEF_THR_DB_CH1 0x18
#define MA_SHIFT_THR_DB_CH1 0x00
#define MA_MSK_THR_DB_CH1 0xFF
#define MA_LEN_THR_DB_CH1 8
//--------------------------------------------------------------- CH1L INTEGER LIMITER THRESHOLD dB
#define MA_IND_THR_DB_CH2 24
#define MA_REG_THR_DB_CH2 0x49
#define MA_DEF_THR_DB_CH2 0x18
#define MA_SHIFT_THR_DB_CH2 0x00
#define MA_MSK_THR_DB_CH2 0xFF
#define MA_LEN_THR_DB_CH2 8
//--------------------------------------------------------------- CH1R INTEGER LIMITER THRESHOLD dB
#define MA_IND_THR_DB_CH3 25
#define MA_REG_THR_DB_CH3 0x4A
#define MA_DEF_THR_DB_CH3 0x18
#define MA_SHIFT_THR_DB_CH3 0x00
#define MA_MSK_THR_DB_CH3 0xFF
#define MA_LEN_THR_DB_CH3 8
//--------------------------------------------------------------- CHX FRACTION LIMITER THRESHOLD dB 1/4
#define MA_IND_THR_LSB_CHX 26
#define MA_REG_THR_LSB_CHX 0x4B
#define MA_DEF_THR_LSB_CHX 0x00

#define MA_SHIFT_THR_LSB_CH0 0x00
#define MA_MSK_THR_LSB_CH0 0x03
#define MA_LEN_THR_LSB_CH0 2

#define MA_SHIFT_THR_LSB_CH1 0x02
#define MA_MSK_THR_LSB_CH1 0x0C
#define MA_LEN_THR_LSB_CH1 2

#define MA_SHIFT_THR_LSB_CH2 0x04
#define MA_MSK_THR_LSB_CH2 0x30
#define MA_LEN_THR_LSB_CH2 2

#define MA_SHIFT_THR_LSB_CH3 0x06
#define MA_MSK_THR_LSB_CH3 0xC0
#define MA_LEN_THR_LSB_CH3 2

//--------------------------------------------------------------- POWER MODE AN FREQUENCY MONITOR CHANNEL 0
#define MA_IND_MON0_FREQ_PM 27
#define MA_REG_MON0_FREQ_PM 0x60
#define MA_DEF_MON0_FREQ_PM 0x00
//MONITOR FREQUNBCY OF CHANNEL 0
#define MA_SHIFT_MON0_FREQ 0x04 
#define MA_MSK_MON0_FREQ 0x70
#define MA_LEN_MON0_FREQ 3
// MONITOR THE POWER MODE OF CHANNEL 0
#define MA_SHIFT_MON0_PM 0x00
#define MA_MSK_MON0_PM 0x03
#define MA_LEN_MON0_PM 2

//--------------------------------------------------------------- MONITOR CHANNEL 0
#define MA_IND_MON0 28
#define MA_REG_MON0 0x61
#define MA_DEF_MON0 0x00
// DCU0 MUTE MONITOR
#define MA_SHIFT_MON0_MUTE 0x05
#define MA_MSK_MON0_MUTE 0x20
#define MA_LEN_MON0_MUTE 1
// DCU0 VDD MONITOR
#define MA_SHIFT_MON0_VDD_OK 0x04
#define MA_MSK_MON0_VDD_OK 0x10
#define MA_LEN_MON0_VDD_OK 1
// DCU0 PVDD MONITOR
#define MA_SHIFT_MON0_PVDD_OK 0x03
#define MA_MSK_MON0_PVDD_OK 0x08
#define MA_LEN_MON0_PVDD_OK 1
// CFLY2 PROTECTION MONITOR CHANNEL 0.
#define MA_SHIFT_MON0VCFLY2_OK 0x02
#define MA_MSK_MON0VCFLY2_OK 0x04
#define MA_LEN_MON0VCFLY2_OK 1
// CFLY1 PROTECTION MONITOR CHANNEL 0.
#define MA_SHIFT_MON0_VCFPLY1_OK 0x01
#define MA_MSK_MON0_VCFPLY1_OK 0x02
#define MA_LEN_MON0_VCFPLY1_OK 1
// OCP MONITOR CHANNEL 0
#define MA_SHIFT_MON0_OCP 0x00
#define MA_MSK_MON0_OCP 0x01
#define MA_LEN_MON0_OCP 1

//--------------------------------------------------------------- MONITOR CHANNEL 0 MODULATION INDEX
#define MA_IND_MON0_MODUL 29
#define MA_REG_MON0_MODUL 0x62
#define MA_DEF_MON0_MODUL 0x00
#define MA_SHIFT_MON0_MODUL 0x00
#define MA_MSK_MON0_MODUL 0xFF
#define MA_LEN_MON0_MODUL 8

//--------------------------------------------------------------- POWER MODE AN FREQUENCY MONITOR CHANNEL 1
#define MA_IND_MON1_FREQ_PM 30
#define MA_REG_MON1_FREQ_PM 0x64
#define MA_DEF_MON1_FREQ_PM 0x00
//MONITOR FREQUNBCY OF CHANNEL 1
#define MA_SHIFT_MON1_FREQ 0x04 
#define MA_MSK_MON1_FREQ 0x70
#define MA_LEN_MON1_FREQ 3
// MONITOR THE POWER MODE OF CHANNEL 1
#define MA_SHIFT_MON1_PM 0x00
#define MA_MSK_MON1_PM 0x03
#define MA_LEN_MON1_PM 2
//--------------------------------------------------------------- MONITOR CHANNEL 1
#define MA_IND_MON1 31
#define MA_REG_MON1 0x65
#define MA_DEF_MON1 0x00
// DCU1 MUTE MONITOR
#define MA_SHIFT_MON1_MUTE 0x05
#define MA_MSK_MON1_MUTE 0x20
#define MA_LEN_MON1_MUTE 1
// DCU1 VDD MONITOR
#define MA_SHIFT_MON1_VDD_OK 0x04
#define MA_MSK_MON1_VDD_OK 0x10
#define MA_LEN_MON1_VDD_OK 1
// DCU1 PVDD MONITOR
#define MA_SHIFT_MON1_PVDD_OK 0x03
#define MA_MSK_MON1_PVDD_OK 0x08
#define MA_LEN_MON1_PVDD_OK 1
// CFLY2 PROTECTION MONITOR CHANNEL 1.
#define MA_SHIFT_MON1VCFLY2_OK 0x02
#define MA_MSK_MON1VCFLY2_OK 0x04
#define MA_LEN_MON1VCFLY2_OK 1
// CFLY1 PROTECTION MONITOR CHANNEL 1.
#define MA_SHIFT_MON1_VCFPLY1_OK 0x01
#define MA_MSK_MON1_VCFPLY1_OK 0x02
#define MA_LEN_MON1_VCFPLY1_OK 1
// OCP MONITOR CHANNEL 1
#define MA_SHIFT_MON1_OCP 0x00
#define MA_MSK_MON1_OCP 0x01
#define MA_LEN_MON1_OCP 1

//--------------------------------------------------------------- MONITOR CHANNEL 0 MODULATION INDEX
#define MA_IND_MON_CH1_MODUL 32
#define MA_REG_MON_CH1_MODUL 0x66
#define MA_DEF_MON_CH1_MODUL 0x00
#define MA_SHIFT_MON_CH1_MODUL 0x00
#define MA_MSK_MON_CH1_MODUL 0xFF
#define MA_LEN_MON_CH1_MODUL 8
//--------------------------------------------------------------- ACCUMULATED ERRORS,  AT AND AFTER TRIGGERING
#define MA_IND_ERRO_ACC 33
#define MA_REG_ERRO_ACC 0x6D
#define MA_DEF_ERRO_ACC 0x00
#define MA_SHIFT_ERRO_ACC 0x00
#define MA_MSK_ERRO_ACC 0xFF
#define MA_LEN_ERRO_ACC 8

//--------------------------------------------------------------- MSEL[2:0] MONITOR REGISTER
#define MA_IND_MON_MSEL 34
#define MA_REG_MON_MSEL 0x75
#define MA_DEF_MON_MSEL 0x00
#define MA_SHIFT_MON_MSEL 0x00
#define MA_MSK_MON_MSEL 0x07
#define MA_LEN_MON_MSEL 3
//--------------------------------------------------------------- CURRENT ERROR FLAG MONITOR REG - FOR APP. CTRL.
#define MA_IND_ERROR 35
#define MA_REG_ERROR 0x7C
#define MA_DEF_ERROR 0x00
#define MA_SHIFT_ERROR 0x00
#define MA_MSK_ERROR 0xFF
#define MA_LEN_ERROR 8
//---------------------------------------------------------------
#define MA_IND_MON_LIMIT_CLIP 36
#define MA_REG_MON_LIMIT_CLIP 0x7E
#define MA_DEF_MON_LIMIT_CLIP 0x00 

#define MA_SHIFT_MON_LIMIT 0x04
#define MA_MSK_MON_LIMIT 0xF0
#define MA_LEN_MON_LIMIT 4

#define MA_SHIFT_MON_CLIP 0x00
#define MA_MSK_MON_CLIP 0x0F
#define MA_LEN_MON_CLIP 4


#define REGAMOUNT MA_IND_MON_LIMIT_CLIP + 1 
#define READONLY 10
#define READWRITE REGAMOUNT - READONLY

#define MA_VOL_MAX 2400
#define MA_VOL_MIN -14400
#define MA_VOL_MAX_DB 24
#define MA_VOL_MIN_DB -144


void 	ma_setVolumeMasterDb(int16_t volume); 
void	ma_init(void); 
void	ma_configure(uint8_t factory);
int16_t ma_getVolumeDb(void); 

/*Select manual Power Mode control. Default
 *the device will operate in automatic Power
 *Mode control. 
 *This bit can be set to 1 if manual Power Mode control is required.
 */
void ma_setPowerMode(uint8_t mode);

/*
 *Threshold value for PM1=>PM2 change. This
 *value will set the threshold for when automatic
 *Power Mode changes from PMX to PMX. It can
 *be programmed from 0 - 255; 
 *this maps to 0 output power – max output power
 */
void ma_setTreshold(uint8_t transition, uint8_t value); 

/*soft-clipping. High to enable. Low to disable
 */
void ma_setClipping(uint8_t enable);

/*High to use permanently latching OCP. 
 */
void ma_setOcp(uint8_t enable);

/*Power Mode Profile select. With this register
 *the user can select the appropriate Power Mode Profile.
 * Datasheet MA12070P page 13 
*/
void ma_setPowerModeProfileSetings(uint8_t setings); 
void ma_setPowerModeProfileConfig(uint8_t scheme, uint8_t powerMode); 

// Load factory settings to the main value table
void ma_setFactorySettings(); 


void ma_clearOcpLatch(void); 
void ma_setAudioInMode(uint8_t mode);
void ma_setDcProtection(uint8_t enable);
void ma_setAudioInOverwrite(uint8_t enable);

void ma_setI2sFormat(uint8_t format); 
void ma_setI2sRightFirst(uint8_t leftOrRight);
void ma_setI2sFrameSize(uint8_t bits);
void ma_setI2sBitOrder(uint8_t mostOrLeast);
void ma_setI2sWsPolarity(uint8_t highOrLow);
void ma_setI2sSckPolarity(uint8_t risingOrFalling);

void ma_setProcReleaseLvl(uint8_t lvl);
void ma_setProcAttackLvl(uint8_t lvl);
void ma_setProcEn(uint8_t enable);
void ma_setProcMute(uint8_t mute);
void ma_setProcLimiter(uint8_t enable);

void ma_setVolumeCh0(uint8_t db, uint8_t lsb);
void ma_setVolumeCh1(uint8_t db, uint8_t lsb);
void ma_setVolumeCh2(uint8_t db, uint8_t lsb);
void ma_setVolumeCh3(uint8_t db, uint8_t lsb);
void ma_setVolumeMaster(uint8_t db, uint8_t lsb);

void ma_clearErrHandler(void);

int16_t ma_getVolume(void);

void ma_printCurrentCconf(void);
void ma_getCurrentDevInfo(void); 
//I2C Functions 
void ma_clearRegTable(void);
void ma_i2c_fetch(void);
void ma_i2c_update(void);
// Error Mangement 
void ma_throwError(uint16_t error);
void printBinary_uint8(uint8_t toPrint);
