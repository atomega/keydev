
csrc = $(wildcard *.c) \ $(wildcard i2c/*.c) \ $(wildcard bh1750/*.c) \ $(wildcard algorithms/*.c) \ $(wildcard ma12070/*.c)

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
