#!/bin/bash
#####################################################
#Author : Kerem
#
#
#Description : Tentative of a linux first setup with whiptail 
#

VIMRC="/home/$USER/.keremrc"
VIMDIR="/home/$USER/.keremdir"

if [ -f $VIMRC ];
then
	printf "\e[95mFile : $VIMRC exists Making a Backup\e[32m\n"
	mv $VIMRC  "$VIMRC".bak
else
	printf "\e[95mCreatting file : $VIMRC\n"
fi

cp keremrc $VIMRC

if [ -d "$VIMDIR" ]; 
then 
	printf "\e[95mDirectory : $VIMDIR exists Making a Backup\e[32m\n"
	mv $VIMDIR $VIMDIR"_bak"
	mkdir $VIMDIR
else 
	printf "\e[95mCreating directory : $VIMDIR \e[32m\n"
	mkdir $VIMDIR
fi
