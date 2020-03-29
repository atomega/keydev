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
*	- Linux : https://www.kernel.org/doc/Documentation/i2c/dev-interface
***********************************************************************
* 	Revision History
* 	****************
*	Date		Author		V		Revision (Date in YYYYMMDD format)
*	22032020    KeY      	1.0		First creation of it .h File creation
***********************************************************************
	TODO @ 22.03.2020
	****
	1: 
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

#include "bm_i2c.h"
#include <stdio.h>
#include <stdint.h>

/* User Includes */
#include <cstdio>
#include <ostream>
#include <iostream>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
/* End User defines */


using namespace std; 

// Creat i2c abject witha agiven channel address & mode speed is by default the slowest.
bm_i2c::bm_i2c(uint8_t channel, uint16_t address, bm_i2c_mode_t mode, bm_i2c_address_t addressMode) 
: m_channel(channel), m_address(address), m_mode(mode), m_addressMode(addressMode)
{ 
	m_state = I2C_STATE_RESET; 
	m_icIdentification = 0; 
	m_icManufacturer = 0; 
	m_icRevision = 0; 

	switch(m_mode)
    {
		case I2C_MODE_MASTER :
			i2c_initChannelAsMaster(); 
			i2c_setAddress(m_address); 
			m_state = I2C_STATE_READY; 
		break; 
	 
		case I2C_MODE_SLAVE : 
			i2c_initChannelAsSlave(); 
			i2c_setAddress(m_address); 
			m_state = I2C_STATE_READY; 
		break; 

		case I2C_MODE_MULTI_MASTER :
			i2c_initChannelAsMaster(); 
			i2c_setAddress(m_address); 
			m_state = I2C_STATE_READY; 
		break; 
	}	
}

bm_i2c::~bm_i2c()
{
	i2c_freeChannel(); 
}


// Hardware Specific : Initilise the hardware channel in master mode
void bm_i2c::i2c_initChannelAsMaster()
{
	snprintf(m_fileName, 19, "/dev/i2c-%d", m_channel);
	
	m_fileDescriptor = open(m_fileName, O_RDWR);
	
	if (m_fileName < 0) 
	{	
		i2c_throwError(__LINE__); 
	}
}

void bm_i2c::i2c_setAddress(uint16_t address)
{		 
	switch (m_addressMode)
	{
		case I2C_ADDRESS_7B: 
			m_address = address;
			m_internalBuffer[0] = address & ((1 << 8)-1);
		break;
	
		case I2C_ADDRESS_10B:

		break;
			
	}
	m_state	= I2C_STATE_RESET; 
	m_error = ioctl(m_fileDescriptor, I2C_SLAVE,m_internalBuffer[0]);
	if (m_error < 0) 
	{	
		i2c_throwError(__LINE__); 
		m_state = I2C_STATE_ERROR; 
	}
}


// Defined by me :Read a given number of bytes
void bm_i2c::i2c_receive(uint8_t *reg, uint8_t *buffer, uint8_t *regLenght, uint8_t *bufferLenght)
{
	if (*bufferLenght == *regLenght)
	{
		for(m_transferCount = 0 ; m_transferCount < *bufferLenght ; m_transferCount++ )
		{	
			i2c_pointReg(&reg[m_transferCount]);
			if ((read(m_fileDescriptor,&buffer[m_transferCount],1 )) != 1) 										 
			{	
				i2c_throwError(__LINE__); 
			}
		}
	}
	else if (*bufferLenght > *regLenght  &&  *regLenght == 1)
	{
		i2c_pointReg(reg);
		if ((read(m_fileDescriptor,buffer, *bufferLenght)) != *bufferLenght) 										 
		{	
			i2c_throwError(__LINE__); 
		}
		else
		{
			cout << "write Done " << endl; 
		}
	}
}

// Defined by me : Send a given number of bytes
void bm_i2c::i2c_send(uint8_t *reg, uint8_t *data, uint8_t *regLenght, uint8_t *dataLenght)
{
	if (*regLenght == 1 && *dataLenght ==0)
	{
		i2c_pointReg(reg);
	}
	else if (*regLenght == *dataLenght)
	{
		for(m_transferCount = 0 ; m_transferCount < *regLenght; m_transferCount++ )
		{ 
			m_internalBuffer[0] = reg[m_transferCount]; 
			m_internalBuffer[1] = data[m_transferCount]; 

			if ((write(m_fileDescriptor, m_internalBuffer, 2)) != 2) 										
			{
				i2c_throwError(__LINE__); 
			}	
		}
	}
	else if (*regLenght == 1 && *dataLenght > *regLenght )
	{
		i2c_pointReg(reg);

		for(m_transferCount = 1 ; m_transferCount < *regLenght; m_transferCount++ )
		{ 
			m_internalBuffer[1] = data[m_transferCount]; 

			if ((write(m_fileDescriptor, m_internalBuffer, 2)) != 2) 										
			{
				i2c_throwError(__LINE__); 
			}	
		}
	}
}

// Defined by me : Points to the register to be red from 
void bm_i2c::i2c_pointReg(uint8_t * reg)
{
	if ((write(m_fileDescriptor,reg, 1)) != 1) 										
	{	
		i2c_throwError(__LINE__);  
	}
}

// Defined by me : Cycle trough different modes until device cnat't answer fast enought
uint8_t bm_i2c::i2c_testDeviceSpeed()
{
	//TODO : Implement it	
	return 0;
}							


// Hardware Specific : Initilise the hardware channel in slave mode
void bm_i2c::i2c_initChannelAsSlave()
{
}

// Hardware Specific : Free the hardware channel for othe recousrces
void bm_i2c::i2c_freeChannel()
{
	close(m_fileDescriptor); 
}			

// I2C Standart : Clock Syncronization
void bm_i2c::i2c_clockSynchronise(){}
// I2c Standart : 3 Bytes (24 its) Read Only reg | 12 Bits : Manufacturer info | 9 Bits: Part Identification | 3 Bits DIE Rev.
void bm_i2c::i2c_readDeviceInfo(){}	 
// I2c Standart : Stop Communication for multimaster mode
void bm_i2c::i2c_abortTransmit(){}	 
// I2C Standart : Optional For Pausing Communication because treatement takes longer than the communication
void bm_i2c::i2c_clockStretch(){}	
// I2C Standart : Arbitration for multimaster mode to define the right master.
void bm_i2c::i2c_arbitration(){}		 
// I2C Standart : Software reset not supported by all hardware.
void bm_i2c::i2c_softReset(){}		
// I2C Standart : in case if SCL is stuck
void bm_i2c::i2c_busClear(){}

void bm_i2c::i2c_setSpeed(bm_i2c_speed_t speed){}
void bm_i2c::i2c_setAddressMode(){}
void bm_i2c::i2c_setTimeout(uint8_t m_timeout){}
void bm_i2c::i2c_setInterrupt(){}
void bm_i2c::i2c_setDma(){}
uint8_t bm_i2c::i2c_getIcIdentification() const
{
	return m_icIdentification; 	
}

uint8_t bm_i2c::i2c_getIcRevision()	const
{
	return m_icRevision;  
}

uint8_t bm_i2c::i2c_getInterrupt() const
{
	return m_interrupttFlags; 
}

uint8_t bm_i2c::i2c_getAddress() const
{
	return m_address; 
}

uint8_t bm_i2c::i2c_getError() const
{
	return m_error; 
}

uint16_t bm_i2c::i2c_getIcManufacturer() const
{
	return m_icManufacturer; 
}

uint32_t bm_i2c::i2c_getTimeout() const
{
	return m_timeout; 
}


uint8_t bm_i2c::i2c_getAddressMode() const
{
	return m_addressMode; 	
}


void bm_i2c::i2c_throwError(int16_t error)
{
	cout << "An error has been generated on line : >>" << error << "<< " << endl << "Operation aborded anc channel closed" << endl; 
	m_state = I2C_STATE_ERROR; 
}


