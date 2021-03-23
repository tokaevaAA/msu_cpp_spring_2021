all: main.o Allocator.o
	g++ -std=c++17 main.o Allocator.o -o a.out
Allocator.o: Allocator.cpp Allocator.h
	g++  -c -std=c++17 allocator.cpp -o Allocator.o
main.o: main.cpp Allocator.h
	g++ -c -std=c++17 main.cpp  -o main.o
clean:
	rm -f main.o Allocator.o a.out

