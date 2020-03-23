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
bm_i2c::bm_i2c(uint8_t channel, uint16_t address, bm_i2c_mode_t mode) 
: m_channel(channel), m_address(address), m_mode(mode)
{ 
	m_state = I2C_STATE_RESET; 
	m_icIdentification = 0; 
	m_icManufacturer = 0; 
	m_icRevision = 0; 

	switch(m_mode)
    {
		case I2C_MODE_MASTER :
			initChannelAsMaster(); 
			setAddress(m_address); 
			m_state = I2C_STATE_READY; 
		break; 
	 
		case I2C_MODE_SLAVE : 
			initChannelAsSlave(); 
			setAddress(m_address); 
			m_state = I2C_STATE_READY; 
		break; 

		case I2C_MODE_MULTI_MASTER :
			initChannelAsMaster(); 
			setAddress(m_address); 
			m_state = I2C_STATE_READY; 
		break; 
	}	
}

bm_i2c::~bm_i2c()
{
	freeChannel(); 
}


// Hardware Specific : Initilise the hardware channel in master mode
void bm_i2c::initChannelAsMaster()
{
	/*Usercode*/			
	snprintf(m_fileName, 19, "/dev/i2c-%d", m_channel);
	
	m_fileDescriptor = open(m_fileName, O_RDWR);
	
	if (m_fileName < 0) 
	{	
		throwI2cError(__LINE__); 
	}
	/*Edocresu*/	
}

void bm_i2c::setAddress(uint8_t address)
{		 
	/*Usercode*/			
	m_address = address;
	m_state = I2C_STATE_RESET; 
	m_error = ioctl(m_fileDescriptor, I2C_SLAVE,m_address);  
	
	if (m_error < 0) 
	{	
		throwI2cError(__LINE__); 
		m_state = I2C_STATE_ERROR; 
	}
	/*Edocresu*/
}
	 

// Defined by me :Read a given number of bytes
void bm_i2c::receive(uint8_t *Buffer, uint8_t *Register, uint8_t *Lenght)
{
	/*Usercode*/			
	for(m_transferCount = 0 ; m_transferCount < *Lenght; m_transferCount++ )
	{	
	}
}

// Defined by me : Send a given number of bytes
void bm_i2c::send(uint8_t *Data, uint8_t *Register, uint8_t *Lenght)
{
	for(m_transferCount = 0 ; m_transferCount < *Lenght; m_transferCount++ )
	{ 
		m_dataFrame[0] = *Register; 
		m_dataFrame[1] = *Data;
		if (write(m_fileDescriptor, m_dataFrame, 2) != 2)
		{
			throwI2cError(__LINE__); 
		}
	}
}

void bm_i2c::write16(uint8_t *Data, uint8_t* Register)
{
	m_dataFrame[0] = *Register; 
	m_dataFrame[1] = *Data; 

	if ((write(m_fileDescriptor, m_dataFrame, 2)) != 2) 										
	{														
		throwI2cError(__LINE__); 
	}	
}
 
void bm_i2c::read8(uint8_t *Data, uint8_t* Register)
{
	if ((write(m_fileDescriptor, Register, 1)) != 1) 										
	{	
		throwI2cError(__LINE__);  
	}
	else 
	{	
		if ((read(m_fileDescriptor, m_dataFrame, 1)) != 1) 										 
		{	
			throwI2cError(__LINE__); 
		}
	}	
}
 

// Defined by me : Cycle trough different modes until device cnat't answer fast enought
uint8_t bm_i2c::testDeviceSpeed()
{
	//TODO : Implement it	
	return 0;
}							


// Hardware Specific : Initilise the hardware channel in slave mode
void bm_i2c::initChannelAsSlave()
{
	/*Usercode*/			
	/*Edocresu*/
}

// Hardware Specific : Free the hardware channel for othe recousrces
void bm_i2c::freeChannel()
{
	/*Usercode*/			
	close(m_fileDescriptor); 
	/*Edocresu*/
}			


// I2C Standart : Clock Syncronization
void bm_i2c::clockSynchronise()
{
	/*Usercode*/			
	/*Edocresu*/
}
// I2c Standart : 3 Bytes (24 its) Read Only Register | 12 Bits : Manufacturer info | 9 Bits: Part Identification | 3 Bits DIE Rev.
void bm_i2c::readDeviceInfo()
{
	/*Usercode*/			
	/*Edocresu*/
}	 
// I2c Standart : Stop Communication for multimaster mode
void bm_i2c::abortTransmit()
{
	/*Usercode*/			
	/*Edocresu*/
}	 
// I2C Standart : Optional For Pausing Communication because treatement takes longer than the communication
void bm_i2c::clockStretch()
{
	/*Usercode*/			
	/*Edocresu*/
}	
// I2C Standart : Arbitration for multimaster mode to define the right master.
void bm_i2c::arbitration()
{
	/*Usercode*/			
	/*Edocresu*/
}		 
// I2C Standart : Software reset not supported by all hardware.
void bm_i2c::softReset()
{
	/*Usercode*/			
	/*Edocresu*/
}		
// I2C Standart : in case if SCL is stuck
void bm_i2c::busClear()
{
	/*Usercode*/			
	/*Edocresu*/
}


void bm_i2c::setSpeed(bm_i2c_speed_t speed)
{
}

		 
void bm_i2c::setAddressMode()
{
	
}
					

void bm_i2c::setTimeout(uint8_t m_timeout)
{
	
}
	
void bm_i2c::setInterrupt()
{
	
}
			
void bm_i2c::setDma()
{
	
}

uint8_t bm_i2c::getIcIdentification() const
{
	return m_icIdentification; 	
}

uint8_t bm_i2c::getIcRevision()	const
{
	return m_icRevision;  
}

uint8_t bm_i2c::getInterrupt() const
{
	return m_interrupttFlags; 
}

uint8_t bm_i2c::getAddress() const
{
	return m_address; 
}

uint8_t bm_i2c::getError() const
{
	return m_error; 
}

uint16_t bm_i2c::getIcManufacturer() const
{
	return m_icManufacturer; 
}

uint32_t bm_i2c::getTimeout() const
{
	return m_timeout; 
}


uint8_t bm_i2c::getAddressMode() const
{
	return m_addressMode; 	
}


void bm_i2c::throwI2cError(int16_t error)
{
	cout << "An error has been generated on line : >>" << error << "<< " << endl << "Operation aborded anc channel closed" << endl; 
	m_state = I2C_STATE_ERROR; 
}


