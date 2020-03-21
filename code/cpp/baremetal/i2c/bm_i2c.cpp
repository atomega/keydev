/**********************************************************************
  i* Project       : Library for Bare Metal Adaptation
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

#include "bm_i2c.h"
#include <stdio.h>
#include <stdint.h>
#include <cstdio>
#include <ostream>
#include <iostream>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
using namespace std; 

void bm_i2c::throwI2cError(uint16_t error)
{
	cout << "an error has been generated " << error << "Operation aborded anc channel closed" << endl; 
	m_state = I2C_STATE_ERROR; 
}

void bm_i2c::setAddress(uint8_t address)
{
	m_address = address;
	m_state = I2C_STATE_RESET; 
	m_error = ioctl(m_fileDescriptor, I2C_SLAVE,m_address);  
	
	if (m_error < 0) 
	{	
		throwI2cError(m_error); 
		m_state = I2C_STATE_ERROR; 
	}
	else
	{
		m_error = 0	;	
	}
}

void bm_i2c::initChannel()
{
	m_state = I2C_STATE_RESET; 
	snprintf(m_fileName, 19, "/dev/i2c-%d", m_channel);
	
	m_fileDescriptor = open(m_fileName, O_RDWR);
	
	if (m_fileName < 0) 
	{	
		throwI2cError(m_fileDescriptor); 
		m_state = I2C_STATE_ERROR; 
	}
	else 
	{
		m_error = 0 ; 
	}
	
}


bm_i2c::bm_i2c(uint8_t channel, uint8_t address, uint8_t DMA) : m_channel(channel), m_address(address), m_dma(DMA)  
{ 	
	initChannel(); 
	setAddress(m_address); 
	m_state = I2C_STATE_READY;
}
