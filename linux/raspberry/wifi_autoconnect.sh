#!/bin/bash

# L'adresse IP du serveur que vous voulez pinger (8.8.8.8 est un serveur DNS public de Google)
SERVER=8.8.8.8

# Envoyer seulement 2 pings, et envoyer la sortie vers /dev/null
ping -c2 ${SERVER} > /dev/null
printf "Ping test to see if there is a connection \n"

# Si le code retour du ping ($?) est différent de 0 (qui correspond à une erreur)
if [ $? != 0 ]
then
printf "Wifi ping test has failed reconfiguring Wlan0 \n"
    # Restart the wireless interface
    # Relancer l'interface wifi
	sudo ifconfig wlan0 down 
	sudo ifconfig wlan0 up
fi
