//////////////////////////////////////////////////////////
// Created by 	: Kerem Yollu												
//	Project 		: Multiprise conectée
// Nom			: getip.c
// Header 		: getip.h			
//_________________________Info_________________________
//
// Librairie capable d'aller récuperer les adresses ip  
// ethernet et wifi de la raspberry garce au socets et 
// appelles systèmes dediée à la gestion des ip "getifaddrs();" 
// Cette fonction fait apelle à la libarire lcd.c due à la 
// compléxité de la mise en forme des adresse ip afin de 
// faciliter l'affichage. 
//////////////////////////////////////////////////////////

#include "main.h"
#include "getip.h"
#include "lcd.h"


// Récuperation de l'adresse ip eth0 
void get_ip_eth() 
{
    struct ifaddrs *ifaddr, *ifa;
    int s;
    char host[NI_MAXHOST];
	
	// Optention de l'adresse ip 	  
    if (getifaddrs(&ifaddr) == -1) 
    {
        printf("GETIP.C :\t Erreur de l'appelle => getifaddrs \n");
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) 
    {
        if (ifa->ifa_addr == NULL)
            continue;  

		// LEcture et mise en forme de l'adresse ip
        s=getnameinfo(ifa->ifa_addr,sizeof(struct sockaddr_in),host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);

        if((strcmp(ifa->ifa_name,"eth0")==0)&&(ifa->ifa_addr->sa_family==AF_INET))
        {
            if (s != 0)
            {
                printf("GETIP.C :\t Erreur de l'appelle => etnameinfo() %s\n", gai_strerror(s));
            }
				//Affichage sur écran lcd 		 
				lcd_display_string(2, 0, "IPE:"); 
				lcd_display_string(2, 5, host); 
            #ifdef GETIP_DEBUG
				printf("GETIP.C :\t Interface => <%s>\n",ifa->ifa_name );
            printf("GETIP.C :\t  Address => <%s>\n", host); 
				#endif
        }
    }
}


// Récuperation de l'adresse ip wlan0 
void get_ip_wlan() 
{
    struct ifaddrs *ifaddr, *ifa;
    int s;
    char host[NI_MAXHOST];

	// Optention de l'adresse ip 	  
	 if (getifaddrs(&ifaddr) == -1) 
    {
        printf("GETIP.C :\t Erreur de l'appelle => getifaddrs \n");
    }


    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) 
    {
        if (ifa->ifa_addr == NULL)
            continue;  
		// LEcture et mise en forme de l'adresse ip
        s=getnameinfo(ifa->ifa_addr,sizeof(struct sockaddr_in),host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);

        if((strcmp(ifa->ifa_name,"wlan0")==0)&&(ifa->ifa_addr->sa_family==AF_INET))
        {
            if (s != 0)
            {
                printf("GETIP.C :\t Erreur de l'appelle => etnameinfo() %s\n", gai_strerror(s));
            }
				//Affichage sur écran lcd 		 
				lcd_display_string(3, 0, "IPW:"); 
				lcd_display_string(3, 5, host); 
            #ifdef GETIP_DEBUG
				printf("GETIP.C :\t Interface => <%s>\n",ifa->ifa_name );
            printf("GETIP.C :\t  Address => <%s>\n", host); 
				#endif
        }
    }

}
