#!/bin/bash

echo "Wellcome to Raspbian setup script"

mapfile -t MODULES </home/$USER/keydev/linux/firstsetup/sw_modules

for m in "${MODULES[@]}"
do
	echo $m
	case $m in 
		VIM)
			echo "debug" 
			/home/pi/keydev/linux/firstsetup/modules/vim/installVim.sh
			;;
		GCC)
			sudo apt-get install -y gcc
			;;
		I2C_TOOLS)
			sudo apt-get install -y i2c-tools
			sudo apt-get install -y libi2c-dev
			;;
		HTOP)
			sudo apt-get install -y htop
			;;
		MC)
			sudo apt-get install -y mc
			;;
		POSTGRES)
			sudo apt-get install -y postgresql libpq-dev postgresql-client postgresql-client-common 
			sudo apt-get install -y php5-pgsql 
			;;
		CMAKE)
			sudo apt-get install -y cmake
			sudo apt-get install -y gcc
			;;
		PIP)
			sudo apt-get install -y python3-pip
			;;
		*)
			echo "One module has not been taken care of"
			;;
	esac
done
