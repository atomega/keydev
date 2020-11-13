#!/bin/bash

mutePin=17
enabelPin=27
powerPin=22
volume=55
bitRate=64

helpInfo()
{
	echo "Please entre a command"
	echo "-> disconfigure : Clearing the control pins"
	echo "-> power : Turns the relay on"
	echo "-> shutdown : turns the relay off"
	echo "-> mute : mutes the amplifier output stage"
	echo "-> enable : enable amplifier for opretaion and serial communication"
	echo "-> disable : disable the amplifier"
	echo "-> volup : Send serial command to up the volume"
	echo "-> voldown : Send serial command to down the volume"
	echo "-> init : Calls tha main init \"C\" code"
	echo "-> start : All the required steps to start the amplifier for the first time"
	echo "-> stop : all the required steps to stop the amplifier"
}

delay()
{		
	read -p "" -t 0.1
}

powerUp()
{
	sudo echo "0" > /sys/class/gpio/gpio$powerPin/value
	delay
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
	delay
	echo "Amplifier powered down"
}


muteAmp()
{
	echo "0" > /sys/class/gpio/gpio$mutePin/value
	delay
	echo "Amplifier is muted"

}

unmuteAmp()
{
	echo "1" > /sys/class/gpio/gpio$mutePin/value
	delay
	echo "Amplifier is unmuted"
}

enableAmp()
{
	echo "0" > /sys/class/gpio/gpio$enabelPin/value
	delay
	echo "Amplifier is enabeled"
}

disableAmp()
{
	sudo echo "1" > /sys/class/gpio/gpio$enabelPin/value
	delay
	echo "Amplifier is disabeled"
}


getEnable()
{
	res=$(cat /sys/class/gpio/gpio$enabelPin/value)
	if [ "$res" == "1" ]; then echo "0";
	elif [ "$res" == "0" ]; then echo "1";
	else echo "Error : unable to read pin";
	fi
	exit 1
}

getMute()
{
	res=$(cat /sys/class/gpio/gpio$mutePin/value)
	if [ "$res" == "1" ]; then echo "0";
	elif [ "$res" == "0" ]; then echo "1";
	fi
	exit 1
}

getPower()
{
	res=$(cat /sys/class/gpio/gpio$powerPin/value)
	if [ "$res" == "1" ]; then echo "0";
	elif [ "$res" == "0" ]; then echo "1";
	fi
	exit 1
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
	helpInfo
elif [ "$#" -eq 1 ]
then

	if [ "$1" == "configure" ];		then configurePins; fi
	if [ "$1" == "disconfigure" ];	then clearPins;	fi
	if [ "$1" == "power" ];			then powerUp; fi
	if [ "$1" == "shutdown" ];		then powerDown; fi
	if [ "$1" == "mute" ];			then muteAmp; fi
	if [ "$1" == "unmute" ];		then unmuteAmp; fi
	if [ "$1" == "enable" ];		then enableAmp; fi
	if [ "$1" == "disable" ];		then disableAmp; fi
	if [ "$1" == "volup" ];			then volup; fi
	if [ "$1" == "voldown" ];		then voldown; fi
	if [ "$1" == "init" ];			then initAmp; fi
	
	if [ "$1" == "start" ];
	then
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
		echo "Amplifier has stoped"
	fi
elif [ "$#" -eq 2 ]
then
	if [ "$1" == "get" ]
	then
		if [ "$2" == "mute" ]; then getMute;
		elif [ "$2" == "enable" ]; then getEnable; 
		elif [ "$2" == "power" ]; then getPower;
		fi
	fi
else 
	helpInfo
fi
