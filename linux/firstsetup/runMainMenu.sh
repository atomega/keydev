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
W_DIFF_MS=11
W_TITLE="Initial"
W_NBR_OF_SELECTION=1
LENGHT_LIST_ITEM=1
LENGHT_PREV_LIST_ITEM=1
W_LIST_SECTION=0

mapfile -t MOD_RASPBIAN < /home/$USER/keydev/linux/firstsetup/raspbian/mods/mod_raspbian.txt
mapfile -t MOD_DEBIAN < /home/$USER/keydev/linux/firstsetup/debian/mods/mod_debian.txt

get_dimentions()
{
	W_LIST_HEIGHT=$(($W_NBR_OF_SELECTION*$W_SELECTION_HEIGHT))
	W_WINDOW_HEIGHT=$(($W_LIST_HEIGHT+$W_HEADER_HEIGHT+$W_FOOTER_HEIGHT))
	W_TITLE_LENGHT=${#W_TITLE}


	if [ $W_LIST_SECTION == "1" ]
	then
		for ((c=0; c<=$ARRAY_SIZE; c+=3))
		do  
			LENGHT_LIST_ITEM=$((${#MOD_RASPBIAN[$c]}+${#MOD_RASPBIAN[$c+1]}))

			if [ $LENGHT_PREV_LIST_ITEM -lt $LENGHT_LIST_ITEM ]
			then
				LENGHT_PREV_LIST_ITEM=$LENGHT_LIST_ITEM 
			fi
		done 
		
		LENGHT_PREV_LIST_ITEM=$(($LENGHT_PREV_LIST_ITEM+$W_DIFF_MS))
	
		if [ $LENGHT_PREV_LIST_ITEM -gt $W_TITLE_LENGHT ]
		then
			W_WINDOW_WIDTH=$(($LENGHT_PREV_LIST_ITEM+$W_MARGIN+$W_DIFF_MS))
		else
			W_WINDOW_WIDTH=$(($W_TITLE_LENGHT+$W_MARGIN))
		fi
	else 
		W_WINDOW_WIDTH=$(($W_TITLE_LENGHT+$W_MARGIN))
	fi
}



W_TITLE="Wellcome to the first setup run"
W_NBR_OF_SELECTION=1
get_dimentions
whiptail	--msgbox "$W_TITLE" $W_WINDOW_HEIGHT $W_WINDOW_WIDTH

W_TITLE="Please choose your desired distribution"
W_NBR_OF_SELECTION=2
get_dimentions
whiptail	--menu --separate-output "$W_TITLE" $W_WINDOW_HEIGHT $W_WINDOW_WIDTH $W_LIST_HEIGHT \
			DEBIAN "The venerable" \
			RASPBIAN "The little Venerable" \
			2>sw_distro

OS=$(cat sw_distro)

W_LIST_SECTION=1
case $OS in 
	DEBIAN)
		ARRAY_SIZE="${#MOD_DEBIAN[@]}"
		W_TITLE="Please select Debian modules that you wish to install"  
		W_NBR_OF_SELECTION=$(( ${#MOD_DEBIAN[@]} / 3 ))
		get_dimentions
		whiptail	--checklist --separate-output "$W_TITLE" $W_WINDOW_HEIGHT $W_WINDOW_WIDTH $W_LIST_HEIGHT "${MOD_DEBIAN[@]}" 2>sw_modules
		;;
	RASPBIAN)
		ARRAY_SIZE="${#MOD_RASPBIAN[@]}"
		W_TITLE="Please select Raspbian modules that you wish to install"  
		W_NBR_OF_SELECTION=$(( ${#MOD_RASPBIAN[@]} / 3 ))
		get_dimentions
		whiptail	--checklist --separate-output "$W_TITLE" $W_WINDOW_HEIGHT $W_WINDOW_WIDTH $W_LIST_HEIGHT "${MOD_RASPBIAN[@]}" 2>sw_modules
		/home/$USER/keydev/linux/firstsetup/raspbian/setupRaspbian.sh
		;;
	*)
		echo "You should not be here"
		exit 0 
		;;
esac
W_LIST_SECTION=0

rm sw_*

#sudo apt-get update -y
#sudo apt-get upgrade -y

exit 0
