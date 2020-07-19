#!/bin/sh

rm /home/$USER/keydev/code/script/raspberry/ma12070/ampLog.txt
touch /home/$USER/keydev/code/script/raspberry/ma12070/ampLog.txt
#sudo chmod +wx /home/$USER/keydev/code/script/raspberry/ma12070/ampLog.txt

sudo /home/$USER/keydev/code/script/raspberry/ma12070/gpioSetup.sh

sudo /home/$USER/keydev/code/script/raspberry/ma12070/enableAmp.sh 

sudo /home/$USER/keydev/code/cpp/runtest 64 35 > /home/$USER/keydev/code/script/raspberry/ma12070/ampLog.txt

sudo /home/$USER/keydev/code/script/raspberry/ma12070/unmuteAmp.sh

echo "Done"
