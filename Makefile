all: main
	g++ main.o -o calculator -std=c++11

main:
	g++ -c main.cc -std=c++11
