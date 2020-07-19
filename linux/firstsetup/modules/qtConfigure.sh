#!/bin/bash

sysrootLinker="sysroot-relativelinks.py"

quitting()  
{
	read -p 'Do you want to Make Clean before quitting ? (y/n): ' yesorno
	if [ ¨$yesorno¨ = ¨y¨ ]; 
	then
		sudo make confclean -j$coreCount
		sudo make clean -j$coreCount
	fi
	
	read -p 'Do you want to remove created files before quitting ? (y/n): ' yesorno
	if [ ¨$yesorno¨ = ¨y¨ ]; 
	then
		sudo rm -r $sysrootDir
		sudo rm -r $qtExtPrefix
		sudo rm -r $qtHostPrefix
		sudo rm -r $qtPrefix
	fi
	
	read -p 'Do you want to remove Installation files before quitting ? (y/n): ' yesorno
	if [ ¨$yesorno¨ = ¨y¨ ]; 
	then
		sudo rm -r $installDir
	fi
		echo -e "\e[34m Terminating process \e[0m"
	exit
}  

installDir="/home/$USER/xCompiler"
sysrootDir="$installDir/sysroot"
qtExtPrefix="$installDir/qt5pi"
qtHostPrefix="$installDir/qt5"
toolchainUsed="$installDir/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin/arm-linux-gnueabihf-"

qtDriectory="/home/key/crosscompile-tools/qt-everywhere-src-5.12.5/"
qtPrefix="/usr/local/qt5pi"
qtDevice="linux-rasp-pi3-g++"
coreCount=4

echo "#############################################################################################"
echo -e "\e[34m Wellcome to the Qt crosscompiler setup script \e[0m"
echo -e "\e[34m the compilation may take a long time (Few Hours) depending on your system \e[0m"
echo -e "\e[34m so please take a coffee and enjoy the ride \e[0m"
echo "#############################################################################################"


sudo mkdir $qtPrefix
mkdir $qtExtPrefix
mkdir $qtHostPrefix

read -p 'Do you want to install Raspberry Pi Tools (y/n) ?: ' yesorno
if [ ¨$yesorno¨ = ¨y¨ ]; 
then
	sudo apt-get install -y git
	sudo apt-get install -y rsync
	mkdir $installDir
	cd $installDir
	git clone https://github.com/raspberrypi/tools
fi


read -p 'Do you want to link sysroot and Rsync (y/n) ?: ' yesorno
if [ ¨$yesorno¨ = ¨y¨ ]; 
then
	cd $installDir
	read -p "Directory of the current system: " -i "/home/" -e sysrootDir
	echo -e "\e[31m Creating Sysroot \e[0m"
	wget https://raw.githubusercontent.com/riscv/riscv-poky/master/scripts/sysroot-relativelinks.py
	sudo chmod +x ./sysroot-relativelinks.py
	sudo ./sysroot-relativelinks.py $sysrootDir
fi
 
cd $qtDriectory

read -p 'Do you want to compile (y/n) ?: ' yesorno
if [ ¨$yesorno¨ = ¨y¨ ]; 
then
	sudo ./configure -v -release -opengl es2 -eglfs -device $qtDevice -device-option CROSS_COMPILE=$toolchainUsed -sysroot $sysrootDir -opensource -confirm-license -skip qtwayland -skip qtlocation -skip qtscript -make libs -prefix $qtPrefix -extprefix $qtExtPrefix -hostprefix $qtHostPrefix -no-use-gold-linker -v -no-gbm
fi

read -p 'Was the configuration Sucsessfull (y/n) ?: ' yesorno
if [ ¨$yesorno¨ = ¨y¨ ]; 
then
	echo -e "\e[31m Continuing with Make \e[0m"
	sudo make -j$coreCount
else 
	quitting
fi

read -p 'Was Make Sucsessfull (y/n) ?: ' yesorno
if [ ¨$yesorno¨ = ¨y¨ ]; 
then
	echo -e "\e[31m Continuing with Make Install \e[0m"
	sudo make install -j$coreCount
else 
	quitting
fi

read -p 'Was Make Install Sucsessfull (y/n) ?: ' yesorno
if [ ¨$yesorno¨ = ¨y¨ ]; 
then
	echo -e "\e[31m All is done correctly \e[0m"
else 
	quitting
fi
