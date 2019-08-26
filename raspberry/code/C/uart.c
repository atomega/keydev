//////////////////////////////////////////////////////////
// Created by 	: Kerem Yollu												
//	Project 		: Multiprise conectée
// Nom 			: uart.c
// Header 		: uart.h			
//_________________________Info_________________________
//
// COnfiguration de l'uart
// Les infos sur les flags /usr/include/termios.h voir : http://pubs.opengroup.org/onlinepubs/007908799/xsh/termios.h.html):
//	Bauds 	- B1200, B2400, B4800, B9600, B19200, B38400, B57600, B115200, B230400, B460800, B500000, B576000, B921600, B1000000, B1152000, B1500000, B2000000, B2500000, B3000000, B3500000, B4000000
//	CSIZE 	- CS5, CS6, CS7, CS8
//	CLOCAL 	- Ignore modem status lines
//	CREAD 	- Enable receiver
//	IGNPAR 	- Ignore characters with parity errors
//	ICRNL 	- Map CR to NL on input (Use for ASCII comms where you want to auto correct end of line characters - don't use for bianry comms!)
//	PARENB 	- Parity enable
//	PARODD 	- Odd parity (else even)
//
// Les flags (fcntl.h):
//	Access modes (use 1 of these):
//		O_RDONLY - Open for reading only.
//		O_RDWR - Open for reading and writing.
//		O_WRONLY - Open for writing only.
//
//	O_NDELAY / O_NONBLOCK (same function) - Enables nonblocking mode. When set read requests on the file can return immediately with a failure status
//											if there is no input immediately available (instead of blocking). Likewise, write requests can also return
//											immediately with a failure status if the output can't be written immediately.
//
//	O_NOCTTY - When set and path identifies a terminal device, open() shall not cause the terminal device to become the controlling terminal for the process.
//////////////////////////////////////////////////////////
#include <stdio.h>
#include <unistd.h>			//Used for UART
#include <fcntl.h>			//Used for UART
#include <termios.h>			//Used for UART
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define TX_BUFF_LENGHT 10 
#define RX_BUFF_LENGHT 512 
#define UART_INTEFACE "/dev/ttyS0"


int uart0_filestream = -1;

void initUART() 
{
	struct termios options;
	
	uart0_filestream = open(UART_INTEFACE,  O_RDWR | O_NOCTTY | O_NDELAY);		//non blocking read/write 

	if (uart0_filestream == -1)
	{
		printf(" UART.C :\tErreur impossible d'ouviri le port UART\n");
	}

	tcgetattr(uart0_filestream, &options);
	options.c_cflag = B9600 | CS8 | CLOCAL | CREAD; //<Set baud rate
	options.c_iflag = IGNPAR;
	options.c_oflag = 0;
	options.c_lflag = 0;
	tcflush(uart0_filestream, TCIFLUSH);
	tcsetattr(uart0_filestream, TCSANOW, &options);

	printf("UART.C :\tUART à été initializé avec success\n"); 
	
}

void uartSendData( const char *tx_data)
{
	char tx_buffer[TX_BUFF_LENGHT];
	int data_lenght = 0; 

	data_lenght= strlen(tx_data); 
	
	if(data_lenght	> TX_BUFF_LENGHT)
	{
		printf("UART.C :\ttx data est trop long : %d \n", data_lenght); 
	}
	else 
	{
		printf("UART.C :\t%d byte ont été mise dans tx_buffer \n", data_lenght); 
		strcpy(tx_buffer, tx_data); 

		if (uart0_filestream != -1)
		{
			int count = write(uart0_filestream, &tx_buffer[0], data_lenght);		//Filestream, bytes a ecrire, nombres de bytes à ecrire
			if (count < 0)
			{
				printf("UART.C :\tErreur TX\n");
			}
		}
	}
}


void uartSendEnter()
{
	char tx_buffer[1];
	tx_buffer[0] =13; 
	
	if (uart0_filestream != -1)
	{
		int count = write(uart0_filestream, &tx_buffer[0], 1);		//Filestream, bytes a ecrire, nombres de bytes à ecrire
		printf("UART.C :\t Commande \"Enter\" a ete envoyee\n"); 
		if (count < 0)
		{
			printf("UART.C :\tErreur TX\n");
		}
	}
}
char* uartRecieveData()
{
 	static char rx_buffer[RX_BUFF_LENGHT];
	int rx_length = 0;  

	if (uart0_filestream != -1)
	{
		rx_length = read(uart0_filestream, (void*)rx_buffer, RX_BUFF_LENGHT - 1);		
		
		if (rx_length < 0)
		{	
			printf("UART.C :\tErreur lors de la récéption \"rxbuff < 0\" \n"); 
		}
		else if (rx_length == 0)
		{
			printf("UART.C :\tPas de donées en attente de lecture \n"); 	
		}
		else
		{
			printf("UART.C :\t%d Bytes ont été lus => %s\n", rx_length, rx_buffer);
			return rx_buffer; 
		}
	}
	else 
	{
		return "error"; 
	}
	
	return "error"; 
}



int main()
{
	char* data; 	
	initUART(); 
	uartSendData("+++");  
	getchar(); 
	data = uartRecieveData(); 	
	getchar(); 
	uartSendData("ATID");  
   uartSendEnter();   
	getchar(); 
	data = uartRecieveData(); 	

	printf(" UART.C :\t message recut => %s \n", data);
	
	return 1; 
}


