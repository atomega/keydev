#!/usr/bin/python

import sys
import smbus

argumentsNo = len(sys.argv) 

if argumentsNo == 3:
    bus = smbus.SMBus(1)    # 0 = /dev/i2c-0 (port I2C0), 1 = /dev/i2c-1 (port I2C1)
    DEVICE_ADDRESS = int(sys.argv[1], 16)
    I2C_REG = int(sys.argv[2], 16)
    
    while True:     
        try:
            i2cRecievedData = bus.read_byte_data(DEVICE_ADDRESS, I2C_REG)
            print("Recieved: ",hex(i2cRecievedData))
            break
        except IOError:
            print("Error: Read failed")
            break

    bus.close()

elif argumentsNo == 4:
    bus = smbus.SMBus(1)    # 0 = /dev/i2c-0 (port I2C0), 1 = /dev/i2c-1 (port I2C1)
    DEVICE_ADDRESS = int(sys.argv[1], 16)
    I2C_REG = int(sys.argv[2], 16)
    I2C_DATA = int(sys.argv[3], 16)

    while True: 
        try:  
            bus.write_byte_data(DEVICE_ADDRESS, I2C_REG, I2C_DATA)
            i2cRecievedData = bus.read_byte_data(DEVICE_ADDRESS, I2C_REG)
            print("New Data: ",hex(i2cRecievedData))
        except IOError:
            print("Error: Read failed")
            break

    bus.close()
