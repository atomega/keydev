#!/bin/sh

sleep 3
./gpioSetup.sh

./enableAmp.sh 
./runtest

./unmuteAmp.sh

echo "Done"
