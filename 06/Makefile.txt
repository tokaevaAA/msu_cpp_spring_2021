CompilerType=g++
CFLAGS=-c -std=c++17 -Wall

all: main.o Formater.o 
	$(CompilerType)  main.o Formater.o -o a.out
test: main.o Formater.o 
	$(CompilerType)  main.o Formater.o -o a.out
	./a.out
Formater.o:  Formater.cpp Formater.h 
	$(CompilerType)  $(CFLAGS) Formater.cpp -o Formater.o
main.o: main.cpp Formater.h 
	$(CompilerType) $(CFLAGS) main.cpp  -o main.o
clean:
	rm -rf *.o test

