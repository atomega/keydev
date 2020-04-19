#!/bin/sh

sleep 3
./gpioSetup.sh

./enableAmp.sh 

/home/pi/keydev/code/c/runtest

./unmuteAmp.sh

echo "Done"
