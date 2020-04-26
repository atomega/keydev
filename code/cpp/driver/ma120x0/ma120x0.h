#define MA12070_ADDR 0x20 // Device Adress



//------------------------------------------------------------------manualPM---
// Select Manual PowerMode control
#define ma_manualpm__a 0
#define ma_pm__index 0
#define ma_manualpm__len 1
#define ma_manualpm__mask 0x40
#define ma_manualpm__shift 0x06
#define ma_manualpm__reset 0x00
//--------------------------------------------------------------------pm_man---
// manual selected power mode
#define ma_pm_man__a 0
#define ma_pm_man__len 2
#define ma_pm_man__mask 0x30
#define ma_pm_man__shift 0x04
#define ma_pm_man__reset 0x03
//------------------------------------------ ----------------------mthr_1to2---
// mod. index threshold value for pm1=>pm2 change.
#define ma_mthr_1to2__a 1
#define ma_mthr_1to2__index 1
#define ma_mthr_1to2__len 8
#define ma_mthr_1to2__mask 0xff
#define ma_mthr_1to2__shift 0x00
#define ma_mthr_1to2__reset 0x3c
//-----------------------------------------------------------------mthr_2to1---
// mod. index threshold value for pm2=>pm1 change.
#define ma_mthr_2to1__a 2
#define ma_mthr_2to1__index 2
#define ma_mthr_2to1__len 8
#define ma_mthr_2to1__mask 0xff
#define ma_mthr_2to1__shift 0x00
#define ma_mthr_2to1__reset 0x32
//-----------------------------------------------------------------mthr_2to3---
// mod. index threshold value for pm2=>pm3 change.
#define ma_mthr_2to3__a 3
#define ma_mthr_2to3__index 3
#define ma_mthr_2to3__len 8
#define ma_mthr_2to3__mask 0xff
#define ma_mthr_2to3__shift 0x00
#define ma_mthr_2to3__reset 0x5a
//-----------------------------------------------------------------mthr_3to2---
// mod. index threshold value for pm3=>pm2 change.
#define ma_mthr_3to2__a 4
#define ma_mthr_3to2__index 4
#define ma_mthr_3to2__len 8
#define ma_mthr_3to2__mask 0xff
#define ma_mthr_3to2__shift 0x00
#define ma_mthr_3to2__reset 0x50
//-------------------------------------------------------------pwmclkdiv_nom---
// pwm default clock divider value
#define ma_pwmclkdiv_nom__a 8
#define ma_pwmclkdiv_nom__index 5
#define ma_pwmclkdiv_nom__len 8
#define ma_pwmclkdiv_nom__mask 0xff
#define ma_pwmclkdiv_nom__shift 0x00
#define ma_pwmclkdiv_nom__reset 0x26
//--------- ----------------------------------------------------ocp_latch_en---
// high to use permanently latching level-2 ocp
#define ma_ocp_latch_en__a 10
#define ma_ocp_latch_en__index 6
#define ma_ocp_latch_en__len 1
#define ma_ocp_latch_en__mask 0x02
#define ma_ocp_latch_en__shift 0x01
#define ma_ocp_latch_en__reset 0x00
//---------------------------------------------------------------lf_clamp_en---
// high (default) to enable lf int2+3 clamping on clip
#define ma_lf_clamp_en__a 10
#define ma_lf_clamp_en__index 7
#define ma_lf_clamp_en__len 1
#define ma_lf_clamp_en__mask 0x80
#define ma_lf_clamp_en__shift 0x07
#define ma_lf_clamp_en__reset 0x00
//-------------------------------------------------------pmcfg_btl_b.modtype---
//
#define ma_pmcfg_btl_b__modtype__a 18
#define ma_pmcfg_btl_b__index 8
#define ma_pmcfg_btl_b__modtype__len 2
#define ma_pmcfg_btl_b__modtype__mask 0x18
#define ma_pmcfg_btl_b__modtype__shift 0x03
#define ma_pmcfg_btl_b__modtype__reset 0x02
//-------------------------------------------------------pmcfg_btl_b.freqdiv---
#define ma_pmcfg_btl_b__freqdiv__a 18
#define ma_pmcfg_btl_b__freqdiv__len 2
#define ma_pmcfg_btl_b__freqdiv__mask 0x06
#define ma_pmcfg_btl_b__freqdiv__shift 0x01
#define ma_pmcfg_btl_b__freqdiv__reset 0x01
//----------------------------------------------------pmcfg_btl_b.lf_gain_ol---
//
#define ma_pmcfg_btl_b__lf_gain_ol__a 18
#define ma_pmcfg_btl_b__lf_gain_ol__len 1
#define ma_pmcfg_btl_b__lf_gain_ol__mask 0x01
#define ma_pmcfg_btl_b__lf_gain_ol__shift 0x00
#define ma_pmcfg_btl_b__lf_gain_ol__reset 0x01
//-------------------------------------------------------pmcfg_btl_c.freqdiv---
//
#define ma_pmcfg_btl_c__freqdiv__a 19
#define ma_pmcfg_btl_c__index 9
#define ma_pmcfg_btl_c__freqdiv__len 2
#define ma_pmcfg_btl_c__freqdiv__mask 0x06
#define ma_pmcfg_btl_c__freqdiv__shift 0x01
#define ma_pmcfg_btl_c__freqdiv__reset 0x01
//-------------------------------------------------------pmcfg_btl_c.modtype---
//
#define ma_pmcfg_btl_c__modtype__a 19
#define ma_pmcfg_btl_c__modtype__len 2
#define ma_pmcfg_btl_c__modtype__mask 0x18
#define ma_pmcfg_btl_c__modtype__shift 0x03
#define ma_pmcfg_btl_c__modtype__reset 0x01
//----------------------------------------------------pmcfg_btl_c.lf_gain_ol---
//
#define ma_pmcfg_btl_c__lf_gain_ol__a 19
#define ma_pmcfg_btl_c__lf_gain_ol__len 1
#define ma_pmcfg_btl_c__lf_gain_ol__mask 0x01
#define ma_pmcfg_btl_c__lf_gain_ol__shift 0x00
#define ma_pmcfg_btl_c__lf_gain_ol__reset 0x00
//-------------------------------------------------------pmcfg_btl_d.modtype---
//
#define ma_pmcfg_btl_d__modtype__a 20
#define ma_pmcfg_btl_d__index 10
#define ma_pmcfg_btl_d__modtype__len 2
#define ma_pmcfg_btl_d__modtype__mask 0x18
#define ma_pmcfg_btl_d__modtype__shift 0x03
#define ma_pmcfg_btl_d__modtype__reset 0x02
//-------------------------------------------------------pmcfg_btl_d.freqdiv---
//
#define ma_pmcfg_btl_d__freqdiv__a 20
#define ma_pmcfg_btl_d__freqdiv__len 2
#define ma_pmcfg_btl_d__freqdiv__mask 0x06
#define ma_pmcfg_btl_d__freqdiv__shift 0x01
#define ma_pmcfg_btl_d__freqdiv__reset 0x02
//----------------------------------------------------pmcfg_btl_d.lf_gain_ol---
//
#define ma_pmcfg_btl_d__lf_gain_ol__a 20
#define ma_pmcfg_btl_d__lf_gain_ol__len 1
#define ma_pmcfg_btl_d__lf_gain_ol__mask 0x01
#define ma_pmcfg_btl_d__lf_gain_ol__shift 0x00
#define ma_pmcfg_btl_d__lf_gain_ol__reset 0x00
//------------ -------------------------------------------pmcfg_se_a.modtype---
//
#define ma_pmcfg_se_a__modtype__a 21
#define ma_pmcfg_se_a__index 11
#define ma_pmcfg_se_a__modtype__len 2
#define ma_pmcfg_se_a__modtype__mask 0x18
#define ma_pmcfg_se_a__modtype__shift 0x03
#define ma_pmcfg_se_a__modtype__reset 0x01
//--------------------------------------------------------pmcfg_se_a.freqdiv---
//
#define ma_pmcfg_se_a__freqdiv__a 21
#define ma_pmcfg_se_a__freqdiv__len 2
#define ma_pmcfg_se_a__freqdiv__mask 0x06
#define ma_pmcfg_se_a__freqdiv__shift 0x01
#define ma_pmcfg_se_a__freqdiv__reset 0x00
//-----------------------------------------------------pmcfg_se_a.lf_gain_ol---
//
#define ma_pmcfg_se_a__lf_gain_ol__a 21
#define ma_pmcfg_se_a__lf_gain_ol__len 1
#define ma_pmcfg_se_a__lf_gain_ol__mask 0x01
#define ma_pmcfg_se_a__lf_gain_ol__shift 0x00
#define ma_pmcfg_se_a__lf_gain_ol__reset 0x01
//-----------------------------------------------------pmcfg_se_b.lf_gain_ol---
//
#define ma_pmcfg_se_b__lf_gain_ol__a 22
#define ma_pmcfg_se_b__index 12
#define ma_pmcfg_se_b__lf_gain_ol__len 1
#define ma_pmcfg_se_b__lf_gain_ol__mask 0x01
#define ma_pmcfg_se_b__lf_gain_ol__shift 0x00
#define ma_pmcfg_se_b__lf_gain_ol__reset 0x00
//--------------------------------------------------------pmcfg_se_b.freqdiv---
//
#define ma_pmcfg_se_b__freqdiv__a 22
#define ma_pmcfg_se_b__freqdiv__len 2
#define ma_pmcfg_se_b__freqdiv__mask 0x06
#define ma_pmcfg_se_b__freqdiv__shift 0x01
#define ma_pmcfg_se_b__freqdiv__reset 0x01
//--------------------------------------------------------pmcfg_se_b.modtype---
//
#define ma_pmcfg_se_b__modtype__a 22
#define ma_pmcfg_se_b__modtype__len 2
#define ma_pmcfg_se_b__modtype__mask 0x18
#define ma_pmcfg_se_b__modtype__shift 0x03
#define ma_pmcfg_se_b__modtype__reset 0x01
//----------------------------------------------------------balwaitcount_pm1---
// pm1 balancing period.
#define ma_balwaitcount_pm1__a 23
#define ma_balwaitcount_pm1__index 13
#define ma_balwaitcount_pm1__len 8
#define ma_balwaitcount_pm1__mask 0xff
#define ma_balwaitcount_pm1__shift 0x00
#define ma_balwaitcount_pm1__reset 0x14
//----------------------------------------------------------balwaitcount_pm2---
// pm2 balancing period.
#define ma_balwaitcount_pm2__a 24
#define ma_balwaitcount_pm2__index 13
#define ma_balwaitcount_pm2__len 8
#define ma_balwaitcount_pm2__mask 0xff
#define ma_balwaitcount_pm2__shift 0x00
#define ma_balwaitcount_pm2__reset 0x14
//----------------------------------------------------------balwaitcount_pm3---
// pm3 balancing period.
#define ma_balwaitcount_pm3__a 25
#define ma_balwaitcount_pm3__index 14
#define ma_balwaitcount_pm3__len 8
#define ma_balwaitcount_pm3__mask 0xff
#define ma_balwaitcount_pm3__shift 0x00
#define ma_balwaitcount_pm3__reset 0x1a
//-------------------------------------------------------------usespread_pm1---
// pm1 pwm spread-spectrum mode on/off.
#define ma_usespread_pm1__a 26
#define ma_usespread_pm1__len 1
#define ma_usespread_pm1__mask 0x40
#define ma_usespread_pm1__shift 0x06
#define ma_usespread_pm1__reset 0x00
//---------------------------------------------------------------dtsteps_pm1---
// pm1 dead time setting [10ns steps].
#define ma_dtsteps_pm1__a 26
#define ma_dtsteps_pm1__len 3
#define ma_dtsteps_pm1__mask 0x38
#define ma_dtsteps_pm1__shift 0x03
#define ma_dtsteps_pm1__reset 0x04
//---------------------------------------------------------------baltype_pm1---
// pm1 balancing sensor scheme.
#define ma_baltype_pm1__a 26
#define ma_baltype_pm1__len 3
#define ma_baltype_pm1__mask 0x07
#define ma_baltype_pm1__shift 0x00
#define ma_baltype_pm1__reset 0x00
//-------------------------------------------------------------usespread_pm2---
// pm2 pwm spread-spectrum mode on/off.
#define ma_usespread_pm2__a 27
#define ma_usespread_pm2__len 1
#define ma_usespread_pm2__mask 0x40
#define ma_usespread_pm2__shift 0x06
#define ma_usespread_pm2__reset 0x00
//---------------------------------------------------------------dtsteps_pm2---
// pm2 dead time setting [10ns steps].
#define ma_dtsteps_pm2__a 27
#define ma_dtsteps_pm2__len 3
#define ma_dtsteps_pm2__mask 0x38
#define ma_dtsteps_pm2__shift 0x03
#define ma_dtsteps_pm2__reset 0x03
//---------------------------------------------------------------baltype_pm2---
// pm2 balancing sensor scheme.
#define ma_baltype_pm2__a 27
#define ma_baltype_pm2__len 3
#define ma_baltype_pm2__mask 0x07
#define ma_baltype_pm2__shift 0x00
#define ma_baltype_pm2__reset 0x01
//-------------------------------------------------------------usespread_pm3---
// pm3 pwm spread-spectrum mode on/off.
#define ma_usespread_pm3__a 28
#define ma_usespread_pm3__len 1
#define ma_usespread_pm3__mask 0x40
#define ma_usespread_pm3__shift 0x06
#define ma_usespread_pm3__reset 0x00
//---------------------------------------------------------------dtsteps_pm3---
// pm3 dead time setting [10ns steps].
#define ma_dtsteps_pm3__a 28
#define ma_dtsteps_pm3__len 3
#define ma_dtsteps_pm3__mask 0x38
#define ma_dtsteps_pm3__shift 0x03
#define ma_dtsteps_pm3__reset 0x01
//---------------------------------------------------------------baltype_pm3---
// pm3 balancing sensor scheme.
#define ma_baltype_pm3__a 28
#define ma_baltype_pm3__len 3
#define ma_baltype_pm3__mask 0x07
#define ma_baltype_pm3__shift 0x00
#define ma_baltype_pm3__reset 0x03
//-----------------------------------------------------------------pmprofile---
// pm profile select. valid presets: 0-1-2-3-4. 5=> custom profile.
#define ma_pmprofile__a 29
#define ma_pmprofile__len 3
#define ma_pmprofile__mask 0x07
#define ma_pmprofile__shift 0x00
#define ma_pmprofile__reset 0x00
//-------------------------------------------------------------------pm3_man---
// custom profile pm3 contents. 0=>a,  1=>b,  2=>c,  3=>d
#define ma_pm3_man__a 30
#define ma_pm3_man__len 2
#define ma_pm3_man__mask 0x30
#define ma_pm3_man__shift 0x04
#define ma_pm3_man__reset 0x02
//-------------------------------------------------------------------pm2_man---
// custom profile pm2 contents. 0=>a,  1=>b,  2=>c,  3=>d
#define ma_pm2_man__a 30
#define ma_pm2_man__len 2
#define ma_pm2_man__mask 0x0c
#define ma_pm2_man__shift 0x02
#define ma_pm2_man__reset 0x03
//-------------------------------------------------------------------pm1_man---
// custom profile pm1 contents. 0=>a,  1=>b,  2=>c,  3=>d
#define ma_pm1_man__a 30
#define ma_pm1_man__len 2
#define ma_pm1_man__mask 0x03
#define ma_pm1_man__shift 0x00
#define ma_pm1_man__reset 0x03
//-----------------------------------------------------------ocp_latch_clear---
// low-high clears current ocp latched condition.
#define ma_ocp_latch_clear__a 32
#define ma_ocp_latch_clear__len 1
#define ma_ocp_latch_clear__mask 0x80
#define ma_ocp_latch_clear__shift 0x07
#define ma_ocp_latch_clear__reset 0x00
//-------------------------------------------------------------audio_in_mode---
// audio input mode; 0-1-2-3-4-5
#define ma_audio_in_mode__a 37
#define ma_audio_in_mode__len 3
#define ma_audio_in_mode__mask 0xe0
#define ma_audio_in_mode__shift 0x05
#define ma_audio_in_mode__reset 0x00
//-----------------------------------------------------------------eh_dcshdn---
// high to enable dc protection
#define ma_eh_dcshdn__a 38
#define ma_eh_dcshdn__len 1
#define ma_eh_dcshdn__mask 0x04
#define ma_eh_dcshdn__shift 0x02
#define ma_eh_dcshdn__reset 0x01
//---------------------------------------------------------audio_in_mode_ext---
// if set,  audio_in_mode is controlled from audio_in_mode register. if not set
//audio_in_mode is set from fuse bank setting
#define ma_audio_in_mode_ext__a 39
#define ma_audio_in_mode_ext__len 1
#define ma_audio_in_mode_ext__mask 0x20
#define ma_audio_in_mode_ext__shift 0x05
#define ma_audio_in_mode_ext__reset 0x00
//------------------------------------------------------------------eh_clear---
// flip to clear error registers
#define ma_eh_clear__a 45
#define ma_eh_clear__len 1
#define ma_eh_clear__mask 0x04
#define ma_eh_clear__shift 0x02
#define ma_eh_clear__reset 0x00
//----------------------------------------------------------thermal_compr_en---
// enable otw-contr.  input compression?
#define ma_thermal_compr_en__a 45
#define ma_thermal_compr_en__len 1
#define ma_thermal_compr_en__mask 0x20
#define ma_thermal_compr_en__shift 0x05
#define ma_thermal_compr_en__reset 0x01
//---------------------------------------------------------------system_mute---
// 1 = mute system,  0 = normal operation
#define ma_system_mute__a 45
#define ma_system_mute__len 1
#define ma_system_mute__mask 0x40
#define ma_system_mute__shift 0x06
#define ma_system_mute__reset 0x00
//------------------------------------------------------thermal_compr_max_db---
// audio limiter max thermal reduction
#define ma_thermal_compr_max_db__a 46
#define ma_thermal_compr_max_db__len 3
#define ma_thermal_compr_max_db__mask 0x07
#define ma_thermal_compr_max_db__shift 0x00
#define ma_thermal_compr_max_db__reset 0x04
//---------------------------------------------------------audio_proc_enable---
// enable audio proc,  bypass if not enabled
#define ma_audio_proc_enable__a 53
#define ma_audio_proc_enable__len 1
#define ma_audio_proc_enable__mask 0x08
#define ma_audio_proc_enable__shift 0x03
#define ma_audio_proc_enable__reset 0x00
//--------------------------------------------------------audio_proc_release---
// 00:slow,  01:normal,  10:fast
#define ma_audio_proc_release__a 53
#define ma_audio_proc_release__len 2
#define ma_audio_proc_release__mask 0x30
#define ma_audio_proc_release__shift 0x04
#define ma_audio_proc_release__reset 0x00
//---------------------------------------------------------audio_proc_attack---
// 00:slow,  01:normal,  10:fast
#define ma_audio_proc_attack__a 53
#define ma_audio_proc_attack__len 2
#define ma_audio_proc_attack__mask 0xc0
#define ma_audio_proc_attack__shift 0x06
#define ma_audio_proc_attack__reset 0x00
//----------------------------------------------------------------i2s_format---
// i2s basic data format,  000 = std. i2s,  001 = left justified (default)
#define ma_i2s_format__a 53
#define ma_i2s_format__len 3
#define ma_i2s_format__mask 0x07
#define ma_i2s_format__shift 0x00
#define ma_i2s_format__reset 0x01
//--------------------------------------------------audio_proc_limiterenable---
// 1: enable limiter,  0: disable limiter
#define ma_audio_proc_limiterenable__a 54
#define ma_audio_proc_limiterenable__len 1
#define ma_audio_proc_limiterenable__mask 0x40
#define ma_audio_proc_limiterenable__shift 0x06
#define ma_audio_proc_limiterenable__reset 0x00
//-----------------------------------------------------------audio_proc_mute---
// 1: mute,  0: unmute
#define ma_audio_proc_mute__a 54
#define ma_audio_proc_mute__len 1
#define ma_audio_proc_mute__mask 0x80
#define ma_audio_proc_mute__shift 0x07
#define ma_audio_proc_mute__reset 0x00
//---------------------------------------------------------------i2s_sck_pol---
// i2s sck polarity cfg. 0 = rising edge data change
#define ma_i2s_sck_pol__a 54
#define ma_i2s_sck_pol__len 1
#define ma_i2s_sck_pol__mask 0x01
#define ma_i2s_sck_pol__shift 0x00
#define ma_i2s_sck_pol__reset 0x01
//-------------------------------------------------------------i2s_framesize---
// i2s word length. 00 = 32bit,  01 = 24bit
#define ma_i2s_framesize__a 54
#define ma_i2s_framesize__len 2
#define ma_i2s_framesize__mask 0x18
#define ma_i2s_framesize__shift 0x03
#define ma_i2s_framesize__reset 0x00
//----------------------------------------------------------------i2s_ws_pol---
// i2s ws polarity. 0 = low first
#define ma_i2s_ws_pol__a 54
#define ma_i2s_ws_pol__len 1
#define ma_i2s_ws_pol__mask 0x02
#define ma_i2s_ws_pol__shift 0x01
#define ma_i2s_ws_pol__reset 0x00
//-----------------------------------------------------------------i2s_order---
// i2s word bit order. 0 = msb first
#define ma_i2s_order__a 54
#define ma_i2s_order__len 1
#define ma_i2s_order__mask 0x04
#define ma_i2s_order__shift 0x02
#define ma_i2s_order__reset 0x00
//------------------------------------------------------------i2s_rightfirst---
// i2s l/r word order; 0 = left first
#define ma_i2s_rightfirst__a 54
#define ma_i2s_rightfirst__len 1
#define ma_i2s_rightfirst__mask 0x20
#define ma_i2s_rightfirst__shift 0x05
#define ma_i2s_rightfirst__reset 0x00
//-------------------------------------------------------------vol_db_master---
// master volume db
#define ma_vol_db_master__a 64
#define ma_vol_db_master__len 8
#define ma_vol_db_master__mask 0xff
#define ma_vol_db_master__shift 0x00
#define ma_vol_db_master__reset 0x18
//------------------------------------------------------------vol_lsb_master---
// master volume lsb 1/4 steps
#define ma_vol_lsb_master__a 65
#define ma_vol_lsb_master__len 2
#define ma_vol_lsb_master__mask 0x03
#define ma_vol_lsb_master__shift 0x00
#define ma_vol_lsb_master__reset 0x00
//----------------------------------------------------------------vol_db_ch0---
// volume channel 0
#define ma_vol_db_ch0__a 66
#define ma_vol_db_ch0__len 8
#define ma_vol_db_ch0__mask 0xff
#define ma_vol_db_ch0__shift 0x00
#define ma_vol_db_ch0__reset 0x18
//----------------------------------------------------------------vol_db_ch1---
// volume channel 1
#define ma_vol_db_ch1__a 67
#define ma_vol_db_ch1__len 8
#define ma_vol_db_ch1__mask 0xff
#define ma_vol_db_ch1__shift 0x00
#define ma_vol_db_ch1__reset 0x18
//----------------------------------------------------------------vol_db_ch2---
// volume channel 2
#define ma_vol_db_ch2__a 68
#define ma_vol_db_ch2__len 8
#define ma_vol_db_ch2__mask 0xff
#define ma_vol_db_ch2__shift 0x00
#define ma_vol_db_ch2__reset 0x18
//----------------------------------------------------------------vol_db_ch3---
// volume channel 3
#define ma_vol_db_ch3__a 69
#define ma_vol_db_ch3__len 8
#define ma_vol_db_ch3__mask 0xff
#define ma_vol_db_ch3__shift 0x00
#define ma_vol_db_ch3__reset 0x18
//---------------------------------------------------------------vol_lsb_ch0---
// volume channel 1 - 1/4 steps
#define ma_vol_lsb_ch0__a 70
#define ma_vol_lsb_ch0__len 2
#define ma_vol_lsb_ch0__mask 0x03
#define ma_vol_lsb_ch0__shift 0x00
#define ma_vol_lsb_ch0__reset 0x00
//---------------------------------------------------------------vol_lsb_ch1---
// volume channel 3 - 1/4 steps
#define ma_vol_lsb_ch1__a 70
#define ma_vol_lsb_ch1__len 2
#define ma_vol_lsb_ch1__mask 0x0c
#define ma_vol_lsb_ch1__shift 0x02
#define ma_vol_lsb_ch1__reset 0x00
//---------------------------------------------------------------vol_lsb_ch2---
// volume channel 2 - 1/4 steps
#define ma_vol_lsb_ch2__a 70
#define ma_vol_lsb_ch2__len 2
#define ma_vol_lsb_ch2__mask 0x30
#define ma_vol_lsb_ch2__shift 0x04
#define ma_vol_lsb_ch2__reset 0x00
//---------------------------------------------------------------vol_lsb_ch3---
// volume channel 3 - 1/4 steps
#define ma_vol_lsb_ch3__a 70
#define ma_vol_lsb_ch3__len 2
#define ma_vol_lsb_ch3__mask 0xc0
#define ma_vol_lsb_ch3__shift 0x06
#define ma_vol_lsb_ch3__reset 0x00
//----------------------------------------------------------------thr_db_ch0---
// thr_db channel 0
#define ma_thr_db_ch0__a 71
#define ma_thr_db_ch0__len 8
#define ma_thr_db_ch0__mask 0xff
#define ma_thr_db_ch0__shift 0x00
#define ma_thr_db_ch0__reset 0x18
//----------------------------------------------------------------thr_db_ch1---
// thr db ch1
#define ma_thr_db_ch1__a 72
#define ma_thr_db_ch1__len 8
#define ma_thr_db_ch1__mask 0xff
#define ma_thr_db_ch1__shift 0x00
#define ma_thr_db_ch1__reset 0x18
//----------------------------------------------------------------thr_db_ch2---
// thr db ch2
#define ma_thr_db_ch2__a 73
#define ma_thr_db_ch2__len 8
#define ma_thr_db_ch2__mask 0xff
#define ma_thr_db_ch2__shift 0x00
#define ma_thr_db_ch2__reset 0x18
//----------------------------------------------------------------thr_db_ch3---
// threshold db ch3
#define ma_thr_db_ch3__a 74
#define ma_thr_db_ch3__len 8
#define ma_thr_db_ch3__mask 0xff
#define ma_thr_db_ch3__shift 0x00
#define ma_thr_db_ch3__reset 0x18
//---------------------------------------------------------------thr_lsb_ch0---
// thr lsb ch0
#define ma_thr_lsb_ch0__a 75
#define ma_thr_lsb_ch0__len 2
#define ma_thr_lsb_ch0__mask 0x03
#define ma_thr_lsb_ch0__shift 0x00
#define ma_thr_lsb_ch0__reset 0x00
//---------------------------------------------------------------thr_lsb_ch1---
// thr lsb ch1
#define ma_thr_lsb_ch1__a 75
#define ma_thr_lsb_ch1__len 2
#define ma_thr_lsb_ch1__mask 0x0c
#define ma_thr_lsb_ch1__shift 0x02
#define ma_thr_lsb_ch1__reset 0x00
//---------------------------------------------------------------thr_lsb_ch2---
// thr lsb ch2 1/4 db step
#define ma_thr_lsb_ch2__a 75
#define ma_thr_lsb_ch2__len 2
#define ma_thr_lsb_ch2__mask 0x30
#define ma_thr_lsb_ch2__shift 0x04
#define ma_thr_lsb_ch2__reset 0x00
//---------------------------------------------------------------thr_lsb_ch3---
// threshold lsb ch3
#define ma_thr_lsb_ch3__a 75
#define ma_thr_lsb_ch3__len 2
#define ma_thr_lsb_ch3__mask 0xc0
#define ma_thr_lsb_ch3__shift 0x06
#define ma_thr_lsb_ch3__reset 0x00
//-----------------------------------------------------------dcu_mon0.pm_mon---
// power mode monitor channel 0
#define ma_dcu_mon0__pm_mon__a 96
#define ma_dcu_mon0__pm_mon__len 2
#define ma_dcu_mon0__pm_mon__mask 0x03
#define ma_dcu_mon0__pm_mon__shift 0x00
#define ma_dcu_mon0__pm_mon__reset 0x00
//-----------------------------------------------------dcu_mon0.freqmode_mon---
// frequence mode monitor channel 0
#define ma_dcu_mon0__freqmode_mon__a 96
#define ma_dcu_mon0__freqmode_mon__len 3
#define ma_dcu_mon0__freqmode_mon__mask 0x70
#define ma_dcu_mon0__freqmode_mon__shift 0x04
#define ma_dcu_mon0__freqmode_mon__reset 0x00
//-------------------------------------------------------dcu_mon0.pps_passed---
// dcu0 pps completion indicator
#define ma_dcu_mon0__pps_passed__a 96
#define ma_dcu_mon0__pps_passed__len 1
#define ma_dcu_mon0__pps_passed__mask 0x80
#define ma_dcu_mon0__pps_passed__shift 0x07
#define ma_dcu_mon0__pps_passed__reset 0x00
//----------------------------------------------------------dcu_mon0.ocp_mon---
// ocp monitor channel 0
#define ma_dcu_mon0__ocp_mon__a 97
#define ma_dcu_mon0__ocp_mon__len 1
#define ma_dcu_mon0__ocp_mon__mask 0x01
#define ma_dcu_mon0__ocp_mon__shift 0x00
#define ma_dcu_mon0__ocp_mon__reset 0x00
//--------------------------------------------------------dcu_mon0.vcfly1_ok---
// cfly1 protection monitor channel 0.
#define ma_dcu_mon0__vcfly1_ok__a 97
#define ma_dcu_mon0__vcfly1_ok__len 1
#define ma_dcu_mon0__vcfly1_ok__mask 0x02
#define ma_dcu_mon0__vcfly1_ok__shift 0x01
#define ma_dcu_mon0__vcfly1_ok__reset 0x00
//--------------------------------------------------------dcu_mon0.vcfly2_ok---
// cfly2 protection monitor channel 0.
#define ma_dcu_mon0__vcfly2_ok__a 97
#define ma_dcu_mon0__vcfly2_ok__len 1
#define ma_dcu_mon0__vcfly2_ok__mask 0x04
#define ma_dcu_mon0__vcfly2_ok__shift 0x02
#define ma_dcu_mon0__vcfly2_ok__reset 0x00
//----------------------------------------------------------dcu_mon0.pvdd_ok---
// dcu0 pvdd monitor
#define ma_dcu_mon0__pvdd_ok__a 97
#define ma_dcu_mon0__pvdd_ok__len 1
#define ma_dcu_mon0__pvdd_ok__mask 0x08
#define ma_dcu_mon0__pvdd_ok__shift 0x03
#define ma_dcu_mon0__pvdd_ok__reset 0x00
//-----------------------------------------------------------dcu_mon0.vdd_ok---
// dcu0 vdd monitor
#define ma_dcu_mon0__vdd_ok__a 97
#define ma_dcu_mon0__vdd_ok__len 1
#define ma_dcu_mon0__vdd_ok__mask 0x10
#define ma_dcu_mon0__vdd_ok__shift 0x04
#define ma_dcu_mon0__vdd_ok__reset 0x00
//-------------------------------------------------------------dcu_mon0.mute---
// dcu0 mute monitor
#define ma_dcu_mon0__mute__a 97
#define ma_dcu_mon0__mute__len 1
#define ma_dcu_mon0__mute__mask 0x20
#define ma_dcu_mon0__mute__shift 0x05
#define ma_dcu_mon0__mute__reset 0x00
//------------------------------------------------------------dcu_mon0.m_mon---
// m sense monitor channel 0
#define ma_dcu_mon0__m_mon__a 98
#define ma_dcu_mon0__m_mon__len 8
#define ma_dcu_mon0__m_mon__mask 0xff
#define ma_dcu_mon0__m_mon__shift 0x00
#define ma_dcu_mon0__m_mon__reset 0x00
//-----------------------------------------------------------dcu_mon1.pm_mon---
// power mode monitor channel 1
#define ma_dcu_mon1__pm_mon__a 100
#define ma_dcu_mon1__pm_mon__len 2
#define ma_dcu_mon1__pm_mon__mask 0x03
#define ma_dcu_mon1__pm_mon__shift 0x00
#define ma_dcu_mon1__pm_mon__reset 0x00
//-----------------------------------------------------dcu_mon1.freqmode_mon---
// frequence mode monitor channel 1
#define ma_dcu_mon1__freqmode_mon__a 100
#define ma_dcu_mon1__freqmode_mon__len 3
#define ma_dcu_mon1__freqmode_mon__mask 0x70
#define ma_dcu_mon1__freqmode_mon__shift 0x04
#define ma_dcu_mon1__freqmode_mon__reset 0x00
//-------------------------------------------------------dcu_mon1.pps_passed---
// dcu1 pps completion indicator
#define ma_dcu_mon1__pps_passed__a 100
#define ma_dcu_mon1__pps_passed__len 1
#define ma_dcu_mon1__pps_passed__mask 0x80
#define ma_dcu_mon1__pps_passed__shift 0x07
#define ma_dcu_mon1__pps_passed__reset 0x00
//----------------------------------------------------------dcu_mon1.ocp_mon---
// ocp monitor channel 1
#define ma_dcu_mon1__ocp_mon__a 101
#define ma_dcu_mon1__ocp_mon__len 1
#define ma_dcu_mon1__ocp_mon__mask 0x01
#define ma_dcu_mon1__ocp_mon__shift 0x00
#define ma_dcu_mon1__ocp_mon__reset 0x00
//--------------------------------------------------------dcu_mon1.vcfly1_ok---
// cfly1 protcetion monitor channel 1
#define ma_dcu_mon1__vcfly1_ok__a 101
#define ma_dcu_mon1__vcfly1_ok__len 1
#define ma_dcu_mon1__vcfly1_ok__mask 0x02
#define ma_dcu_mon1__vcfly1_ok__shift 0x01
#define ma_dcu_mon1__vcfly1_ok__reset 0x00
//--------------------------------------------------------dcu_mon1.vcfly2_ok---
// cfly2 protection monitor channel 1
#define ma_dcu_mon1__vcfly2_ok__a 101
#define ma_dcu_mon1__vcfly2_ok__len 1
#define ma_dcu_mon1__vcfly2_ok__mask 0x04
#define ma_dcu_mon1__vcfly2_ok__shift 0x02
#define ma_dcu_mon1__vcfly2_ok__reset 0x00
//----------------------------------------------------------dcu_mon1.pvdd_ok---
// dcu1 pvdd monitor
#define ma_dcu_mon1__pvdd_ok__a 101
#define ma_dcu_mon1__pvdd_ok__len 1
#define ma_dcu_mon1__pvdd_ok__mask 0x08
#define ma_dcu_mon1__pvdd_ok__shift 0x03
#define ma_dcu_mon1__pvdd_ok__reset 0x00
//-----------------------------------------------------------dcu_mon1.vdd_ok---
// dcu1 vdd monitor
#define ma_dcu_mon1__vdd_ok__a 101
#define ma_dcu_mon1__vdd_ok__len 1
#define ma_dcu_mon1__vdd_ok__mask 0x10
#define ma_dcu_mon1__vdd_ok__shift 0x04
#define ma_dcu_mon1__vdd_ok__reset 0x00
//-------------------------------------------------------------dcu_mon1.mute---
// dcu1 mute monitor
#define ma_dcu_mon1__mute__a 101
#define ma_dcu_mon1__mute__len 1
#define ma_dcu_mon1__mute__mask 0x20
#define ma_dcu_mon1__mute__shift 0x05
#define ma_dcu_mon1__mute__reset 0x00
//------------------------------------------------------------dcu_mon1.m_mon---
// m sense monitor channel 1
#define ma_dcu_mon1__m_mon__a 102
#define ma_dcu_mon1__m_mon__len 8
#define ma_dcu_mon1__m_mon__mask 0xff
#define ma_dcu_mon1__m_mon__shift 0x00
#define ma_dcu_mon1__m_mon__reset 0x00
//--------------------------------------------------------dcu_mon0.sw_enable---
// dcu0 switch enable monitor
#define ma_dcu_mon0__sw_enable__a 104
#define ma_dcu_mon0__sw_enable__len 1
#define ma_dcu_mon0__sw_enable__mask 0x40
#define ma_dcu_mon0__sw_enable__shift 0x06
#define ma_dcu_mon0__sw_enable__reset 0x00
//--------------------------------------------------------dcu_mon1.sw_enable---
// dcu1 switch enable monitor
#define ma_dcu_mon1__sw_enable__a 104
#define ma_dcu_mon1__sw_enable__len 1
#define ma_dcu_mon1__sw_enable__mask 0x80
#define ma_dcu_mon1__sw_enable__shift 0x07
#define ma_dcu_mon1__sw_enable__reset 0x00
//------------------------------------------------------------hvboot0_ok_mon---
// hvboot0_ok for test/debug
#define ma_hvboot0_ok_mon__a 105
#define ma_hvboot0_ok_mon__len 1
#define ma_hvboot0_ok_mon__mask 0x40
#define ma_hvboot0_ok_mon__shift 0x06
#define ma_hvboot0_ok_mon__reset 0x00
//------------------------------------------------------------hvboot1_ok_mon---
// hvboot1_ok for test/debug
#define ma_hvboot1_ok_mon__a 105
#define ma_hvboot1_ok_mon__len 1
#define ma_hvboot1_ok_mon__mask 0x80
#define ma_hvboot1_ok_mon__shift 0x07
#define ma_hvboot1_ok_mon__reset 0x00
//-----------------------------------------------------------------error_acc---
// accumulated errors,  at and after triggering
#define ma_error_acc__a 109
#define ma_error_acc__len 8
#define ma_error_acc__mask 0xff
#define ma_error_acc__shift 0x00
#define ma_error_acc__reset 0x00
//-------------------------------------------------------------i2s_data_rate---
// detected i2s data rate: 00/01/10 = x1/x2/x4
#define ma_i2s_data_rate__a 116
#define ma_i2s_data_rate__len 2
#define ma_i2s_data_rate__mask 0x03
#define ma_i2s_data_rate__shift 0x00
#define ma_i2s_data_rate__reset 0x00
//---------------------------------------------------------audio_in_mode_mon---
// audio input mode monitor
#define ma_audio_in_mode_mon__a 116
#define ma_audio_in_mode_mon__len 3
#define ma_audio_in_mode_mon__mask 0x1c
#define ma_audio_in_mode_mon__shift 0x02
#define ma_audio_in_mode_mon__reset 0x00
//------------------------------------------------------------------msel_mon---
// msel[2:0] monitor register
#define ma_msel_mon__a 117
#define ma_msel_mon__len 3
#define ma_msel_mon__mask 0x07
#define ma_msel_mon__shift 0x00
#define ma_msel_mon__reset 0x00
//---------------------------------------------------------------------error---
// current error flag monitor reg - for app. ctrl.
#define ma_error__a 124
#define ma_error__len 8
#define ma_error__mask 0xff
#define ma_error__shift 0x00
#define ma_error__reset 0x00
//----------------------------------------------------audio_proc_limiter_mon---
// b7-b4: channel 3-0 limiter active
#define ma_audio_proc_limiter_mon__a 126
#define ma_audio_proc_limiter_mon__len 4
#define ma_audio_proc_limiter_mon__mask 0xf0
#define ma_audio_proc_limiter_mon__shift 0x04
#define ma_audio_proc_limiter_mon__reset 0x00
//-------------------------------------------------------audio_proc_clip_mon---
// b3-b0: channel 3-0 clipping monitor
#define ma_audio_proc_clip_mon__a 126
#define ma_audio_proc_clip_mon__len 4
#define ma_audio_proc_clip_mon__mask 0x0f
#define ma_audio_proc_clip_mon__shift 0x00
#define ma_audio_proc_clip_mon__reset 0x00
#endif   /* Tue Nov 14 13:36:42 2017*/




#define MA12070_VOL_MAX 2400
#define MA12070_VOL_MIN -14400
#define MA12070_VOL_MAX_DB 24
#define MA12070_VOL_MIN_DB -144

#define MA12070_REG_POWER_MODE_CONTROL 0x00 
#define MA12070_DEF_POWER_MODE_CONTROL 0x3D 
#define MA12070_POWER_MODE_1 1
#define MA12070_POWER_MODE_2 2
#define MA12070_POWER_MODE_3 3
#define MA12070_POWER_MODE_MAN 4
#define MA12070_POWER_MODE_AUTO 5
#define MA12070_POWER_MODE_DEFF 6	

#define MA12070_REG_MTHR_1TO2 0x01 
#define MA12070_DEF_MTHR_1TO2 0x3C 

#define MA12070_REG_MTHR_2TO1 0x02 
#define MA12070_DEF_MTHR_2TO1 0x32 

#define MA12070_REG_MTHR_2TO3 0x03 
#define MA12070_DEF_MTHR_2TO3 0x5A 

#define MA12070_REG_MTHR_3TO2 0x04 
#define MA12070_DEF_MTHR_3TO2 0x50 

#define MA12070_REG_SOFT_CILLIPNG 0x0A 
#define MA12070_CLIPPING_EN 0x1 
#define MA12070_CLIPPING_LATCH 0x00 
#define MA12070_DEF_SOFT_CILLIPNG 0xC 

#define MA12070_REG_PM_PROFILE_MODE 0x1D
#define MA12070_POWER_PROFILE_0 1
#define MA12070_POWER_PROFILE_1 2
#define MA12070_POWER_PROFILE_2 3
#define MA12070_POWER_PROFILE_3 4
#define MA12070_POWER_PROFILE_4 5
#define MA12070_DEF_PM_PROFILE_MODE 0x3D

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
#define MA12070_AUDIO_IN_MODE_0 1 
#define MA12070_AUDIO_IN_MODE_1 2
#define MA12070_DEF_AUDIO_IN_MODE 0x10

#define MA12070_REG_DC_PROTECTION 0x26 
#define MA12070_DEF_DC_PROTECTION 0x05 

#define MA12070_REG_AUDI_IN_OVERWRITE 0x27
#define MA12070_DEF_AUDI_IN_OVERWRITE 0X08

#define MA12070_REG_ERROR_HANDLER 0x2D
#define MA12070_DEF_ERROR_HANDLER 0x30

#define MA12070_REG_PCM_WORD_FORMAT 0x35
#define MA12070_I2S_STANDART 1
#define MA12070_I2S_LEFT 2
#define MA12070_I2S_RIGHT_16b 3
#define MA12070_I2S_RIGHT_18b 4
#define MA12070_I2S_RIGHT_20b 5
#define MA12070_I2S_RIGHT_24b 6

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
	uint8_t power_mode_manual;
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
	uint8_t vol_db[4];
	uint8_t vol_lsb[4];
	uint8_t thr_db[4];
	uint8_t thr_lsb[4];
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
uint8_t ma12070_setTreshold(uint8_t transition, uint8_t value); 
uint8_t ma12070_setClippingAndOcp(uint8_t clipOrOcp, uint8_t enable); 
uint8_t ma12070_setPowerModeProfileSetings(uint8_t setings); 
uint8_t ma12070_setPowerModeProfileConfig(uint8_t scheme, uint8_t powerMode); 
uint8_t ma12070_clearOcpLatch(); 
uint8_t ma12070_setAudioInMode(uint8_t mode);
uint8_t ma12070_setDcProtection(uint8_t enable);
uint8_t ma12070_setAudioInOverwrite(uint8_t enable);

uint8_t ma12070_setI2sFormat(uint8_t format); 
uint8_t ma12070_setI2sRightFirst(uint8_t leftOrRight);
uint8_t ma12070_setI2sNoOfFrameBits(uint8_t bits);
uint8_t ma12070_setI2sBitOrder(uint8_t mostOrLeast);
uint8_t ma12070_setI2sWsPolarity(uint8_t highOrLow);
uint8_t ma12070_setI2sSckPolarity(uint8_t risingOrFalling);

uint8_t ma12070_setProcReleaseLvl(uint8_t lvl);
uint8_t ma12070_setProcAttackLvl(uint8_t lvl);
uint8_t ma12070_setProcEn(uint8_t enable);
uint8_t ma12070_setProcMute(uint8_t mute);
uint8_t ma12060_setProcLimiterEn(uint8_t enable);

uint8_t ma12070_setVolumeCh0(uint8_t db, uint8_t lsb);
uint8_t ma12070_setVolumeCh1(uint8_t db, uint8_t lsb);
uint8_t ma12070_setVolumeCh2(uint8_t db, uint8_t lsb);
uint8_t ma12070_setVolumeCh3(uint8_t db, uint8_t lsb);
uint8_t ma12070_setVolumeMaster(uint8_t db, uint8_t lsb);


uint8_t ma12070_clearErrHandler();

int16_t ma12070_getVolume(void);

void ma12070_printCurrentCconf(void);
void ma12070_getCurrentDevInfo(void); 
