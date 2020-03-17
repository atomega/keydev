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
*	17032020    KeY      	1.0		First creation of it .h File creation
***********************************************************************
	TODO @ 17.03.2020
	****
	1: PLease change all vouds to corresponting return types 
	2: Manage error handling that is inexixtenet for now 
	3: Mange encapsulation Some methodes doesn't require Public access
	4: Kepp in mind that chaging Methodes on the future won't be an option
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


#ifndef BM_I2C_H_
#define BM_I2C_H_

using namespace std; 

#define uint8_t unsigned char
#define uint32_t unsigned long long

typedef enum
{
	I2C_STATE_RESET		= 1,	// Not Initialized
	I2C_STATE_READY		= 2,	// Ready
	I2C_STATE_TX		= 4,	// Transmitting
	I2C_STATE_RX		= 5,	// Receiving
	I2C_STATE_LISTEN	= 6,	// Listening
	I2C_STATE_ABORT		= 7,	// Aborted by user
	I2C_STATE_TIMEOUT	= 8,	// Timeout
	I2C_STATE_ERROR		= 9 	// Error happened
} bm_i2c_stateTypeDef;

typedef enum
{
	I2C_SPEED_STANDART	= 1,	// Sm	100 kbits/s This mode will be choosen for the constructor. 
	I2C_SPEED_FAST		= 2,	// Fm	400 kbits/s 
	I2C_SPEED_FAST_PLUS	= 3,	// Fm+	1	Mbits/s
	I2C_SPEED_HIGH_SPEED= 4, // Hs	3.4 Mbits/s 
	I2C_SPEED_ULTRA_FAST= 5	// UFm	5	Mbits/s
} bm_i2c_speedTypeDef; // PLease note that speed modes engender a behavioural change

typedef enum
{
	I2C_ADDRESS_7B	= 1,	// 7  bits addressing mode  
	I2C_ADDRESS_10B = 2	// 10 bits addressing mode  
} bm_i2c_addressTypeDef;




class bm_i2c
{
	public :
		
		/*Methods*/
		bm_i2c_speedTypeDef testDeviceSpeed(); // Cycle trough different modes until device cnat't answer fast enought

		uint8_t discoverDevices(); // Scan the awailable address range on standart mode to find devices (please set timout to a reasonable value) similar as Linux 
		
		uint8_t checkPullUps();		// Not a hardware check it will only check if communicaion is possible without errors

		void send(uint8_t *Data, uint8_t Lenght);      	//Send a given number of bytes 
		void receive(uint8_t *Buffer, uint8_t Lenght);	//Read a given number of bytes
		
		void softReset();			// Software reset not supported by all hardware.
		void clockSynchronise();	// Clock Syncronization
		void abortTransmit();		// Stop Communication for multimaster mode 
		void arbitration();			// Arbitration for multimaster mode to define the right master. 
		void clockStretch();		// Optional For Pausing Communication because treatement takes longer than the communication
		void freeChannel();			// Can be used for MCU but initialy thougt for linux
		void initChannel();			// Can be used for MCU but initialy thougt for linux
		void busClear();			// in case if SCL is stuck 
		void readDeviceInfo();		// 3 Bytes (24 its) Read Only Register | 12 Bits : Manufacturer info | 9 Bits: Part Identification | 3 Bits DIE Rev. 

		/*getters*/
		uint8_t getError() const;
		uint8_t getMode() const;
		uint32_t getTimeout() const;
		uint8_t getAddressMode() const;
		uint8_t getInterrupt() const;
		uint8_t getAddress() const;
		uint8_t getsetDma() const;

		/*Setters*/
		void setTimeout(uint8_t m_timeout);
		void setAddressMode();
		void setInterrupt();
		void setAddress();
		void setDma();

		bm_i2c(uint8_t channel, uint8_t address, uint8_t DMA);
		~bm_i2c();

	private :
		bm_i2c_addressTypeDef m_adressMode; // Address of the device to be communicated
		bm_i2c_speedTypeDef m_speed;		// Trasmission speed
		bm_i2c_stateTypeDef m_state;		// Current state of this i2c Object

		uint8_t m_channel; 					// Selection of I2C Hardware Channel
		uint8_t m_adress;  					// Address of the device to be communicated
		uint8_t *m_bufferPointer; 			// Buffer pointer for data to be sent & received
		uint8_t m_transferCount; 			// Internal counter for the count of data Transfer
		uint32_t m_timeout;					// Timeout for managing communication breaks
		uint32_t m_interrupttFlags; 		// Interrupt flag that would be sent
		uint32_t m_interruptSource;			// From what this interrupt is coming
		uint32_t m_error; 					// The error code corresponding to that error

		volatile uint8_t m_transferSize;	// Size of the data to be sent or received
};


#endif /* BM_I2C_H_ */
