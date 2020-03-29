cpp_src = $(wildcard *.cpp) \ $(wildcard lowlayer/i2c/*.cpp) 
c_src = $(wildcard driver/pf8574/*.c)

cpp_obj = $(cpp_src:.cpp=.o)
c_obj = $(c_src:.c=.o)
CC = g++ 
CFLAGS = -Wall -pedantic  
LDFLAGS = 
EXEC = runtest


all : $(EXEC)

$(EXEC): $(cpp_obj) $(c_obj)
	$(CC) -o $@ $^ $(LDFLAGS) 
 
clean: 
	rm -rf $(obj)

cleanall: 
	rm -rf $(obj) $(EXEC)
