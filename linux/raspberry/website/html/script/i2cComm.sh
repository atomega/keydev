#!/bin/bash

VAR1=$1

argTab=($2 $3 $4)

regexNumber='^[0-9]{1}' #Starts and contain only one number fom 0 to 9
regexHex='^0[xX][0-9a-fA-F]{2}' #Starts with 0x or 0X followed by two hexadecimal values from 0 to F or f 

helpInfo()
{
	echo ""
	echo "Usage: ./i2cComm.sh I2CINTERFACE ADDRESS REGISTER DATA"
	echo "  - I2CINTERFACE [0-9] - I2C device interface listed on /dev/i2cXXXX"
	echo "  - ADDRESS [0x00-0xFF] - I2C devices physical address"
	echo "  - REGISTER [0x00-0xFF] - Desired register that needs to be accessed"
	echo "  - DATA [0x00-0xFF] - Desired data to be written on the selected register"
	echo "	  -> If data is given: a write oppeartion will be executed"
	echo "	     Ex: ./i2cComm.sh 1 0x20 0x40 0x37"
	echo "	  -> If data is not given: a read oppeartion will be executed"
	echo "	     Ex: ./i2cComm.sh 1 0x20 0x40"
	exit 1
}

isArg1ok()
{
	strlength=$(echo -n $VAR1 | wc -m)
	
	if [ "$strlength" -eq 1 ]
	then 
		if ! [[ $VAR1 =~ $regexNumber ]] 
		then
			echo "Error: $VAR1 is not a valid I2C bus number"
			exit 1
		fi
	else 
		echo "Error: $VAR1 is not a valid I2c bus number"
		exit 1
		fi
}

areArgOK()
{
	if ! [[ $1 =~ $regexHex ]] 
	then
		echo "Error: $1 is not a valid hexadecimal number"
		exit 1
	fi
}

if [ "$#" -eq 1 ]
then 
	if [ "$VAR1" = "help" ]
	then
		helpInfo
	else
		echo "Error: invalid argument number"
		exit 1 
	fi
elif [ "$#" -eq 3  ]
then 
	isArg1ok
	for i in ${argTab[@]}
	do
		areArgOK "$i"
	done

	i2cget -y $1 $2 $3 #Call That ca be changed

elif [ "$#" -eq 4 ]
then 
	isArg1ok
	for i in ${argTab[@]}
	do
		areArgOK "$i"
	done

	i2cset -y $1 $2 $3 $4 # Call that can be changed
	i2cReadVal=$(i2cget -y $1 $2 $3) # Call that can be Changed
	
	if [ "$4" = "$i2cReadVal" ]
	then
		echo "New value : $i2cReadVal"
	else
		echo "Error: write unsucessfull"
		exit 1 
	fi
else
	echo "Error: invalid argument number"
	exit 1 
fi

exit 1
