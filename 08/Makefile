CompilerType=g++
CFLAGS=-c -std=c++17 -Wall

all: main.o 
	$(CompilerType)  main.o  -o a.out
test: main.o 
	$(CompilerType)  main.o  -o a.out
	./a.out

main.o: main.cpp ThreadPool.hpp
	$(CompilerType) $(CFLAGS) main.cpp  -o main.o
clean:
	rm -rf *.o test

