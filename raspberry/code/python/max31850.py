#!/usr/bin/python

import glob
import time

device_file = '/sys/bus/w1/devices/3b-0df40b41f895/w1_slave'

def read_temp_raw():
  f = open(device_file, 'r')
  lines = f.readlines()
  f.close()
  return lines

def read_temp():
  lines = read_temp_raw()
  while lines[0].strip()[-3:] != 'YES':
		lines = read_temp_raw()
  equals_pos = lines[1].find('t=')
  if equals_pos != -1:
		temp_string = lines[1][equals_pos+2:]
		temp_c = float(temp_string) / 1000.0
		temp_c = temp_c - 4
#		f= open("data.txt","w+")
#		f.write("Temp : %.2f C" %round(temp_c,2))
#		f.close
		print(str(temp_c))

while True:
	read_temp()
	time.sleep(2)
