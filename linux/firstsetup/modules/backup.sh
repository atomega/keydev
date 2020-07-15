#!/bin/bash

#sudo apt-get install -y rsync
OK=0
response="na"

echo "#######################################"
echo "What kinf of backup do you want to do:" 
echo "Create new from ssh		-> ns "
echo "Create new from local		-> nl "
echo "Create itteration from ssh	-> is" 
echo "Create itteration from local	-> il" 
echo "Restore backup to local		-> rl" 
echo "#######################################"
   
   # loop until we get a good answer and break out
   while [ "$OK" = 0 ]
   do
	read -p "Please choose : ns OR nl OR is OR il OR rl OR quit: " input
      # Test the input
      if [ "$input" = "ns" ] || [ "$input" = "nS" ] || [ "$input" = "Ns" ] || [ "$input" = "NS" ]
         then
         response="ns"
         OK=1
      elif [ "$input" = "nl" ] || [ "$input" = "nL" ] || [ "$input" = "Nl" ] || [ "$input" = "NL" ]
         then
         response="nl"
         OK=1
      elif [ "$input" = "is" ] || [ "$input" = "iS" ] || [ "$input" = "iS" ] || [ "$input" = "IS" ]
         then
         response="is"
         OK=1
      elif [ "$input" = "il" ] || [ "$input" = "iL" ] || [ "$input" = "Il" ] || [ "$input" = "IL" ]
         then
         response="il"
         OK=1
      elif [ "$input" = "rl" ] || [ "$input" = "rL" ] || [ "$input" = "Rl" ] || [ "$input" = "RL" ]
         then
         response="rl"
         OK=1
      elif [ "$input" = "help" ] || [ "$input" = "h" ]
		then 
		echo "What kinf of backup do you want to do:" 
		echo "Create new from ssh -> ns "
		echo "Create new from local -> nl "
		echo "Create itteration from ssh -> is" 
		echo "Create itteration from local -> il" 
		echo "Restore on local -> rl" 
      elif [ "$input" = "q" ] || [ "$input" = "quit" ]
		then
		exit
      else
         # Invalid input
         echo "INPUT ERROR: Must be ns OR nl OR is OR il OR rl OR quit: Please try again."
      fi
   done


if [ "$response" = "ns" ]; 
then
	read -p "Source ip address: " -i -e sourceIp 
	read -p "Source user name: " -i -e sourceUser 
	read -p "Source directory: " -i "/" -e sourceDir
	sudo rsync -aAXP -e ssh --delete --exclude={"/dev/*","/proc/*","/sys/*","/tmp/*","/run/*","/mnt/*","/media/*","swapfile","lost+found",".cache","Downloads",".ecryptfs"} $sourceUser@$sourceIp:$sourceDir $targetDir

elif [ "$response" = "nl" ]; 
then
	read -p "Source directory: " -i "/" -e sourceDir
	read -p "Target directory: " -i "/" -e targetDir
	sudo rsync -aAXP --delete --exclude={"/dev/*","/proc/*","/sys/*","/tmp/*","/run/*","/mnt/*","/media/*","swapfile","lost+found",".cache","Downloads",".ecryptfs"} $sourceDir $targetDir 

elif [ "$response" = "is" ]; 
then
	read -p "Source ip address: " -i -e sourceIp 	
	read -p "Source user name: " -i -e sourceUser 
	read -p "Source directory: " -i "/" -e sourceDir
	read -p "Target current directory: " -i "/" -e linkDir
	read -p "Target itteration directory: " -i "/" -e targetDir
	sudo rsync -aAXPH -e ssh --delete --exclude={"/dev/*","/proc/*","/sys/*","/tmp/*","/run/*","/mnt/*","/media/*","swapfile","lost+found",".cache","Downloads",".ecryptfs"} --link-dest=$linkDir $sourceUser@$sourceIp:$sourceDir $targetDir

elif [ "$response" = "il" ]; 
then
	read -p "Source directory: " -i "/" -e sourceDir
	read -p "Target current directory: " -i "/" -e linkDir
	read -p "Target itteration directory: " -i "/" -e targetDir
	sudo rsync -aAXPH --delete --exclude={"/dev/*","/proc/*","/sys/*","/tmp/*","/run/*","/mnt/*","/media/*","swapfile","lost+found",".cache","Downloads",".ecryptfs"} --link-dest=$linkDir $sourceDir $targetDir
	
elif [ "$response" = "rl" ]; 
then	
	lsblk
	read -p "Target Device to be mounted: " -i "/dev/" -e deviceName
	read -p "Target device mount direcotry: " -i "/mnt/" -e targetDir
	read -p "Backup directory: " -i "/" -e sourceDir
	sudo mount $deviceName $targetDir
	ls $targetDir
	sudo rsync -aAXP --delete --exclude="lost+found" $sourceDir $targetDir 
fi
exit
