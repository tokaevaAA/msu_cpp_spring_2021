CompilerType=g++
CFLAGS=-c -std=c++17 -Wall

all: main.o filesort.o
	$(CompilerType)  main.o filesort.o -o a.out
test: main.o filesort.o
	$(CompilerType)  main.o filesort.o -o a.out
	./a.out

filesort.o: filesort.cpp filesort.hpp
	$(CompilerType) $(CFLAGS) filesort.cpp  -o filesort.o

main.o: main.cpp filesort.hpp
	$(CompilerType) $(CFLAGS) main.cpp  -o main.o

clean:
	rm -rf *.o test

