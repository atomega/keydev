#!/bin/bash

mutePin=17
enabelPin=27
powerPin=22

powerUp()
{
	sudo echo "1" > /sys/class/gpio/gpio$powerPin/value
	echo "Amplifier powered up"
}

powerDown()
{
	sudo echo "0" > /sys/class/gpio/gpio$powerPin/value
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
	sudo echo "0" > /sys/class/gpio/gpio$powerPin/value
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
	/home/pi/github/keydev/code/cpp/runtest 64 35
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

if [ "$1" == "start" ];
then
	configurePins
	powerUp
	enableAmp
	initAmp
	unmuteAmp
	echo "Amplifier has started"
fi

if [ "$1" == "stop" ];
then
	muteAmp
	disableAmp
	powerDown
	clearPins
	echo "Amplifier has stoped"
fi
