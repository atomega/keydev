#!/bin/bash

mutePin=17
enabelPin=27
powerPin=22
volume=55
bitRate=32

powerUp()
{
	sudo echo "0" > /sys/class/gpio/gpio$powerPin/value
	echo "Amplifier powered up"
}


volup()
{
	/home/pi/github/keydev/code/python/raspberry/ma12070/volup.py
}

voldown()
{
	/home/pi/github/keydev/code/python/raspberry/ma12070/voldown.py
}

powerDown()
{
	sudo echo "1" > /sys/class/gpio/gpio$powerPin/value
	echo "Amplifier powered down"
}


muteAmp()
{
	sudo echo "0" > /sys/class/gpio/gpio$mutePin/value
	echo "Amplifier is muted"

}

unmuteAmp()
{
	sudo echo "1" > /sys/class/gpio/gpio$mutePin/value
	echo "Amplifier is unmuted"
}

enableAmp()
{
	sudo echo "0" > /sys/class/gpio/gpio$enabelPin/value
	echo "Amplifier is enabeled"
}

disableAmp()
{
	sudo echo "1" > /sys/class/gpio/gpio$enabelPin/value
	echo "Amplifier is disabeled"
}

configurePins()
{
	sudo echo "$mutePin" > /sys/class/gpio/export
	sudo echo "$enabelPin" > /sys/class/gpio/export
	sudo echo "$powerPin" > /sys/class/gpio/export
	sudo echo "out" > /sys/class/gpio/gpio$mutePin/direction
	sudo echo "0" > /sys/class/gpio/gpio$mutePin/value
	sudo echo "out" > /sys/class/gpio/gpio$enabelPin/direction
	sudo echo "1" > /sys/class/gpio/gpio$enabelPin/value
	sudo echo "out" > /sys/class/gpio/gpio$powerPin/direction
	sudo echo "1" > /sys/class/gpio/gpio$powerPin/value
	echo "Pins for amplifier are configured"
}

clearPins()
{
	sudo echo "$mutePin" > /sys/class/gpio/unexport
	sudo echo "$enabelPin" > /sys/class/gpio/unexport
	sudo echo "$powerPin" > /sys/class/gpio/unexport
	echo "Pins for amplifier are set to system default"
}

initAmp()
{
	/home/pi/github/keydev/code/cpp/runtest $bitRate $volume
}

if [ -z "$1" ];
then
	echo "Please entre a command"
fi

if [ "$1" == "configure" ];
then
	configurePins
fi

if [ "$1" == "disconfigure" ];
then
	clearPins
fi
	
if [ "$1" == "power" ];
then
	powerUp
fi

if [ "$1" == "shutdown" ];
then
	powerDown
fi

if [ "$1" == "mute" ];
then
	muteAmp
fi

if [ "$1" == "unmute" ];
then
	unmuteAmp
fi

if [ "$1" == "enable" ];
then
	enableAmp
fi

if [ "$1" == "disable" ];
then
	disableAmp
fi

if [ "$1" == "volup" ];
then
	volup
fi

if [ "$1" == "voldown" ];
then
	voldown
fi

if [ "$1" == "start" ];
then
	powerUp
	read -p "" -t 0.1
	enableAmp
	read -p "" -t 0.1
	initAmp
	read -p "" -t 0.1
	unmuteAmp
	echo "Amplifier has started"
fi

if [ "$1" == "stop" ];
then
	muteAmp
	read -p "" -t 0.1
	disableAmp
	read -p "" -t 0.1
	powerDown
	echo "Amplifier has stoped"
fi