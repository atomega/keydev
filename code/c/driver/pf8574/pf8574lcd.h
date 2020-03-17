// commandes
#define LCD_CLEARDISPLAY   		0x01
#define LCD_RETURNHOME   			0x02
#define LCD_ENTRYMODESET   		0x04
#define LCD_DISPLAYCONTROL   		0x08
#define LCD_CURSORSHIFT   			0x10
#define LCD_FUNCTIONSET   			0x20
#define LCD_SETCGRAMADDR   		0x40
#define LCD_SETDDRAMADDR   		0x80

// flags pour mode d'ecriture 
#define LCD_ENTRYRIGHT   			0x00
#define LCD_ENTRYLEFT   			0x02
#define LCD_ENTRYSHIFTINCREMENT  0x01
#define LCD_ENTRYSHIFTDECREMENT 	0x00

// flags pour ecran on/off control
#define LCD_DISPLAYON   			0x04
#define LCD_DISPLAYOFF   			0x00
#define LCD_CURSORON   				0x02
#define LCD_CURSOROFF   			0x00
#define LCD_BLINKON   				0x01
#define LCD_BLINKOFF   				0x00

// flags pour display/decalage curseurr 
#define LCD_DISPLAYMOVE   			0x08
#define LCD_CURSORMOVE   			0x00
#define LCD_MOVERIGHT   			0x04
#define LCD_MOVELEFT   				0x00

// flags pour function set
#define LCD_8BITMODE   				0x10
#define LCD_4BITMODE   				0x00
#define LCD_2LINE   					0x08
#define LCD_1LINE   					0x00
#define LCD_5x1DOTS   				0x04
#define LCD_5x8DOTS   				0x00

//flags pour le rétroeclairage
#define LCD_BACKLIGHT   			0x08
#define LCD_NOBACKLIGHT   			0x00

//Pins de gestion de donées. 
#define EN								0x04 // Enable bit
#define RW			   				0x02 // Read/Write bit
#define RS			 		  			0x01 // Register select bit


//DIfferents mode enre commande est ecriture 
#define CMD_MODE 						0x00
#define CHAR_MODE						0x01

//adresse I2C du controlleur pour LCD 
#define LCD_ADDRS 					0x27

//Nombre max de char sur une ligne
#define TOTAL_CHAR_CAP 				20 

int i2c_lcd_init(int addrs); 
void lcd_write_char( char charvalue); 
void lcd_display_string(char line, char pos, char* charvalue); 
void ldc_pulse_En(char data); 
void lcd_write(char cmd, char mode); 
void lcd_write_4bits(char data); 
