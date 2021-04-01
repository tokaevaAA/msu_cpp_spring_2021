CompilerType=g++
CFLAGS=-c -std=c++17 -Wall

all: main.o Parser.o
	$(CompilerType)  main.o Parser.o -o a.out
test: main.o Parser.o
	$(CompilerType)  main.o Parser.o -o a.out
	./a.out
Parser.o: Parser.cpp Parser.h
	$(CompilerType)  $(CFLAGS) Parser.cpp -o Parser.o
main.o: main.cpp Parser.h
	$(CompilerType) $(CFLAGS) main.cpp  -o main.o
clean:
	rm -rf *.o test

