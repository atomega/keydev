#include "main.h"
#include "lcd.h"
#include "getip.h"
#include "dbcomm.h"
int main()
{
	i2c_lcd_init(LCD_ADDRS); 
	lcd_display_string(1, 0, "       R-A-M      "); 
	get_ip_eth(); 
	get_ip_wlan(); 	
//	testDb(); 	
  return 0; 
}
