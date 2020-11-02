#!/usr/bin/python

import sys
import smbus

argumentsNo = len(sys.argv) 

if argumentsNo == 3:
    bus = smbus.SMBus(1)    # 0 = /dev/i2c-0 (port I2C0), 1 = /dev/i2c-1 (port I2C1)
    DEVICE_ADDRESS = int(sys.argv[1], 16)
    I2C_REG = int(sys.argv[2], 16)
    i2cRecievedData = bus.read_byte_data(DEVICE_ADDRESS, I2C_REG)
    bus.close();
    print(hex(i2cRecievedData))

elif argumentsNo == 4:
    bus = smbus.SMBus(1)    # 0 = /dev/i2c-0 (port I2C0), 1 = /dev/i2c-1 (port I2C1)
    DEVICE_ADDRESS = int(sys.argv[1], 16)
    I2C_REG = int(sys.argv[2], 16)
    I2C_DATA = int(sys.argv[3], 16)
    bus.write_byte_data(DEVICE_ADDRESS, I2C_REG, I2C_DATA)
    i2cRecievedData = bus.read_byte_data(DEVICE_ADDRESS, I2C_REG)
    bus.close();
    print(hex(i2cRecievedData))
