#include"../main.h"
#include"../i2c/i2c.h"
#include"../algorithms/bitgestion.h"
#include"ma12070.h"

int curretnVolume = 0; 

uint8_t Buffer = 0; 
S_MA12070 amp = {0}; 

uint8_t ma12070_initI2c(void)
{
	// Openning the i2c port for communication
	i2c_open_device(0x20);
	return 1;
}

uint8_t ma12070_setPowerMode(uint8_t mode)
{
	Buffer = i2c_read_8(MA12070_REG_POWER_MODE_CONTROL);
  		
	switch(mode)
	{
		case MA12070_POWER_MODE_MAN:
	 		Buffer = set_nth_bit_uint8(Buffer,6); 
			break; 
	
		case MA12070_POWER_MODE_1:
	 		Buffer = unset_nth_bit_uint8(Buffer,6); 
	 		Buffer = unset_nth_bit_uint8(Buffer,5); 
	 		Buffer = set_nth_bit_uint8(Buffer,4); 
			break; 
		
		case MA12070_POWER_MODE_2: 	
	 		Buffer = unset_nth_bit_uint8(Buffer,6); 
	 		Buffer = set_nth_bit_uint8(Buffer,5); 
	 		Buffer = unset_nth_bit_uint8(Buffer,4); 
			break; 
		
		case MA12070_POWER_MODE_3: 	
	 		Buffer = unset_nth_bit_uint8(Buffer,6); 
	 		Buffer = set_nth_bit_uint8(Buffer,5); 
	 		Buffer = set_nth_bit_uint8(Buffer,4); 
			break;  
		
		case MA12070_POWER_MODE_DEFF:	
	 		Buffer = MA12070_DEF_PM_PROFILE_MODE; 
			break; 
		
		default: 
				return 1; 
	}
	i2c_write_16(MA12070_REG_POWER_MODE_CONTROL,Buffer); 
	return 0;  	
}

uint8_t ma12070_setTreshold(uint8_t transition, uint8_t value)
{
	if(value <= 0 && value <= 255)
	{
		switch(transition)
		{
			case MA12070_REG_MTHR_1TO2 :
				i2c_write_16(MA12070_REG_MTHR_1TO2, value); 
				break;
			
			case MA12070_REG_MTHR_2TO1 : 
				i2c_write_16(MA12070_REG_MTHR_2TO1, value); 
				break;  
			
			case MA12070_REG_MTHR_2TO3 : 
				i2c_write_16(MA12070_REG_MTHR_2TO3, value); 
				break; 
			
			case MA12070_REG_MTHR_3TO2 : 
				i2c_write_16(MA12070_REG_MTHR_3TO2, value); 
				break; 
			
			default : 
				return 1; 
		}
		return 0; 
	}
	else 
	{
		return 1;
	}
	return 1; 
}

uint8_t ma12070_setClippingAndOcp(uint8_t clipOrOcp, uint8_t enable)
{
	if( clipOrOcp >= 0 && clipOrOcp <= 1 && enable >= 0 && enable <= 1)
	{
		Buffer = i2c_read_8(MA12070_REG_SOFT_CILLIPNG); 
		
		if (clipOrOcp)
		{
			if (enable)
			{
				Buffer = set_nth_bit_uint8(Buffer, 7);
			}
			else 
			{
				Buffer = unset_nth_bit_uint8(Buffer, 7);
			}
		}
		else
		{
			if (enable)
			{
				Buffer = set_nth_bit_uint8(Buffer, 1);
			}
			else
			{
				Buffer = unset_nth_bit_uint8(Buffer, 1);
			}
		}

		i2c_write_16(MA12070_REG_SOFT_CILLIPNG, Buffer);
		
		return 0; 
	}

	return 1; 
}

uint8_t ma12070_setPowerModeProfileSetings(uint8_t setings)
{
		switch(setings)
		{
			case MA12070_POWER_PROFILE_0 :
				Buffer = 0x00;
				break; 
			case MA12070_POWER_PROFILE_1 :
				Buffer = 0x01;
				break; 
			case MA12070_POWER_PROFILE_2 :
				Buffer = 0x02;
				break; 
			case MA12070_POWER_PROFILE_3 :
				Buffer = 0x03;
				break; 
			case MA12070_POWER_PROFILE_4 :
				Buffer = 0x04;
				break; 
			default:
				return 1; 
		}
		i2c_write_16(MA12070_REG_PM_PROFILE_MODE, Buffer);
		return 0;
}

uint8_t ma12070_setPowerModeProfileConfig(uint8_t scheme, uint8_t powerMode)
{
	if(scheme <= 3 && scheme >= 0 && powerMode <= 3 && powerMode >= 1)
	{
		Buffer = i2c_read_8(MA12070_REG_PM_PROFILE_CONF);
		switch(powerMode)
		{
			case MA12070_POWER_MODE_1 : 
				switch(scheme)
				{
					case MA12070_POWER_SCHEME_CUSTOM : 
						Buffer = set_nth_bit_uint8(Buffer,5);	//1
						Buffer = unset_nth_bit_uint8(Buffer,4); //0
						break; 
						 
					case MA12070_POWER_SCHEME_A : 
						Buffer = unset_nth_bit_uint8(Buffer,5); //0
						Buffer = unset_nth_bit_uint8(Buffer,4); //0
						break; 
						
					case MA12070_POWER_SCHEME_B : 
						Buffer = unset_nth_bit_uint8(Buffer,5); //0
						Buffer = set_nth_bit_uint8(Buffer,4);	//1
						break; 
						
					case MA12070_POWER_SCHEME_C : 
						Buffer = set_nth_bit_uint8(Buffer,5);	//1
						Buffer = unset_nth_bit_uint8(Buffer,4); //0
						break; 
						
					case MA12070_POWER_SCHEME_D :
						Buffer = set_nth_bit_uint8(Buffer,5); 	//1 
						Buffer = set_nth_bit_uint8(Buffer,4); 	//1
						break; 
						
					default : 
						return 1; 
				}
				i2c_write_16(MA12070_REG_PM_PROFILE_CONF,Buffer); 
				return 0; 

			case MA12070_POWER_MODE_2 : 
				switch(scheme)
				{
					case MA12070_POWER_SCHEME_CUSTOM : 
						Buffer = set_nth_bit_uint8(Buffer,3);	//1
						Buffer = set_nth_bit_uint8(Buffer,2);	//1
						break; 

					case MA12070_POWER_SCHEME_A :
						Buffer = unset_nth_bit_uint8(Buffer,3);	//0
						Buffer = unset_nth_bit_uint8(Buffer,2); //0
						break; 
					
					case MA12070_POWER_SCHEME_B : 
						Buffer = unset_nth_bit_uint8(Buffer,3);	//0
						Buffer = set_nth_bit_uint8(Buffer,2); 	//1 
						break; 
						
					case MA12070_POWER_SCHEME_C : 
						Buffer = set_nth_bit_uint8(Buffer,3);	//1 
						Buffer = unset_nth_bit_uint8(Buffer,2); //0
						break; 
						
					case MA12070_POWER_SCHEME_D :
						Buffer = set_nth_bit_uint8(Buffer,3); 	//1
						Buffer = set_nth_bit_uint8(Buffer,2); 	//1
						break; 
						
					default : 
						return 1; 
				}
				i2c_write_16(MA12070_REG_PM_PROFILE_CONF,Buffer); 
				return 0; 
			
			case MA12070_POWER_MODE_3 : 
				switch(scheme)
				{
					case MA12070_POWER_SCHEME_CUSTOM : 
						Buffer = set_nth_bit_uint8(Buffer,1);	//1
						Buffer = set_nth_bit_uint8(Buffer,0);	//1
						break; 

					case MA12070_POWER_SCHEME_A :
						Buffer = unset_nth_bit_uint8(Buffer,1);	//0
						Buffer = unset_nth_bit_uint8(Buffer,0);	//0
						break; 

					case MA12070_POWER_SCHEME_B : 
						Buffer = unset_nth_bit_uint8(Buffer,1);	//0
						Buffer = set_nth_bit_uint8(Buffer,0);		//1
						break; 
						
					case MA12070_POWER_SCHEME_C : 
						Buffer = set_nth_bit_uint8(Buffer,1);		//1
						Buffer = unset_nth_bit_uint8(Buffer,0); 	//0
						break; 
					
					case MA12070_POWER_SCHEME_D :
						Buffer = set_nth_bit_uint8(Buffer,1);	//1
						Buffer = set_nth_bit_uint8(Buffer,0); 	//1
						break; 

					default : 
						return 1; 
				}				
				i2c_write_16(MA12070_REG_PM_PROFILE_CONF,Buffer); 
				return 0;

			default :
				return 1; 
		}
	}
	else 
	{
		return 1; 
	}
	return 1;
}

uint8_t ma12070_clearOcpLatch()
{
	Buffer = i2c_read_8(MA12070_REG_OVER_CURR_PROT);
	Buffer = unset_nth_bit_uint8(Buffer,7);
	i2c_write_16(MA12070_REG_OVER_CURR_PROT, Buffer); 
	return 0;
}

uint8_t ma12070_setAudioInMode(uint8_t mode)
{
	if(mode <= 2 && mode >= 0 )
	{
		Buffer = i2c_read_8(MA12070_REG_AUDIO_IN_MODE); 
		switch(mode)
		{
			case MA12070_AUDIO_IN_MODE_0 :
				Buffer = unset_nth_bit_uint8(Buffer,6); 
				Buffer = unset_nth_bit_uint8(Buffer,5); 
				break; 
			case MA12070_AUDIO_IN_MODE_1 : 
				Buffer = unset_nth_bit_uint8(Buffer,6); 
				Buffer = set_nth_bit_uint8(Buffer,5); 
				break; 
			default : 
				return 1; 
		}
		i2c_write_16(MA12070_REG_AUDIO_IN_MODE, Buffer); 
		return 0; 
	}
	else 
	{
		return 0; 
	}
	return 1;
}

uint8_t ma12070_setDcProtection(uint8_t enable)
{
	Buffer = i2c_read_8(MA12070_REG_DC_PROTECTION);
	
	if(enable)
	{
		Buffer = set_nth_bit_uint8(Buffer,2);
	}
	else 
	{
		Buffer = unset_nth_bit_uint8(Buffer,2);
	}

	i2c_write_16(MA12070_REG_DC_PROTECTION, Buffer); 
	return 0;  
}


uint8_t ma12070_setAudioInOverwrite(uint8_t enable)
{
	Buffer = i2c_read_8(MA12070_REG_AUDI_IN_OVERWRITE);
	
	if(enable)
	{
		Buffer = set_nth_bit_uint8(Buffer,5);
	}
	else 
	{
		Buffer = unset_nth_bit_uint8(Buffer,5);
	}

	i2c_write_16(MA12070_REG_AUDI_IN_OVERWRITE,Buffer); 
	return 0;  
}

uint8_t ma12070_clearErrHandler()
{
	Buffer = i2c_read_8(MA12070_REG_ERROR_HANDLER);
	
	Buffer = unset_nth_bit_uint8(Buffer,2);
	i2c_write_16(MA12070_REG_ERROR_HANDLER,Buffer); 
	Buffer = set_nth_bit_uint8(Buffer,2);
	i2c_write_16(MA12070_REG_ERROR_HANDLER,Buffer); 
	Buffer = unset_nth_bit_uint8(Buffer,2);
	i2c_write_16(MA12070_REG_ERROR_HANDLER,Buffer); 
	
	return 0; 
}

uint8_t ma12070_setI2sFormat(uint8_t format)
{
	Buffer = i2c_read_8(MA12070_REG_PCM_WORD_FORMAT); 
	switch(format)
	{	
		case MA12070_I2S_STANDART :
			Buffer = 0x0;
			break; 
		case MA12070_I2S_LEFT :
			Buffer = 0x01; 
			break; 
		case MA12070_I2S_RIGHT_16b :
			Buffer = 0x04; 
			break; 
		case MA12070_I2S_RIGHT_18b :
			Buffer = 0x06; 
			break; 
		case MA12070_I2S_RIGHT_20b :
			Buffer = 0x0; 
			break; 
		case MA12070_I2S_RIGHT_24b :
			Buffer = 0x7; 
			break; 
		default : 
			return 1; 
	}	
	i2c_write_16(MA12070_REG_PCM_WORD_FORMAT,Buffer); 
	return 0; 	
}


uint8_t ma12070_setI2sRightFirst(uint8_t leftOrRight)
{
	Buffer = i2c_read_8(MA12070_REG_I2S_CONFIG); 
	if (leftOrRight == 0)
	{
		Buffer = unset_nth_bit_uint8(Buffer,5);
	}
	else if (leftOrRight == 1)
	{
	printf("Hre");
		Buffer = set_nth_bit_uint8(Buffer,5);
	}
	else 
	{
		return 1;
	}
	i2c_write_16(MA12070_REG_I2S_CONFIG,Buffer); 
	return 0;
}


uint8_t ma12070_setI2sNoOfFrameBits(uint8_t bits)
{
	Buffer = i2c_read_8(MA12070_REG_I2S_CONFIG); 
	switch (bits)
	{
		case 64 :
			Buffer = unset_nth_bit_uint8(Buffer,4);
			Buffer = unset_nth_bit_uint8(Buffer,3);
			break;

		case 48 : 
			Buffer = unset_nth_bit_uint8(Buffer,4);
			Buffer = set_nth_bit_uint8(Buffer,3);
			break; 

		case 32 : 
			Buffer = set_nth_bit_uint8(Buffer,4);
			Buffer = unset_nth_bit_uint8(Buffer,3);
			break;  

		default : 
			  return 1; 	
	
	}
	i2c_write_16(MA12070_REG_I2S_CONFIG,Buffer); 
	return 0;
}


uint8_t ma12070_setI2sBitOrder(uint8_t mostOrLeast)
{
	Buffer = i2c_read_8(MA12070_REG_I2S_CONFIG); 
	if (mostOrLeast == 0)
	{
		Buffer = unset_nth_bit_uint8(Buffer,2);
	}
	else if (mostOrLeast == 1)
	{
		Buffer = set_nth_bit_uint8(Buffer,2);
	}
	else 
	{
		return 1;
	}
	i2c_write_16(MA12070_REG_I2S_CONFIG,Buffer); 
	return 0;
}


uint8_t ma12070_setI2sWsPolarity(uint8_t highOrLow)
{
	Buffer = i2c_read_8(MA12070_REG_I2S_CONFIG); 
	if (highOrLow == 0)
	{
		Buffer = unset_nth_bit_uint8(Buffer,1);
	}
	else if (highOrLow == 1)
	{
		Buffer = set_nth_bit_uint8(Buffer,1);
	}
	else 
	{
		return 1;
	}
	i2c_write_16(MA12070_REG_I2S_CONFIG,Buffer); 
	return 0;
}

uint8_t ma12070_setI2sSckPolarity(uint8_t risingOrFalling)
{
	Buffer = i2c_read_8(MA12070_REG_I2S_CONFIG); 
	if (risingOrFalling == 0)
	{
		Buffer = unset_nth_bit_uint8(Buffer,0);
	}
	else if (risingOrFalling == 1)
	{
		Buffer = set_nth_bit_uint8(Buffer,0);
	}
	else 
	{
		return 1;
	}
	i2c_write_16(MA12070_REG_I2S_CONFIG,Buffer); 
	return 0;
}



uint8_t ma12070_setProcReleaseLvl(uint8_t lvl)
{
	Buffer = i2c_read_8(MA12070_REG_PROCESSOR_SET); 
	switch (lvl)
	{
		case 1 :
			Buffer = unset_nth_bit_uint8(Buffer,7);
			Buffer = unset_nth_bit_uint8(Buffer,6);
			break;

		case 2 : 
			Buffer = unset_nth_bit_uint8(Buffer,7);
			Buffer = set_nth_bit_uint8(Buffer,6);
			break; 

		case 3 : 
			Buffer = set_nth_bit_uint8(Buffer,7);
			Buffer = unset_nth_bit_uint8(Buffer,6);
			break;  

		default : 
			  return 1; 	
	
	}
	i2c_write_16(MA12070_REG_PROCESSOR_SET,Buffer); 
	return 0;
}

uint8_t ma12070_setProcAttackLvl(uint8_t lvl)
{
	Buffer = i2c_read_8(MA12070_REG_PROCESSOR_SET); 
	switch (lvl)
	{
		case 1 :
			Buffer = unset_nth_bit_uint8(Buffer,5);
			Buffer = unset_nth_bit_uint8(Buffer,4);
			break;

		case 2 : 
			Buffer = unset_nth_bit_uint8(Buffer,5);
			Buffer = set_nth_bit_uint8(Buffer,4);
			break; 

		case 3 : 
			Buffer = set_nth_bit_uint8(Buffer,5);
			Buffer = unset_nth_bit_uint8(Buffer,4);
			break;  

		default : 
			  return 1; 	
	
	}
	i2c_write_16(MA12070_REG_PROCESSOR_SET,Buffer); 
	return 0;
}


uint8_t ma12070_setProcEn(uint8_t enable)
{
	Buffer = i2c_read_8(MA12070_REG_PROCESSOR_SET); 
	if (enable == 0)
	{
		Buffer = unset_nth_bit_uint8(Buffer,3);
	}
	else if (enable == 1)
	{
		Buffer = set_nth_bit_uint8(Buffer,3);
	}
	else 
	{
		return 1;
	}
	i2c_write_16(MA12070_REG_PROCESSOR_SET,Buffer); 
	return 0;
}


uint8_t ma12070_setProcMute(uint8_t mute)
{
	Buffer = i2c_read_8(MA12070_REG_LIMITER_SET); 
	if (mute == 0)
	{
		Buffer = unset_nth_bit_uint8(Buffer,7);
	}
	else if (mute == 1)
	{
		Buffer = set_nth_bit_uint8(Buffer,7);
	}
	else 
	{
		return 1;
	}
	i2c_write_16(MA12070_REG_LIMITER_SET,Buffer); 
	return 0;
}


uint8_t ma12060_setProcLimiterEn(uint8_t enable)
{
	Buffer = i2c_read_8(MA12070_REG_LIMITER_SET); 
	if (enable == 0)
	{
		Buffer = unset_nth_bit_uint8(Buffer,6);
	}
	else if (enable == 1)
	{
		Buffer = set_nth_bit_uint8(Buffer,6);
	}
	else 
	{
		return 1;
	}
	i2c_write_16(MA12070_REG_LIMITER_SET,Buffer); 
	return 0;
}





int16_t ma12070_getVolume(void)
{
	uint8_t DbFractionTab[3] = {25,50,75}; 
 	int16_t volume = 0; 	

	amp.vol_db_master = i2c_read_8(MA12070_REG_VOL_DB_MASTER); 
	amp.vol_lsb_master = i2c_read_8(MA12070_REG_VOL_LSB_MASTER);
	
	volume += (24 - amp.vol_db_master) * 100 - DbFractionTab[amp.vol_lsb_master-1];    
			
	printf("\nVolume: %d\t\n", volume); 
	return 1; 
}

void ma12070_printCurrentCconf(void)
{
	printf("\n\n\t CURRENT CONFIGURATION OF MA12070P \n\n");
	printf("power_mode = %d\n", amp.power_mode);
	printf("power_mode namual = %d\n", amp.power_mode_manual);
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
	Buffer = i2c_read_8(MA12070_REG_POWER_MODE_CONTROL);
	amp.power_mode = get_bits_range_uint8(Buffer,4,5); 
	amp.power_mode_manual =  get_nth_bit_uint8(Buffer,6); 
	amp.treshold_1to2 = i2c_read_8(MA12070_REG_MTHR_1TO2);
	amp.treshold_2to1 = i2c_read_8(MA12070_REG_MTHR_2TO1);
	amp.treshold_2to3 = i2c_read_8(MA12070_REG_MTHR_2TO3);
	amp.treshold_3to2 = i2c_read_8(MA12070_REG_MTHR_3TO2);

	Buffer = i2c_read_8(MA12070_REG_SOFT_CILLIPNG); 
	amp.ifClampEn = get_nth_bit_uint8(Buffer,7);
	amp.ocpLatchEn = get_nth_bit_uint8(Buffer,1);
	 
	Buffer = i2c_read_8(MA12070_REG_PM_PROFILE_MODE);
	amp.pmProfile = get_n_bits_lsb_uint8(Buffer, 3); 

	Buffer = i2c_read_8(MA12070_REG_PM_PROFILE_CONF);
	amp.pm3_man = get_bits_range_uint8(Buffer,4,5); 
	amp.pm2_man = get_bits_range_uint8(Buffer,2,3); 
	amp.pm1_man = get_n_bits_lsb_uint8(Buffer,2);  
	
	Buffer = i2c_read_8(MA12070_REG_OVER_CURR_PROT);
	amp.ocp_latch_clear =  get_nth_bit_uint8(Buffer,7);

	Buffer = i2c_read_8(MA12070_REG_AUDIO_IN_MODE);
	amp.audio_in_mode = get_bits_range_uint8(Buffer,5,6);
	Buffer = i2c_read_8(MA12070_REG_DC_PROTECTION);
	amp.eh_dc_shndn = get_nth_bit_uint8(Buffer,2);

	Buffer = i2c_read_8(MA12070_REG_AUDI_IN_OVERWRITE);
	amp.audio_in_mode_ext = get_nth_bit_uint8(Buffer,5);
	
	Buffer = i2c_read_8(MA12070_REG_ERROR_HANDLER);
	amp.eh_clear = get_nth_bit_uint8(Buffer,2);
	
	Buffer = i2c_read_8(MA12070_REG_PCM_WORD_FORMAT);
	amp.i2s_format = Buffer;
	
	Buffer = i2c_read_8(MA12070_REG_I2S_CONFIG);
	amp.i2s_right_first = get_nth_bit_uint8(Buffer,5);
	amp.i2s_frame_size = get_bits_range_uint8(Buffer,3,4);
	amp.i2s_order = get_nth_bit_uint8(Buffer,2);
	amp.i2s_ws_pol = get_nth_bit_uint8(Buffer,1);
	amp.i2s_sck_pol = get_nth_bit_uint8(Buffer,0);
	
	Buffer = i2c_read_8(MA12070_REG_PROCESSOR_SET);
	amp.audio_proc_release = get_bits_range_uint8(Buffer,6,7);
	amp.audio_proc_attack = get_bits_range_uint8(Buffer,4,5);
	amp.audio_proc_enable = get_nth_bit_uint8(Buffer,3);
	
	Buffer = i2c_read_8(MA12070_REG_LIMITER_SET);
	amp.audio_proc_mute = get_nth_bit_uint8(Buffer,7);
	amp.audio_proc_limitter = get_nth_bit_uint8(Buffer,6);
	
	amp.vol_db_master = i2c_read_8(MA12070_REG_VOL_DB_MASTER);
	
	Buffer = i2c_read_8(MA12070_REG_VOL_LSB_MASTER);
	amp.vol_lsb_master = get_n_bits_lsb_uint8(Buffer,2);

	amp.vol_db[0] = i2c_read_8(MA12070_REG_VOL_DB_CH0);
	amp.vol_db[1] = i2c_read_8(MA12070_REG_VOL_DB_CH1);
	amp.vol_db[2] = i2c_read_8(MA12070_REG_VOL_DB_CH2);
	amp.vol_db[3] = i2c_read_8(MA12070_REG_VOL_DB_CH3);
	Buffer = i2c_read_8(MA12070_REG_VOL_LSB_CHX);
	amp.vol_lsb[0] = get_n_bits_lsb_uint8(Buffer,2);
	amp.vol_lsb[1] = get_bits_range_uint8(Buffer,2,3);
	amp.vol_lsb[2] = get_bits_range_uint8(Buffer,4,5);
	amp.vol_lsb[3] = get_bits_range_uint8(Buffer,6,7);

	amp.thr_db[0] = i2c_read_8(MA12070_REG_THR_DB_CH0);
	amp.thr_db[1] = i2c_read_8(MA12070_REG_THR_DB_CH1);
	amp.thr_db[2] = i2c_read_8(MA12070_REG_THR_DB_CH2);
	amp.thr_db[3] = i2c_read_8(MA12070_REG_THR_DB_CH3);
	Buffer = i2c_read_8(MA12070_REG_THR_LSB_CHX);
	amp.thr_lsb[0] = get_n_bits_lsb_uint8(Buffer,2);
	amp.thr_lsb[1] = get_bits_range_uint8(Buffer,2,3);
	amp.thr_lsb[2] = get_bits_range_uint8(Buffer,4,5);
	amp.thr_lsb[3] = get_bits_range_uint8(Buffer,6,7);

	Buffer = i2c_read_8(MA12070_REG_LIMITER_STATUS);
	amp.audio_porc_limiter_mon = get_bits_range_uint8(Buffer,4,7);
	Buffer = i2c_read_8(MA12070_REG_CLIP_STAUTS);
	amp.audio_proc_clip_mon = get_n_bits_lsb_uint8(Buffer,4);

	Buffer = i2c_read_8(MA12070_REG_MON_CH0_FREQ_POW);
	amp.dcu_frequency_mon[0] = get_bits_range_uint8(Buffer,4,6);
	amp.dcu_power_mode_mon[0] = get_n_bits_lsb_uint8(Buffer,2);
	
	Buffer = i2c_read_8(MA12070_REG_MON_CH1_FREQ_POW);
	amp.dcu_frequency_mon[1] = get_bits_range_uint8(Buffer,4,6);
	amp.dcu_power_mode_mon[1] = get_n_bits_lsb_uint8(Buffer,2);
	
	Buffer = i2c_read_8(MA12070_REG_MON_CH0);
	amp.dcu_mute_mon[0] = get_nth_bit_uint8(Buffer,5);
	amp.dcu_vdd_ok_mon[0] = get_nth_bit_uint8(Buffer,4);
	amp.dcu_pvdd_ok_mon[0] = get_nth_bit_uint8(Buffer,3);
	amp.dcu_vcfly2_ok_mon[0] = get_nth_bit_uint8(Buffer,2);
	amp.dcu_vcfly1_ok_mon[0] = get_nth_bit_uint8(Buffer,1);
	amp.ocp_mon[0] = get_nth_bit_uint8(Buffer,0);
	
	Buffer = i2c_read_8(MA12070_REG_MON_CH1);
	amp.dcu_mute_mon[1] = get_nth_bit_uint8(Buffer,5);
	amp.dcu_vdd_ok_mon[1] = get_nth_bit_uint8(Buffer,4);
	amp.dcu_pvdd_ok_mon[1] = get_nth_bit_uint8(Buffer,3);
	amp.dcu_vcfly2_ok_mon[1] = get_nth_bit_uint8(Buffer,2);
	amp.dcu_vcfly1_ok_mon[1] = get_nth_bit_uint8(Buffer,1);
	amp.ocp_mon[1] = get_nth_bit_uint8(Buffer,0);

	amp.dcu_modulation_mon[0] = i2c_read_8(MA12070_REG_MON_CH0_MODUL);
	amp.dcu_modulation_mon[1] = i2c_read_8(MA12070_REG_MON_CH1_MODUL);

	amp.error_acc = i2c_read_8(MA12070_REG_ERRO_ACC);

	Buffer = i2c_read_8(MA12070_REG_MON_MSEL);
	amp.msel_mon = get_n_bits_lsb_uint8(Buffer,3);
	
	amp.error = i2c_read_8(MA12070_REG_ERROR);
}


uint8_t ma12070_setVolumeCh0(uint8_t db, uint8_t lsb)
{
	if(db >= 0 && db <=255 && lsb>= 0 && lsb <= 3)
	{
		i2c_write_16(MA12070_REG_VOL_DB_CH0,db);

		Buffer = i2c_read_8(MA12070_REG_VOL_LSB_CHX);
		
		switch(lsb)
		{
			case 0: 
				Buffer = unset_nth_bit_uint8(Buffer,1);
				Buffer = unset_nth_bit_uint8(Buffer,0);
				break; 
			case 1: 
				Buffer = set_nth_bit_uint8(Buffer,1);
				Buffer = unset_nth_bit_uint8(Buffer,0);
				break; 
			case 3: 
				Buffer = set_nth_bit_uint8(Buffer,1);
				Buffer = set_nth_bit_uint8(Buffer,0);
				break; 
			default: 
				return 1;
		}
		i2c_write_16(MA12070_REG_VOL_LSB_CHX,Buffer);
		return 0; 
	}
	else 
	{
		return 1; 
	}
	return 1;
}

uint8_t ma12070_setVolumeCh1(uint8_t db, uint8_t lsb)
{
	if(db >= 0 && db <=255 && lsb>= 0 && lsb <= 3)
	{
		i2c_write_16(MA12070_REG_VOL_DB_CH1,db);

		Buffer = i2c_read_8(MA12070_REG_VOL_LSB_CHX);
		
		switch(lsb)
		{
			case 0: 
				Buffer = unset_nth_bit_uint8(Buffer,3);
				Buffer = unset_nth_bit_uint8(Buffer,2);
				break; 
			case 1: 
				Buffer = set_nth_bit_uint8(Buffer,3);
				Buffer = unset_nth_bit_uint8(Buffer,2);
				break; 
			case 3: 
				Buffer = set_nth_bit_uint8(Buffer,3);
				Buffer = set_nth_bit_uint8(Buffer,2);
				break; 
			default: 
				return 1;
		}
		i2c_write_16(MA12070_REG_VOL_LSB_CHX,Buffer);
		return 0; 
	}
	else 
	{
		return 1; 
	}
	return 1;
}



uint8_t ma12070_setVolumeCh2(uint8_t db, uint8_t lsb)
{
	if(db >= 0 && db <=255 && lsb>= 0 && lsb <= 3)
	{
		i2c_write_16(MA12070_REG_VOL_DB_CH2,db);

		Buffer = i2c_read_8(MA12070_REG_VOL_LSB_CHX);
		
		switch(lsb)
		{
			case 0: 
				Buffer = unset_nth_bit_uint8(Buffer,5);
				Buffer = unset_nth_bit_uint8(Buffer,4);
				break; 
			case 1: 
				Buffer = set_nth_bit_uint8(Buffer,5);
				Buffer = unset_nth_bit_uint8(Buffer,4);
				break; 
			case 3: 
				Buffer = set_nth_bit_uint8(Buffer,5);
				Buffer = set_nth_bit_uint8(Buffer,4);
				break; 
			default: 
				return 1;
		}
		i2c_write_16(MA12070_REG_VOL_LSB_CHX,Buffer);
		return 0; 
	}
	else 
	{
		return 1; 
	}
	return 1;
}



uint8_t ma12070_setVolumeCh3(uint8_t db, uint8_t lsb)
{
	if(db >= 0 && db <=255 && lsb>= 0 && lsb <= 3)
	{
		printf("You are in"); 
		i2c_write_16(MA12070_REG_VOL_DB_CH3,db);

		Buffer = i2c_read_8(MA12070_REG_VOL_LSB_CHX);
		
		switch(lsb)
		{
			case 0: 
				Buffer = unset_nth_bit_uint8(Buffer,7);
				Buffer = unset_nth_bit_uint8(Buffer,6);
				break; 
			case 1: 
				Buffer = set_nth_bit_uint8(Buffer,7);
				Buffer = unset_nth_bit_uint8(Buffer,6);
				break; 
			case 3: 
				Buffer = set_nth_bit_uint8(Buffer,7);
				Buffer = set_nth_bit_uint8(Buffer,6);
				break; 
			default: 
				return 1;
		}
		i2c_write_16(MA12070_REG_VOL_LSB_CHX,Buffer);
		return 0; 
	}
	else 
	{
		return 1; 
	}
	return 1;
}


uint8_t ma12070_setVolumeMaster(uint8_t db, uint8_t lsb)
{
	if(db >= 0 && db <=255 && lsb>= 0 && lsb <= 3)
	{
		i2c_write_16(MA12070_REG_VOL_DB_MASTER,db);

		Buffer = i2c_read_8(MA12070_REG_VOL_LSB_MASTER);
		
		switch(lsb)
		{
			case 0: 
				Buffer = unset_nth_bit_uint8(Buffer,1);
				Buffer = unset_nth_bit_uint8(Buffer,0);
				break; 
			case 1: 
				Buffer = set_nth_bit_uint8(Buffer,1);
				Buffer = unset_nth_bit_uint8(Buffer,0);
				break; 
			case 3: 
				Buffer = set_nth_bit_uint8(Buffer,1);
				Buffer = set_nth_bit_uint8(Buffer,0);
				break; 
			default: 
				return 1;
		}
		i2c_write_16(MA12070_REG_VOL_LSB_MASTER,Buffer);
		return 0; 
	}
	else 
	{
		return 1; 
	}
	return 1;
}



uint8_t ma12070_setVolume(int16_t volume)
{
	int16_t DbBuff = 0; 
	uint8_t DbFraction = 0; 
	uint8_t DbNumber = 0; 
   		
	//printf("Volume: %d\t", volume); 
	
	if (volume >= 0)
	{
		if( volume <= MA12070_VOL_MAX)
		{
			DbFraction = (char) get_n_bits_lsb_int16(volume,2); 
			DbBuff = (volume/100); 
			
			if(DbFraction == 0)
			{
				DbBuff = (MA12070_VOL_MAX_DB) - DbBuff; 
			} else { DbFraction = (DbFraction^3) + 1; DbBuff = (MA12070_VOL_MAX_DB) - DbBuff -1; } DbNumber = (char)DbBuff; printf("Bdnumber: %u\tfraction: %u \n",DbNumber, DbFraction); 
			
			
			i2c_write_16(MA12070_REG_VOL_DB_MASTER, DbNumber); 
			i2c_write_16(MA12070_REG_VOL_LSB_MASTER, DbFraction); 
			
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
			DbFraction = (char) get_n_bits_lsb_int16(volume,2); 
			DbBuff = (volume/100); 
			
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
		   printf("Bdnumber: %u\tfraction: %u \n",DbNumber, DbFraction);
						
			i2c_write_16(MA12070_REG_VOL_DB_MASTER, DbNumber); 
			i2c_write_16(MA12070_REG_VOL_LSB_MASTER, DbFraction); 
			
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
		ma12070_initI2c();
		
		ma12070_clearErrHandler();

		ma12070_setPowerMode( MA12070_POWER_MODE_DEFF); 	 						// Power mode is set to default 
		ma12070_setTreshold(MA12070_REG_MTHR_1TO2, MA12070_DEF_MTHR_1TO2); 	// Default treshold
		ma12070_setTreshold(MA12070_REG_MTHR_2TO1, MA12070_DEF_MTHR_2TO1); 	// Default treshold
		ma12070_setTreshold(MA12070_REG_MTHR_2TO3, MA12070_DEF_MTHR_2TO3); 	// Default treshold
		ma12070_setTreshold(MA12070_REG_MTHR_3TO2, MA12070_DEF_MTHR_3TO2); 	// Default treshold
		ma12070_setClippingAndOcp(MA12070_CLIPPING_EN,1); 							// soft Clipping ins enabled
		ma12070_setClippingAndOcp(MA12070_CLIPPING_LATCH,0); 						// Cilipping latch disabled
		ma12070_setPowerModeProfileSetings(MA12070_POWER_PROFILE_2);			// Profile 2 the default one 
		ma12070_setAudioInMode(MA12070_AUDIO_IN_MODE_0); 							// Audio in as default +20dB
		ma12070_setDcProtection(1); 														// DC Protection Enabled
		ma12070_setAudioInOverwrite(0);													// Audio In overwrite Disabled (must be enabeled to led AudioInMode to take effect)
	 	ma12070_setI2sFormat(MA12070_I2S_STANDART);									// Standart I2S Configuration
		ma12070_setI2sRightFirst(0); 														// Set to Left First
		ma12070_setI2sNoOfFrameBits(64);													// Word data lenght set to 32
		ma12070_setI2sBitOrder(0); 														//Set to most significant Bit

 		ma12070_setProcMute(0); 															// disabeled
		ma12070_setI2sWsPolarity(0); 														//Set to low
		ma12070_setI2sSckPolarity(1); 													// Set to Falling edge 
		ma12070_setProcReleaseLvl(1); 													// Set to slow 
	 	ma12070_setProcAttackLvl(1); 														// Set to slow
 		ma12070_setProcEn(1); 																// disabled
 		ma12060_setProcLimiterEn(1); 														// disabeled
		ma12070_setVolumeCh0(0x18,0x0);
		ma12070_setVolumeCh1(0x18,0x0);
		ma12070_setVolumeCh2(0x18,0x0);
		ma12070_setVolumeCh3(0x18,0x0);
		ma12070_setVolumeMaster(0x40,0x0);
		//ma12070_setVolume(-15);															// Set Volume to 0 dB 
	return 1; 
}


// This part of the code may later be neede but for now the ma12070_getCurrentDevInfo functio does the trick for me.
/*
uint8_t ma12070_monitorCh0FreqAndPwr()
{
	uint8_t frequency = 0;  
	uint8_t powerMode = 0; 
	Buffer = i2c_read_8(MA12070_REG_MON_CH0_FREQ_POW); 
	frequency = get_n_bits_msb_uint8(Buffer,4);
	frequency = frequency << 1; 
	powerMode = get_n_bits_lsb_uint8(Buffer,2); 
	amp.
} 

uint8_t ma12070_monitorCh0()
{
	Buffer = i2c_read_8(MA12070_REG_MON_CH0_FREQ_POW);
}

uint8_t ma12070_monitorCh0ModulationInd()
{

} */
