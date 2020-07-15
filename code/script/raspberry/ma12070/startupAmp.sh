#!/bin/sh

sudo /home/osmc/keydev/code/script/raspberry/ma12070/gpioSetup.sh

sudo /home/osmc/keydev/code/script/raspberry/ma12070/enableAmp.sh 

sudo /home/osmc/keydev/code/cpp/runtest 64 35 > /home/osmc/keydev/code/script/raspberry/ma12070/ampLog.txt

sudo /home/osmc/keydev/code/script/raspberry/ma12070/unmuteAmp.sh

echo "Done"
