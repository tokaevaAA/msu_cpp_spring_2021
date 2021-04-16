CompilerType=g++
CFLAGS=-c -std=c++17 -Wall

all: main.o BigInt.o 
	$(CompilerType)  main.o BigInt.o -o a.out
test: main.o BigInt.o 
	$(CompilerType)  main.o BigInt.o -o a.out
	./a.out
BigInt.o:  BigInt.cpp BigInt.h 
	$(CompilerType)  $(CFLAGS) BigInt.cpp -o BigInt.o
main.o: main.cpp BigInt.h 
	$(CompilerType) $(CFLAGS) main.cpp  -o main.o
clean:
	rm -rf *.o test

