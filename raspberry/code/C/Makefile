INC = /usr/include/pgsql

CC=gcc 
CFLAGS= -Wall -pedantic  
LDFLAGS= 
EXEC= runlcd


all : $(EXEC)

$(EXEC): main.o i2c.o lcd.o getip.o dbcomm.o 
	$(CC) -o $@ $^ $(LDFLAGS) -lpq
 
main.o: main.c
	$(CC) -o $@ -c $< $(CFLAGS)

i2c.o: i2c.c
	$(CC) -o $@ -c $< $(CFLAGS)

lcd.o: lcd.c
	$(CC) -o $@ -c $< $(CFLAGS)

getip.o: getip.c
	$(CC) -o $@ -c $< $(CFLAGS)

dbcomm.o: dbcomm.c
	$(CC) -c -I/usr/local/pgsql/include dbcomm.c

clean: 
	rm -rf *.o *.so

cleanall: 
	rm -rf *.o .so $(EXEC)
