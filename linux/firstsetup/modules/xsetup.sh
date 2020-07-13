#!/bin/bash

sudo apt-get update -y
sudo apt-get upgrade -y
sudo apt-get dist-upgrade -y
sudo apt-get clean

sudo apt-get install -y --no-install-recommends xserver-xorg
sudo apt-get install -y --no-install-recommends xinit
sudo apt-get install -y openbox lxterminal
sudo apt-get install -y lightdm
sudo apt-get install -y matchbox-keyboard
cp /etc/X11/xinit/xinitrc ~/.xinitrc
