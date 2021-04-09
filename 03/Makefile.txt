CompilerType=g++
CFLAGS=-c -std=c++17 -Wall

all: main.o Matrix.o ProxyRow.o
	$(CompilerType)  main.o Matrix.o ProxyRow.o -o a.out
test: main.o Matrix.o ProxyRow.o
	$(CompilerType)  main.o Matrix.o ProxyRow.o -o a.out
	./a.out
ProxyRow.o: ProxyRow.cpp ProxyRow.h
	$(CompilerType)  $(CFLAGS) ProxyRow.cpp -o ProxyRow.o
Matrix.o:  Matrix.cpp Matrix.h ProxyRow.h
	$(CompilerType)  $(CFLAGS) Matrix.cpp -o Matrix.o
main.o: main.cpp Matrix.h ProxyRow.h
	$(CompilerType) $(CFLAGS) main.cpp  -o main.o
clean:
	rm -rf *.o test

