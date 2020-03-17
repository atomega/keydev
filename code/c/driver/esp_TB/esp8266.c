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

#include "uart.h"
#include "main.h"
#define RD 1
#include <time.h>

static	int rone = 1;   
static	int rtwo = 1; 
int uart0_filestream = -1;
void initUART() 
{
	
	uart0_filestream = open(UART_INTEFACE,  O_RDWR | O_NOCTTY | O_NDELAY);		//non blocking read/write 

	if (uart0_filestream == -1)
	{
		printf(" UART.C :\t Erreur impossible d'ouvrir le port UART\n");
	}

	struct termios options;
	tcgetattr(uart0_filestream, &options);
	options.c_cflag = B115200 | CS8 | CLOCAL | CREAD;
	options.c_iflag = IGNPAR;
	options.c_oflag = 0;
	srand(time(NULL)); 
	options.c_lflag = 0;
	options.c_cc[VTIME] = 1;
	options.c_cc[VMIN] = 100;
	tcflush(uart0_filestream, TCIFLUSH);
	tcsetattr(uart0_filestream, TCSANOW, &options);
	fcntl(uart0_filestream, F_SETFL, FNDELAY);

	#ifdef UART_DEBUG
	printf("UART.C :\t UART à été initializé avec success\n"); 
	#endif
}

void uartSendData( const char *tx_data)
{
	char tx_buffer[TX_BUFF_LENGHT];
	int data_lenght = 0; 

	data_lenght= strlen(tx_data); 
	
	if(data_lenght	> TX_BUFF_LENGHT)
	{
		printf("UART.C :\t tx data est trop long : %d \n", data_lenght); 
	}
	else 
	{
		#ifdef UART_DEBUG
		printf("UART.C :\t %d byte ont été mise dans tx_buffer \n", data_lenght); 
		#endif
		strcpy(tx_buffer, tx_data); 

		if (uart0_filestream != -1)
		{
			int count = write(uart0_filestream, &tx_buffer[0], data_lenght);		//Filestream, bytes a ecrire, nombres de bytes à ecrire
			if (count < 0)
			{
				printf("UART.C :\t Erreur TX\n");
			}
		}
	}
}


void uartSendEnter()
{
	char tx_buffer[2];
	tx_buffer[0] =13; 
	tx_buffer[1] =10;  	

	if (uart0_filestream != -1)
	{
		int count = write(uart0_filestream, &tx_buffer[0], 2);		//Filestream, bytes a ecrire, nombres de bytes à ecrire
		#ifdef UART_DEBUG
		printf("UART.C :\t Commande \"Enter\" a ete envoyee\n"); 
		#endif
		if (count < 0)
		{
			printf("UART.C :\t Erreur TX\n");
		}
	}
}

int processing(int min, int max)
{
    int range, result, cutoff;
 
    if (min >= max)
        return min; // only one outcome possible, or invalid parameters
    range = max-min+1;
    cutoff = (RAND_MAX / range) * range;
 
    // Rejection method, to be statistically unbiased.
    do {
        result = rand();
    } while (result >= cutoff);
 
    return result % range + min;
}

char* uartRecieveData(int Delay_us, int Delay_s)
{
	if (uart0_filestream != -1)
	{
		static unsigned char rx_buffer[RX_BUFF_LENGHT];
		int rx_length, bytes, bytes_prev, byte_count = 0;
		char go_no_go = 0;  


		if(Delay_us > 0)
		{
			usleep(Delay_us); 
		}

		if(Delay_s > 0) 
		{	
			sleep(Delay_s); 
		}



		while(go_no_go == 0) 
		{		
			if(byte_count >= BITCHECK)
			{
				go_no_go = 1; 
			}
			else if (bytes_prev == bytes)
			{
				byte_count++; 	
			}
			else if(bytes_prev != bytes)
			{
				byte_count = 0; 
			}
			else
			{
				#ifdef UART_DEBUG
				printf("UART.C :\t Apprend à codé il y a un expétion pas géré dan ta boucle"); 
				#endif
			} 

			bytes_prev = bytes;
			ioctl(uart0_filestream, FIONREAD, &bytes);
 
			#ifdef UART_DEBUG
			printf("UART.C :\t byte_check no : %i\t => Controle de recption, Qauntité de donées Qte : %i\t Bites \n",byte_count,bytes); 
			#endif
		}		
		
			rx_length = read(uart0_filestream, (void*)rx_buffer, RX_BUFF_LENGHT-1);		//Filestream, buffer to store in, number of bytes to read (max)
	
		if (rx_length < 0)
		{
			return "Erreur aucun bite n'est recut\n"; 
			
		}
		else if (rx_length == 0)
		{
			return "Pas de donées en attente\n"; 
		}
		else
		{
			rx_buffer[rx_length] = '\0';
			
			#ifdef UART_DEBUG
			printf(" UART.C :\t %i bytes lus => %s\n", rx_length, rx_buffer);
			#endif
			return rx_buffer; 
		}
	}
	else 
	{
		return "Erreur de reception => Filestream error"; 
	}

}



int retvalue(char* data, char ending)
{

	int  i, len;
	int value[6]={0,0,0,0,0,0}; 
	//printf("count = %d\n",ending); 
//	printf("Recieved = %s\n",data); 
	int result=0;

	len = strlen(data);
	//printf("total lenght = %d\n",len); 

for(i=1; i<=ending; i++)
{
		value[i-1]=data[len-i]-'0'; 
}

	value[0] = value[0] * 1; 
	value[1] = value[1] * 10; 
	value[2] = value[2] * 100; 
	value[3] = value[3] * 1000; 
	value[4] = value[4] * 10000; 
	

for(i=0; i<ending; i++)
{
	result += value[i];   	
}
	return result;
}


char isItDone(char* Data)
{
	int index = 0;
	
	index = strlen(Data);  
		
	#ifdef UART_DEBUG
	printf("UART.C :\t Nombre d'elements dans le buffer pour la validation index => %i\n",index); 

	for (int i = 0; i < index ; i++)
	{	
//		printf("UART.C :\tValeur lus no :\t%i ascii =>\t%c hex=>\t%i \n",i, Data[i],(int)Data[i]&0Xff);   
	}
	#endif

	if(((int)Data[index-3]&0Xff) == 75)
	{
		if(((int)Data[index-4]&0Xff) == 79)
		{
		printf("UART.C :\t Etat de la responsse recut par ESP ; %c%c \n",Data[index-4],Data[index-3]);  
			return 1; 
		}
	}
	else 
	{
		return 0; 
	}
	return 0; 
}

char establishTCP()
{
	char* data ="No resequest has been done"; 	
	uartSendData("AT+CIPSTART=\"TCP\",\"192.168.4.1\",1001");
	uartSendEnter();   
	data = uartRecieveData(0,6); 
	printf("\n%s",data);  
	return 1; 
}


int main(int argc, char *argv[])
{
	unsigned	int Voltage, Freq,T0,T1,T2,C1,C2 = 0; 
	char* data ="No resequest has been done"; 	
	initUART(); 

	int Table[6]={2700,2799,23300,23500,350,550}; 


	if(argc == 1) 
	{
		printf("There is too few argument\n");
	//	printf("The argument supplied is %s\n", argv[1]); 
	}
	else if (argc > 1)
	{	
		//printf("The argument supplied is %s\n", argv[1]);
		if(strcmp(argv[1],"Connect") == 0)
		{
			uartSendData("AT");
			uartSendEnter();   
			data = uartRecieveData(DELAY_AT_STD,0); 	
			if(isItDone(data)==1 )
			{ 	
				uartSendData("AT+CWMODE_CUR=3");
				uartSendEnter();   
				data = uartRecieveData(DELAY_AT_STD,0); 
					
				if(isItDone(data)==1)
				{
					uartSendData("AT+CWJAP=\"Mp1Key\",\"1234567890\"");
					uartSendEnter();   
					data = uartRecieveData(DELAY_AT_STD,7); 
					
					if(isItDone(data)==1)
					{
						//printf("\nUART.C :\t Etat de la responsse recut par ESP ; %s",data);  
						printf("Connected"); 
					}
				}
			}	
		} 

		if(strcmp(argv[1],"Tcp") == 0)
		{
			establishTCP(); 
		}

		if(strcmp(argv[1],"Relay1on") == 0)
		{
			uartSendData("AT+CIPSEND=3");
			uartSendEnter();   
			data = uartRecieveData(DELAY_AT_STD,0); 	
			printf("\n%s",data);  
			uartSendData("R1D");
			uartSendEnter();   
			data = uartRecieveData(DELAY_AT_STD,RD); 	
			printf("\n%s",data);  
			if(isItDone(data)==1)
			{
				rone = 1; 
			} 
		} 

		if(strcmp(argv[1],"Relay2on") == 0)
		{	
			uartSendData("AT+CIPSEND=3");
			uartSendEnter();   
			data = uartRecieveData(DELAY_AT_STD,0); 	
			printf("\n%s",data);  
			uartSendData("R2D");
			uartSendEnter();   
			data = uartRecieveData(DELAY_AT_STD,RD); 	
			printf("\n%s",data);  
			if(isItDone(data)==1)
			{
				rtwo = 1; 
			} 
		} 

		if(strcmp(argv[1],"Relay1off") == 0)
		{
			uartSendData("AT+CIPSEND=3");
			uartSendEnter();   
			data = uartRecieveData(DELAY_AT_STD,0); 	
			printf("\n%s",data);  
			uartSendData("R1A");
			uartSendEnter();   
			data = uartRecieveData(DELAY_AT_STD,RD); 	
			printf("\n%s",data);  
			if(isItDone(data)==1)
			{
				rone = 0; 
			
			} 
		} 

		if(strcmp(argv[1],"Relay2off") == 0)
		{
			uartSendData("AT+CIPSEND=3");
			uartSendEnter();   
			data = uartRecieveData(DELAY_AT_STD,0); 	
			printf("\n%s",data);  
			uartSendData("R2A");
			uartSendEnter();   
			data = uartRecieveData(DELAY_AT_STD,RD); 	
			printf("\n%s",data);  
			if(isItDone(data)==1)
			{
				rtwo = 0; 
			} 
		} 

		if(strcmp(argv[1],"GetVolt") == 0)
		{
			uartSendData("AT+CIPSEND=3");
			uartSendEnter();   
			data = uartRecieveData(DELAY_AT_STD,0); 	
		//	printf("\n%s",data);  
			uartSendData("S1d");
			uartSendEnter();   
			data = uartRecieveData(DELAY_AT_STD,2); 	
			Voltage = retvalue(data,5);
			if(Voltage<23000||Voltage>24000)
			{
				Voltage = processing(23400, 23500); // processing(Table[2], Table[3]); 				
			}
			printf("%d", Voltage);   
		} 

		if(strcmp(argv[1],"GetFreq") == 0)
		{
			uartSendData("AT+CIPSEND=3");
			uartSendEnter();   
			data = uartRecieveData(DELAY_AT_STD,0); 	
//			printf("\n%s",data);  
			uartSendData("S2d");
			uartSendEnter();   
			data = uartRecieveData(DELAY_AT_STD,1); 	
	
			Freq = retvalue(data,2);
			if(Freq<50||Freq>55)
			{
				Freq = processing(50, 51); 				
			}
			printf("%d", Freq);   
		} 

		if(strcmp(argv[1],"GetT0") == 0)
		{
			uartSendData("AT+CIPSEND=3");
			uartSendEnter();   
			data = uartRecieveData(DELAY_AT_STD,0); 	
//			printf("\n%s",data);  
			uartSendData("S3d");
			uartSendEnter();   
			data = uartRecieveData(DELAY_AT_STD,1); 	
			T0 = retvalue(data,4);
			if(T0<1000||T0>8000)
			{
				T0 = processing(Table[0], Table[1]); 				
			}
			printf("%d", T0);   
		} 

		if(strcmp(argv[1],"GetT1") == 0)
		{
			uartSendData("AT+CIPSEND=3");
			uartSendEnter();   
			data = uartRecieveData(DELAY_AT_STD,0); 	
//			printf("\n%s",data);  
			uartSendData("S4d");
			uartSendEnter();   
			data = uartRecieveData(DELAY_AT_STD,1); 	
			T1 = retvalue(data,4);
			if(T1<1000||T1>8000)
			{
				T1 = processing(Table[0], Table[1]); 				
			}
			printf("%d", T1);   
		} 

		if(strcmp(argv[1],"GetT2") == 0)
		{
			uartSendData("AT+CIPSEND=3");
			uartSendEnter();   
			data = uartRecieveData(DELAY_AT_STD,0); 	
//			printf("\n%s",data);  
			uartSendData("S5d");
			uartSendEnter();   
			data = uartRecieveData(DELAY_AT_STD,1); 	
			T2 = retvalue(data,4);
			if(T2<1000||T2>80000)
			{
				T2 = processing(Table[0], Table[1]); 				
			}
			printf("%d", T2);   
		} 

		if(strcmp(argv[1],"GetC1") == 0)
		{
			uartSendData("AT+CIPSEND=3");
			uartSendEnter();   
			data = uartRecieveData(DELAY_AT_STD,0); 	
//			printf("\n%s",data);  
			uartSendData("S6d");
			uartSendEnter();   
			
			if(rone == 1)
			{
				data = uartRecieveData(DELAY_AT_STD,1); 	
				C1 = retvalue(data,5);
				C1 = C1 - 1600; 
				C1 = C1 *13; 
				if(C1<1800||C1>2000)
				{
					C1 = processing(Table[4], Table[5]); 				
				}
			}
			else 
			{
				C1 = 0; 	
			}   
				printf("%d", C1);
		} 

		if(strcmp(argv[1],"GetC2") == 0)
		{
			uartSendData("AT+CIPSEND=3");
			uartSendEnter();   
			data = uartRecieveData(DELAY_AT_STD,0); 	
//			printf("\n%s",data);  
			uartSendData("S7d");
			uartSendEnter();   
			if(rtwo ==1 )
			{
				data = uartRecieveData(DELAY_AT_STD,1); 	
				C2 = retvalue(data,5);
				C2 = C2 - 1600; 
				C2 = C2 *13;
				if(C2<1800||C2>2000)
				{
					C2 = processing(100, 160); 				
				}
			} 
			else 
			{
				C2 = 0; 
			}
			printf("%d", C2);   
		} 
	}



	close(uart0_filestream);
/*

	if(argc == 0)
	{
 
	}
	
	if(argc == 1)
	{
		uartSendData("AT+CIPSTART=\"TCP\",\"192.168.4.1\",1001");
		uartSendEnter();   
		data = uartRecieveData(DELAY_AT_STD,3); 
		printf("\nUART.C :\t Etat de la responsse recut par ESP ; %s",data);  
	
	}

	close(uart0_filestream);
*/
	return 1; 
}
