/*
* Author : Key 
* Library : Keydev Motor Control
* Version : 1.0 
* Description : Header file for the powetSTEP01 SPI Stepper motor controller.
*/

/* 
############################
# PARAM Register Addresses #  
############################
*/
						/*|Description					|Bit Len|Reset    	|Reset Value							
/*-General configuration---------------------------------------------------------------------------------------------------------*/
#define ABS_POS 0x01	/*|Current position 			| 22 	| 0x000000 	| 0 									*/
#define EL_POS 0x02		/*|Electrical position 			| 9 	| 0x000   	| 0 									*/
#define MARK 0x03		/*|Mark position 				| 22	| 0x000000 	| 0 									*/
#define SPEED 0x04		/*|Current speed 				| 20 	| 0x00000  	| 0 step/tick (0 step/s) 				*/
#define ACC 0x05		/*|Accel. 						| 12 	| 0x08A   	| 125.5e-12 step/tick2 (2008 step/s2) 	*/
#define DEC 0x06		/*|Decel. 						| 12 	| 0x08A   	| 125.5e-12 step/tick2 (2008 step/s2) 	*/
#define MAX_SPEED 0x07	/*|Maximum speed 				| 10 	| 0x041   	| 248e-6 step/tick (991.8 step/s) 		*/
#define MIN_SPEED 0x08	/*|Minimum speed 				| 12 	| 0x000   	| 0 step/tick (0 step/s) 				*/
#define ADC_OUT 0x12	/*|ADC output 					| 5 	| 0xXX 		| 0 									*/
#define OCD_TH 0x13		/*|OCD threshold 				| 5 	| 0x8   	| TBD 									*/
#define FS_SPD 0x15		/*|Full-step speed 				| 11 	| 0x027   	| 150.7e-6 step/tick (602.7 step/s) 	*/
#define STEP_MODE 0x16	/*|Step mode 					| 8 	| 0x7 		| BUSY/SYNC output used as BUSY, 128 microsteps, voltage mode */
#define ALARM_EN 0x17 	/*|Alarm enables 				| 8		| 0xFF 		| All alarms enabled 					*/
#define GATECFG1 0x18 	/*|Gate driver Config 			| 11	| 0xTBD		| Igate = 4 mA, tCC = 125 ns, no boost 	*/
#define GATECFG2 0x19 	/*|Gate driver Config 			| 8		| 0xTBD 	| tBLANK = 125 ns, tDT = 125 ns 		*/
#define STATUS 0X1B 	/*|Status 						| 16 	| 0xXXXX  	| High impedance state, motor stopped, reverse direction, all fault flags released UVLO/reset flag set */
#define CONFIG 0x1A 	/*|IC Config 					| 16	| 0xTBD 	| Internal 16 MHz oscillator (OSCOUT at 2 MHz), SW event causes HardStop, overcurrent shutdown, VCC = 7.5 V, UVLO threshold low */
/*-Voltage mode configuration---------------------------------------------------------------------------------------------------------*/
#define KVAL_HOLD 0x09	/*|Holding KVAL 				| 8 	| 0x29	 	| 0.16·VS */
#define KVAL_RUN 0x0A	/*|Constant speed KVAL 			| 8 	| 0x29	 	| 0.16·VS */
#define KVAL_ACC 0x0B	/*|Accel. starting KVAL 		| 8 	| 0x29	 	| 0.16·VS */
#define KVAL_DEC 0x0C	/*|Decel. starting KVAL 		| 8 	| 0x29	 	| 0.16·VS */
#define INT_SPEED 0x0D	/*|Intersect speed 				| 14	| 0x0408	| 15.4e-6 step/tick (61.5 step/s) */
#define ST_SLP 0x0E		/*|Start slope 					| 8 	| 0x19	 	| 250.038% s/step */
#define FN_SLP_ACC 0x0F	/*|Accel. final slope 			| 8 	| 0x29	 	| 0.063% s/step 	*/
#define FN_SLP_DEC 0x10	/*|Decel. final slope 			| 8 	| 0x29	 	| 0.063% s/step 	*/
#define K_THERM 0x11	/*|Thermal compensation factor 	| 4 	| 0x0	 	| 1.0 			*/
#define STALL_TH 0x14	/*|STALL threshold 				| 5 	| 0x10	 	| TBD 			*/
/*-Current mode configuration--------------------------------------------------------------------------------------------------------*/
#define TVAL_HOLD 0x09  /*|Holding ref voltage 			| 8 	|	29 		| 328 mV 		*/
#define TVAL_RUN 0x0A  	/*|Constant speed ref voltage 	| 8 	|	29 		| 328 mV 		*/
#define TVAL_ACC 0x0B  	/*|Accel. ref voltage 			| 8 	|	29 		| 328 mV 		*/
#define TVAL_DEC 0x0C  	/*|Decel. ref voltage 			| 8 	|	29 		| 328 mV 		*/
#define T_FAST 0x0E  	/*|Fast decay setting 			| 8 	|	19 		| 1 μs / 5 μs 	*/
#define TON_MIN 0x0F  	/*|Minimum on-time 				| 8 	|	29 		| 20.5 μs 		*/
#define TOFF_MIN 0x10  	/*|Minimum off-time				| 8 	|	29 		| 20.5 μs 		*/


/* 
##############################
# Command Register Addresses #  
##############################
*/
/*-Commands without arguments --------------------------------------------------------------------------------------------------------*/
#define NOP 0x0				// 	000 0 0 00 0		Nothing
#define GOHOME 0x70			// 	011 1 0 00 0 		Brings the motor in HOME position
#define GOMARK 0x78			// 	011 1 1 00 0 		Brings the motor in MARK position
#define RESTEPOS 0xD8 		// 	110 1 1 00 0 		Resets the ABS_POS register (sets HOME position)
#define RESETDEVICE 0xC0	// 	110 0 0 00 0 		Device is reset to power-up conditions
#define SOFTSTOP 0xB0		// 	101 1 0 00 0 		Stops motor with a deceleration phase
#define HARDSTOP 0xB8		// 	101 1 1 00 0 		Stops motor immediately
#define SOFTHIZ 0xA0		// 	101 0 0 00 0 		Puts the bridges in high impedance status after a deceleration phase
#define HARDHIZ 0xA8		// 	101 0 1 00 0 		Puts the bridges in high impedance status immediately
#define GETSTATUS 0xD0		// 	110 1 0 00 0 		Returns the status register value
#define RESERVED1 0xEB 		// 	111 0 1 01 1 		RESERVED COMMAND
#define RESERVED2 0xF8		// 	111 1 1 00 0 		RESERVED COMMAND

/*-Commands with arguments --------------------------------------------------------------------------------------------------------*/
#define SETPARAM 0x00 	// SetParam(PARAM,VALUE) 	000 [PARAM] 		Writes VALUE in PARAM register
#define GETPARAM 0x01	// GetParam(PARAM) 			001 [PARAM] 		Returns the stored value in PARAM register
#define RUN	0x28		// Run(DIR,SPD) 			010 1 0 00 DIR 		Sets the target speed and the motor direction
#define STEPCLOCK 0x2C	// StepClock(DIR) 			010 1 1 00 DIR 		Puts the device in step-clock mode and imposes DIR direction
#define MOVE 0x20 		// Move(DIR,N_STEP) 		010 0 0 00 DIR 		Makes N_STEP (micro)steps in DIR direction (Not performable when motor is running)
#define GOTO 0x60		// GoTo(ABS_POS) 			011 0 0 00 0 		Brings motor in ABS_POS position (minimumpath)
#define GOTODIR	0x34	// GoTo_DIR(DIR,ABS_POS) 	011 0 1 00 DIR 		Brings motor in ABS_POS position forcing DIRdirection
#define GOUNTIL 0x08 	// GoUntil(ACT,DIR,SPD) 	100 0 ACT 01 DIR 	Performs a motion in DIR direction with speed SPD until SW is closed, the ACT action is executed then a SoftStop takes place
#define RELEASESW 0x09	// ReleseSW(ACT, DIR) 		100 1 ACT 01 DIR 	Performs a motion in DIR direction at minimum speed until the SW is released (open), the ACT action is executed then a HardStop takes place
#define GOUNTIL_AKT 0x41
#define GOUNTIL_NAKT 
#define RELEASESW_AKT
#define RELEASESW_NAKT

#define FORWARD 1		// For DIR : Direction
#define BACKWARD 0 		// For DIR : Direction



struct Motors
{
	uint32_t absPos;
	uint16_t elecPos;
	uint32_t markedPos;
	uint32_t currentSpeed; 
	uint16_t acceleration; 
	uint16_t deceleration; 
	uint16_t maxSpeed; 
	uint16_t minSpeed; 
	uint8_t stepMode;
	uint16_t configuration;
	

}Motor;

/*
#############################
# PSI Functions : Read Only	#
#############################
*/
uint8_t spi_getAdc(void);
uint16_t spi_getStatus(void);
uint32_t spi_getSpeed(void); 


/*
#####################################################################
# SPI Functions : Readable but Writable Only When Mottor is stopped #
#####################################################################
*/
uint32_t spi_setAbsPos(uint32_t position);
uint32_t spi_getAbsPos(void);

uint16_t spi_setElecPos(uint16_t position);
uint16_t spi_getElecPos(void);

uint16_t spi_setAccel(uint16_t acceleration);
uint16_t spi_getAccel(void);

uint16_t spi_setDecel(uint16_t deceleration);
uint16_t spi_getDecel(void);

uint16_t spi_setMinSpeed(uint16_t speed);
uint16_t spi_getMinSpeed(void);

uint8_t spi_setAlarm(uint8_t alarm); 
uint8_t spi_getAlarm(void); 


/*
################################################################################
# SPI Functions : Readable but Writable when the outputs are in high impedance #
################################################################################
*/
uint8_t spi_setStepMode(uint8_t stepMode); 
uint8_t spi_getStepMode(void);

uint32_t spi_setGateConfig(uint16_t configOne, uint8_t configTwo); 
uint32_t spi_getGateConfig(void); 

uint16_t spi_setConfig(uint16_t Configuration); // this function is the same for all mods plus general config.
uint16_t spi_getConfig(void);  

uint16_t spi_setIntersectSpeed(uint16_t speed); 
uint16_t spi_getIntersectSpeed(void); 

uint8_t spi_setStartSlope(uint8_t slope);
uint8_t spi_getStartSlope(void); 

uint8_t spi_setAccelSlope(uint8_t slope);
uint8_t spi_getAccelSlope(void); 

uint8_t spi_setDecelSlope(uint8_t slope);
uint8_t spi_getDecelSlope(void); 

uint8_t spi_setFastDecay(uint8_t decay); 
uint8_t spi_getFastDecay(void); 

uint8_t spi_setTonMin(uint8_t ton);
uint8_t spi_getTonMin(void); 

uint8_t spi_setToffMin(uint8_t toff);
uint8_t spi_getToffMin(void); 


/*
#################################################
# SPI Functions : Readable ans Writable anytime #
#################################################
*/
uint32_t spi_setMarkedPos(uint32_t position); 
uint32_t spi_getMarkedPos(void); 

uint16_t spi_setMaxSpeed(uint16_t speed);
uint16_t spi_getMaxSpeed(void);

uint8_t spi_setOcd(uint8_t ocd); 
uint8_t spi_getOcd(void);

uint16_t spi_setFullStepSpeed(uint16_t speed); // This function is the same in Current & Voltage Mode 
uint16_t spi_getFullStepSpeed(void); // This function is the same in Current & Voltage Mode 

uint16_t spi_setHoldingForce(uint8_t holding); // This function is the same in Current & Voltage Mode 
uint16_t spi_getHoldingForce(void); // This function is the same in Current & Voltage Mode 

uint16_t spi_setRunForce(uint8_t Runnning); // This function is the same in Current & Voltage Mode 
uint16_t spi_getRunForce(void); // This function is the same in Current & Voltage Mode 

uint16_t spi_setAccelForce(uint8_t Accelerating); // This function is the same in Current & Voltage Mode 
uint16_t spi_getAccelForce(void); // This function is the same in Current & Voltage Mode 

uint16_t spi_setDecelForce(uint8_t Decelerating); // This function is the same in Current & Voltage Mode 
uint16_t spi_getDecelForce(void); // This function is the same in Current & Voltage Mode 

uint8_t spi_setSTall(uint8_t stall); 
uint8_t spi_getSTall(void); 

/*
################################
# PSI Functions : Second Stage #
################################
*/

uint8_t spi_waitBussyFlag(void); 



