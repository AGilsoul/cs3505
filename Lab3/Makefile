
Car: main.o Car.o
	g++ -o Car main.o Car.o

main.o: main.cpp include/Car.h
	g++ -I include -c main.cpp

Car.o: Car.cpp include/Car.h
	g++ -I include -c Car.cpp