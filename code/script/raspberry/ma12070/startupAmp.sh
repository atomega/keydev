#!/bin/sh

sleep 3
~/keydev/code/script/raspberry/ma12070/gpioSetup.sh

~/keydev/code/script/raspberry/ma12070/enableAmp.sh 

~/keydev/code/cpp/runtest

~/keydev/code/script/raspberry/ma12070/unmuteAmp.sh

echo "Done"
