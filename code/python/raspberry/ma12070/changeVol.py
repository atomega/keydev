#!/usr/bin/python

import smbus

bus = smbus.SMBus(1)    # 0 = /dev/i2c-0 (port I2C0), 1 = /dev/i2c-1 (port I2C1)

DEVICE_ADDRESS = 0x20      #7 bit address (will be left shifted to add the read write bit)
I2C_REG = 0x40
VOLUME = 0x35

#Write a single register
y = bus.read_byte_data(DEVICE_ADDRESS, I2C_REG)
print y

#bus.write_byte_data(DEVICE_ADDRESS, DEVICE_REG_MODE1, DEVICE_REG_LEDOUT0)
