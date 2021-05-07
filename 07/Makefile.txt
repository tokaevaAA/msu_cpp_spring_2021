CompilerType=g++
CFLAGS=-c -std=c++17 -Wall

all: main.o Vector.o Allocator.o Iterator.o 
	$(CompilerType)  main.o Vector.o Allocator.o Iterator.o  -o a.out
test: main.o Vector.o Allocator.o Iterator.o 
	$(CompilerType)  main.o Vector.o Allocator.o Iterator.o  -o a.out
	./a.out
Vector.o:  Vector.cpp Vector.h Allocator.h Iterator.h
	$(CompilerType)  $(CFLAGS) Vector.cpp -o Vector.o
Allocator.o:  Allocator.cpp Allocator.h 
	$(CompilerType)  $(CFLAGS) Allocator.cpp -o Allocator.o
Iterator.o:  Iterator.cpp Iterator.h
	$(CompilerType)  $(CFLAGS) Iterator.cpp -o Iterator.o
main.o: main.cpp Vector.h Allocator.h Iterator.h 
	$(CompilerType) $(CFLAGS) main.cpp  -o main.o
clean:
	rm -rf *.o test

