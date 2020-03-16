#!/usr/bin/python

import os
from max31850 import read_temp

cmd_beginning = 'echo Temp = '
cmd_end = 'C | msmtp kerem.yollu@gmail.com'
cmd_temp = read_temp()

cmd = cmd_beginning + cmd_temp + cmd_end  

os.system(cmd)
