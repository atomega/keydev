csrc = $(wildcard *.cpp)
# \ $(wildcard Personnage.cpp) \ $(wildcard Weapon.cpp) 

obj = $(csrc:.cpp=.o)
CC = g++ 
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
