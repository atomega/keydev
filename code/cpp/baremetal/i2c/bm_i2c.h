/**********************************************************************
* Project       : Library for Bare Metal Adaptation
* Program name 	: bm_i2c
* Author        : KeY(kerem.yollu@gmail.com) & Edwin Koch
* Contributors	: 
* Date created 	: 17.03.2020
***********************************************************************
* Purpose		:
* Build an Bare Metal adaptation thought to be used in combination with abstraction layers provided by CPU & MCU Manufacturers.
* The Objective would be to keep the .h File as it is and only modify the .c file according to the provided support from a 3rd party.
* Those supports could be a Abstraction layer from a manufacturer or Kernel functions.
* All is up to you creativity an needs
* 
*	Notice : The following third Party Protocols based on I2C Bus are not going to be implemented : C-BUS SMBUS PMBUS IPMI DDC ATCA		
*
* Referece Material :
*	- NXP	: UM10204.PDF
*	- Linux : Kernel I2C Module
***********************************************************************
* 	Revision History
* 	****************
*	Date		Author		V		Revision (Date in YYYYMMDD format)
*	22032020    KeY      	1.0		First creation of it .h File creation
***********************************************************************
	TODO @ 22.03.2020
	****
	1: Manage error handling that is inexixtenet for now 
***********************************************************************

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/


#pragma once

#include <stdint.h>

using namespace std; 
class bm_i2c
{
	public :
		typedef enum
		{
			I2C_STATE_RESET		= 1,// Not Initialized
			I2C_STATE_READY		= 2,// Ready
			I2C_STATE_TX		= 4,// Transmitting
			I2C_STATE_RX		= 5,// Receiving
			I2C_STATE_LISTEN	= 6,// Listening
			I2C_STATE_ABORT		= 7,// Aborted by user
			I2C_STATE_TIMEOUT	= 8,// Timeout
			I2C_STATE_ERROR		= 9	// Error happened
		}	bm_i2c_state_t;			// Typical Low Level Communication states

		typedef enum
		{
			I2C_SPEED_STANDART		= 1,// Sm	100 kbits/s This mode will be choosen for the constructor. 
			I2C_SPEED_FAST			= 2,// Fm	400 kbits/s 
			I2C_SPEED_FAST_PLUS		= 3,// Fm+	1	Mbits/s
			I2C_SPEED_HIGH_SPEED	= 4,// Hs	3.4 Mbits/s 
			I2C_SPEED_ULTRA_FAST	= 5	// UFm	5	Mbits/s
		}	bm_i2c_speed_t;				// Please note that speed modes engender a behavioural change

		typedef enum
		{
			I2C_ADDRESS_7B	= 1,// 7  bits addressing mode  
			I2C_ADDRESS_10B = 2	// 10 bits addressing mode  
		}	bm_i2c_address_t;	// Doest not require a hardware support -> device adress is sent differently

		typedef enum
		{
			I2C_MODE_MASTER			= 1,// Single Master Mode
			I2C_MODE_SLAVE			= 2,// Slave Mode
			I2C_MODE_MULTI_MASTER	= 3	// Multy Master Mode
		}	bm_i2c_mode_t;				// Only algorithm changes
	
		/*Constructor destructor*/
		bm_i2c(uint8_t channel, uint16_t address, bm_i2c_mode_t mode); // Creat i2c abject witha agiven channel address & mode speed is by default the slowest.
		~bm_i2c();

		/*Methods*/

		void receive(uint8_t *Buffer, uint8_t *Register, uint8_t *Lenght);	// Defined by me : Read a given number of bytes
		void send(uint8_t *Data, uint8_t *Register, uint8_t *Lenght);			// Defined by me : Send a given number of bytes 
		uint8_t testDeviceSpeed();											// Defined by me : Cycle trough different modes until device cnat't answer fast enought
		uint8_t discoverDevices();											// Defined by me : Scan the awailable address range on standart mode to find devices   
		
		void initChannelAsMaster();	// Hardware Specific : Initilise the hardware channel in master mode
		void initChannelAsSlave();	// Hardware Specific : Initilise the hardware channel in slavic mode (@life of boris)
		void freeChannel();			// Hardware Specific : Free the hardware channel for othe recousrces

		void clockSynchronise();// I2C Standart : Clock Syncronization
		void readDeviceInfo();	// I2c Standart : 3 Bytes (24 bits) | 12 Bits : Manufacturer info | 9 Bits: Part Identification | 3 Bits DIE Rev. 
		void abortTransmit();	// I2c Standart : Stop Communication for multimaster mode 
		void clockStretch();	// I2C Standart : Optional For Pausing Communication because treatement takes longer than the communication
		void arbitration();		// I2C Standart : Arbitration for multimaster mode to define the right master. 
		void softReset();		// I2C Standart : Software reset not supported by all hardware.
		void busClear();		// I2C Standart : in case if SCL is stuck 

		/*Setters*/
		void setSpeed(bm_i2c_speed_t speed);	// I2C Standart 
		void setAddress(uint8_t address);		// I2C Standart 
		void setAddressMode();					// I2C Standart

		void setTimeout(uint8_t m_timeout);		// Hardware specific
		void setInterrupt();					// Hardware Specific
		void setDma();							// Hardware specific 	
		
		/*getters*/
		uint8_t getIcIdentification()const;
		uint8_t getIcRevision() const;
		uint8_t getInterrupt() const;
		uint8_t getAddress()const;
		uint8_t getError() const;
		uint16_t getIcManufacturer() const;
		uint32_t getTimeout() const;
		uint8_t getAddressMode() const;
		uint8_t getMode() const;	
		

		void throwI2cError(int16_t error);					// Defined by me : Private error function for error handling
		void write16(uint8_t *Data, uint8_t* Register); 
		void read8(uint8_t *Data, uint8_t* Register); 
	private :
		
		bm_i2c_address_t m_addressMode;	// I2C Standart : Address type of the device to be communicated
		uint16_t m_address;				// I2c Standrat : Address of the device to be communicated or our Slave address in Slave mode
		bm_i2c_speed_t m_speed;			// I2C Standart : Trasmission speed
		uint16_t m_icManufacturer;		// I2C Standart : Device information from manufacturer 
		uint8_t m_icIdentification;		// I2C Standart : Device information from manufacturer
		uint8_t m_icRevision;			// I2C Standart : Device information from manufacturer
		bm_i2c_mode_t m_mode;			// I2C Standart : Mode of our device

		char m_fileName[20];			// Linux : i2c file name
		uint16_t m_fileDescriptor;		// Linux : i2c file description
		
		bm_i2c_state_t m_state;			// Defined by me : Current state of this i2c Object

		uint8_t m_channel;				// Hardware Specific : Selection of I2C Channel
		uint32_t m_interrupttFlags; 	// Hardware Specific : Interrupt flag
		uint32_t m_interruptSource;		// Hardware Specific : Interrupt cause
		
		uint8_t *m_bufferPointer;		// Buffer pointer for data to be sent & received
		uint8_t *m_regPointer;			// Register pointer for data to be sent & received
		uint8_t m_dataFrame[4];			// Data frame to get the right order of data
		uint8_t m_transferCount;		// Internal counter for the count of data Transfer
		uint32_t m_timeout;				// Timeout for managing communication breaks
		int16_t m_error;				// The error code corresponding to that error
		volatile uint8_t m_transferSize;// Size of the data to be sent or received
};

