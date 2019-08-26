#include <netinet/in.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

#define ETH_INTERFACE "eth0"
#define WLAN_INTERFACE "wlan0"

void get_ip_eth();  
void get_ip_wlan();  
