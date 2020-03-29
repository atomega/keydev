csrc = $(wildcard *.c) \ $(wildcard lowlayer/i2c_raspberry/i2c/*.c) \ $(wildcard driver/bh1750/*.c) \ $(wildcard algorithms/*.c) \ $(wildcard driver/ma12070/*.c) \ $(wildcard driver/pf8574/*.c)

obj = $(csrc:.c=.o)
CC = gcc 
CFLAGS = -Wall -pedantic  
LDFLAGS = 
EXEC = runtest


all : $(EXEC)

$(EXEC): $(obj) 
	$(CC) -o $@ $^ $(LDFLAGS) 
 
clean: 
	rm -rf $(obj)

cleanall: 
	rm -rf $(obj) $(EXEC)
