csrc = $(wildcard *.c) 

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
