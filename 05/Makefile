CompilerType=g++
CFLAGS=-c -std=c++17 -Wall

all: main.o Serializer.o 
	$(CompilerType)  main.o Serializer.o -o a.out
test: main.o Serializer.o 
	$(CompilerType)  main.o Serializer.o -o a.out
	./a.out
Serializer.o:  Serializer.cpp Serializer.h 
	$(CompilerType)  $(CFLAGS) Serializer.cpp -o Serializer.o
main.o: main.cpp Serializer.h 
	$(CompilerType) $(CFLAGS) main.cpp  -o main.o
clean:
	rm -rf *.o test

