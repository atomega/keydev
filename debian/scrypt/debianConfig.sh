#!/bin/bash

########################################### INFO ###############################################
# Last Update 03.12.2017
#
# VIM :	There is an installation with wim and NerdTree That makes you able to navigate folder without quitting vim  
#			If you allready have a .vimrc configration file it will backed-up ONLY ONE BACUP WILL BE MADE so be carefull 
#			There is NO .vimrc Configuration file for SUDOERS 
#
# C : 	All the C relatives will be installed for compiling C codes and Debugging
#
# WiringPi : Wirign pi is a C based software for controlling the Raspberry Pi's GPIO pins in C 
#			But Also have inlime terminal command compiled for ease of use plese refer to http://wiringpi.com/ for more information 
#
# HTOP : HTOP is a fully made task manager with comprehemsible interface 
#
# MidnightCommander : Is a file browser with two windows and helps a lot in mamaging file copiying etc... 
#
#
################################################################################################

cat <<"EOF"

                .88888888:.
                88888888.88888.
              .8888888888888888.
              888888888888888888
              88' _`88'_  `88888
              88 88 88 88  88888
              88_88_::_88_:88888
              88:::,::,:::::8888
              88`:::::::::'`8888
             .88  `::::'    8:88.
            8888            `8:888.
          .8888'             `888888.
         .8888:..  .::.  ...:'8888888:.
        .8888.'     :'     `'::`88:88888
       .8888        '         `.888:8888.
      888:8         .           888:88888
    .888:88        .:           888:88888:
    8888888.       ::           88:888888
    `.::.888.      ::          .88888888
   .::::::.888.    ::         :::`8888'.:.
  ::::::::::.888   '         .::::::::::::
  ::::::::::::.8    '      .:8::::::::::::.
 .::::::::::::::.        .:888:::::::::::::
 :::::::::::::::88:.__..:88888:::::::::::'
  `'.:::::::::::88888888888.88:::::::::'
        `':::_:' -- '' -'-' `':_::::'`
EOF



#VARIABLES 

VIMRC".vimrc"
VIMDIR".vim"


printf "\e[93m GOING HOME \e[32m\n\n"
cd ~




printf "\e[36m##################INSTALLING THINGS FOR DEBIAN#################\e[32m\n"
printf "\e[36m INSTALLING PYTHON \e[32m\n"
sudo apt-get install -y python
printf "\e[36m INSTALLING XTERM \e[32m\n\n"
sudo apt-get install -y xterm
printf "\e[36m INSTALLING OKULAR \e[32m\n\n"
sudo apt-get install -y okular 
printf "\e[36m INSTALLING LIBREOFFICE \e[32m\n\n"
sudo apt-get install -y libreoffice 
printf "\e[36m INSTALLING SLIM \e[32m\n\n"
sudo apt-get install -y slim
printf "\e[31m INSTALLING OPENBOX \e[32m\n"
sudo apt-get install -y openbox obconf
printf "\e[31m INSTALLING FEH \e[32m\n"
sudo apt-get install -y feh
printf "\e[31m INSTALLING MENU \e[32m\n"
sudo apt-get install -y menu
printf "\e[31m INSTALLING HTOP \e[32m\n"
sudo apt-get install -y htop 
printf "\e[31m INSTALLING MIDNIGHT COMMANDER \e[32m\n"
sudo apt-get install -y mc
printf "\e[31m CONFIGURING THE MENU \e[32m\n"
sudo cp /var/lib/openbox/debian-menu.xml ~/.config/openbox/debian-menu.xml
sudo cp /etc/xdg/openbox/menu.xml ~/.config/openbox/menu.xml
sudo cp /etc/xdg/openbox/rc.xml ~/.config/openbox/rc.xml
sudo apt-get install -y obmenu
sudo openbox --reconfigure
printf "\e[31m INSTALLING BLUEMAN\e[32m\n"
sudo apt-get install -y blueman
printf "\e[31m INSTALLING GIMP\e[32m\n"
sudo apt-get install -y gimp
printf "\e[31m INSTALLING NCURSES \e[32m\n"
sudo apt-get install -y ncurse-*
printf "\e[31m INSTALLING CMAKE \e[32m\n"
sudo apt-get install cmake 
printf "\e[31m INSTALLING VIM \e[32m\n"
sudo apt-get install -y vim

printf "\e[31m ADDING NERDTREE TO VIM \e[32m\n"
git clone https://github.com/scrooloose/nerdtree.git

if [ -f $VIMRC ];
then
   printf "\e[95mFile : $VIMRC exists Making a Backup\e[32m\n"
     mv $VIMRC  "$VIMRC".bak
     touch vimconfig.txt
else
   printf "\e[95mCreatting file : $VIMRC\n"
   touch vimconfig.txt
fi

if [ -d "$VIMDIR" ]; 
then 
	printf "\e[95mDirectory : $VIMDIR exists Making a Backup\e[32m\n"
	sleep 1 

	if [ -d "$VIMDIR""_bak" ];
	then
		printf "\e[95mBackup Directory Allredy Exists : Replacing\e[32m\n"
		sudo rm -r $VIMDIR"_bak"
	fi
	
	mv $VIMDIR $VIMDIR"_bak"
	sudo mkdir $VIMDIR
else 
	printf "\e[95mCreating directory : $VIMDIR \e[32m\n"
	sudo mkdir $VIMDIR
fi

printf "\e[31m CONFIGURING VIM \e[32m\n"
#This is the configuration to be writtten inside .vimrc that works great but has no configuration for sudoers
cat <<EOT >> vimconfig.txt
""VIM_CONFIG_START

"Basic syntax ----------------------------------------------------------------------

syntax on
set number 
set tabstop3		""TabSize of 3  
set shiftwidth3 	""Indentation fo 3  
set softtabstop0 ""Enabeling it will remplace tabs by spaces in insert mode not cool
set noexpandtab 	""Enabeling it will remplace tabs by spaces not cool 

"-----------------------------------------------------------------------------------



"NerdTree --------------------------------------------------------------------------

"autocmd vimenter * NERDTree "For auto activating nerd tree when vim opens 
map <C-n> :NERDTreeToggle<CR>  
autocmd bufenter * if (winnr("$")  1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif ""autoClose wim when only the NerdTree Window IS open 

"------------------------------------------------------------------------------------

""VIM_CONFIG_END
EOT
mv vimconfig.txt $VIMRC
sudo cp -a nerdtree/. $VIMDIR
sudo rm -r nerdtree/



printf "\e[36m INSTALLING LIVE-BUILD TOOL \e[32m\n"
sudo apt-get install -y live-build

printf "\e[36m##################INSTALLING THINGS FOR DEBIAN DONE ###################\e[32m\n"





printf "\e[36m##################INSTALLING THINGS FOR YOCTO PROJECT#################\e[32m\n"
printf "\e[36m INSTALLING YOCTO PROJECT & PREREQUIES \e[32m\n\n"
printf "\e[36m ADDIN PACKAGES FOR  YOCTO \e[32m\n"
sudo apt-get install -y gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat libsdl1.2-dev xterm
printf "\e[36m INSTALLING PYTHON FOR YOCTO \e[32m\n"
sudo apt-get install -y python
printf "\e[36m INSTALLING QEMU FOR YOCTO \e[32m\n"
sudo apt-get build-dep qemu
printf "\e[36m removing oss4 cause qemu compilation isues\e[32m\n\n"
sudo apt-get remove oss4-dev
cd ~
mkdir Yokto
cd Yokto 
git clone git://git.yoctoproject.org/poky
cd poky
git checkout -b fido origin/fido
source oe-init-build-env
cd ~
cd Yokto
printf "\e[31m INSTALLING BITBAKE \e[32m\n"
git clone git://git.openembedded.org/bitbake
printf "\e[31m INSTALLING C RELATIES \e[32m\n"
sudo apt-get install -y gcc
printf "\e[36m##################INSTALLING THINGS FINISHED#################\e[32m\n"
