CompilerType=g++
CFLAGS=-c -std=c++17 -Wall

all: main.o Allocator.o
	$(CompilerType)  main.o Allocator.o -o a.out
test: main.o Allocator.o
	$(CompilerType)  main.o Allocator.o -o a.out
	./a.out
Allocator.o: Allocator.cpp Allocator.h
	$(CompilerType)  $(CFLAGS) allocator.cpp -o Allocator.o
main.o: main.cpp Allocator.h
	$(CompilerType) $(CFLAGS) main.cpp  -o main.o
clean:
	rm -rf *.o test

