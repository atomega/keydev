#!/bin/bash 

wifiFile="wpa_supplicant.conf"
configFile="config.txt"

read -p "Please Select the Card to use: " -i "/dev/" -e cardName

read -p 'Do you want to burn the image (y/n): ' yesorno
if [ ¨$yesorno¨ = ¨y¨ ]; 
	then
	read -p "Please Select the Image to burn: " -i "/" -e imgToBurn
	sudo dd if=$imgToBurn of=$cardName bs=100M
fi

read -p "Please Select an mount destination: " -i "/" -e mountPath
read -p "Please Select the first partition of card: " -i "$cardName" -e partOne
read -p "Please Select the first partition of card: " -i "$cardName" -e partTwo

cd

sudo umount $mountPath
sudo mount $partOne $mountPath

cd $mountPath
sudo touch SSH 
echo "enable_uart=1" | sudo tee -a $configFile
echo
echo "LS To confirn if SSH file was created" 
ls
echo 
echo 
echo "Cat of the $configFile file to see if enable_uart=1 is included" 
echo
cat $configFile
echo
cd 
sudo umount $mountPath

sudo mount $partTwo $mountPath
cd $mountPath""boot/

sudo rm $wifiFile
sudo touch $wifiFile
echo

read -p 'Please entre SSID for wifi connection: ' ssid
read -p 'Please entre Password for wifi connection: ' psk

echo "ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev" | sudo tee -a $wifiFile
echo "update_config=1" | sudo tee -a $wifiFile
echo "country=CH" | sudo tee -a $wifiFile
echo " " | sudo tee -a $wifiFile
echo "network={" | sudo tee -a $wifiFile
echo -e "\tssid=\"$ssid\"" | sudo tee -a $wifiFile
echo -e "\tpsk=\"$psk\"" | sudo tee -a $wifiFile
echo "}" | sudo tee -a $wifiFile
echo
echo
echo "Cat of the $wifiFile to see if it's correctly configured" 
echo
cat $wifiFile
cd
sudo umount $mountPath
echo
echo "Done" 
echo
