#!/bin/bash

VIMRC="/home/$USER/.vimrc"
VIMDIR="/home/$USER/.vim"

echo "Wellcome to the VIM installation script"

sudo apt-get install exuberant-ctags
sudo apt-get install -y vim 

if [ -f $VIMRC ];
then
	printf "\e[95mFile : $VIMRC exists Making a Backup\e[32m\n"
	mv $VIMRC  "$VIMRC".bak
else
	printf "\e[95mCreatting file : $VIMRC\n"
fi

cp vimrc $VIMRC

if [ -d "$VIMDIR" ]; 
then 
	printf "\e[95mDirectory : $VIMDIR exists Making a Backup\e[32m\n"
	mv $VIMDIR $VIMDIR"_bak"
	mkdir $VIMDIR
else 
	printf "\e[95mCreating directory : $VIMDIR \e[32m\n"
	mkdir $VIMDIR
fi
