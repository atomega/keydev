csrc = $(wildcard *.c) 

obj = $(csrc:.c=.o)
CC = gcc -g
CFLAGS = 
LDFLAGS =
EXEC = ampcontrol


all : $(EXEC)

$(EXEC): $(obj) 
	$(CC) -o $@ $^ $(LDFLAGS) 
 
clean: 
	rm -rf $(obj)

cleanall: 
	rm -rf $(obj) $(EXEC)
