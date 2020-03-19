#!/bin/bash
#####################################################
#Author : Kerem
#
#
#Description : Tentative of a linux first setup with whiptail 
#
W_MARGIN=4
W_HEADER_HEIGHT=3
W_FOOTER_HEIGHT=5
W_SELECTION_HEIGHT=2

W_TITLE="Initial"
W_NBR_OF_SELECTION=1

get_dimentions()
{
	W_LIST_HEIGHT=$(($W_NBR_OF_SELECTION*$W_SELECTION_HEIGHT))
	W_WINDOW_HEIGHT=$(($W_LIST_HEIGHT+$W_HEADER_HEIGHT+$W_FOOTER_HEIGHT))
	W_TITLE_LENGHT=${#W_TITLE}
	W_WINDOW_WIDTH=$(($W_TITLE_LENGHT+$W_MARGIN))
}


mapfile -t MOD_RASPBIAN < raspbian/mods/mod_raspbian.txt
mapfile -t MOD_DEBIAN < debian/mods/mod_debian.txt

W_TITLE="Do you wish a fresh install or install just a module"
W_NBR_OF_SELECTION=1
get_dimentions
whiptail	--yesno "$W_TITLE" \
			--yes-button "Fresh install" \
			--no-button "Just a Module" \
			$W_WINDOW_HEIGHT $W_WINDOW_WIDTH
			CHOICE=$?


W_TITLE="Please choose your desired distribution"
W_NBR_OF_SELECTION=2
get_dimentions
whiptail	--menu --separate-output "$W_TITLE" $W_WINDOW_HEIGHT $W_WINDOW_WIDTH $W_LIST_HEIGHT \
			DEBIAN "The venerable" \
			RASPBIAN "The little Venerable" \
			2>sw_distro

OS=$(cat sw_distro)

case $OS in 
	DEBIAN)
		if [ $CHOICE == "1" ]; then 
			
			W_TITLE="Please select Debian modules that you wish to install no additional feature will be installed"  
		else 

			W_TITLE="Please select Debian modules that you wish to include to your fresh install"  
		fi

		W_NBR_OF_SELECTION=$(( ${#MOD_DEBIAN[@]} / 3 ))
		get_dimentions
		whiptail	--checklist --separate-output "$W_TITLE" $W_WINDOW_HEIGHT $W_WINDOW_WIDTH $W_LIST_HEIGHT "${MOD_DEBIAN[@]}" 2>sw_modules
		;;
	RASPBIAN)
		if [ $CHOICE == "1" ]; then 
			W_TITLE="Please select Raspbian modules that you wish to install no additional feature will be installed"  
		else 
			W_TITLE="Please select Raspian modules that you wish to include to your fresh install"  
		fi
	
		W_NBR_OF_SELECTION=$(( ${#MOD_RASPBIAN[@]} / 3 ))
		get_dimentions
		whiptail	--checklist --separate-output "$W_TITLE" $W_WINDOW_HEIGHT $W_WINDOW_WIDTH $W_LIST_HEIGHT "${MOD_RASPBIAN[@]}" 2>sw_modules
		;;
	*)
		echo "You should not be here"
		exit 0 
		;;
esac

MODULE=$(grep GCC sw_modules)
MODULE=$(grep VIM sw_modules)
MODULE=$(grep POSTGRES sw_modules)
exit 0
# rm sw_*
