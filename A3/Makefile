CC = g++
CFLAGS = -Wall
SRC = src
INCLUDE = include
LIBHARU = ../libharu

sinePDF: sinePDF.o Sine.o HaruPDF.o
	$(CC) $(CFLAGS) -o sinePDF -L$(LIBHARU)/src sinePDF.o Sine.o HaruPDF.o -lhpdfs

sinePDF.o: $(SRC)/sinePDF.cpp $(INCLUDE)/Sine.h $(INCLUDE)/HaruPDF.h 
	$(CC) $(CFLAGS) -I$(LIBHARU)/include -I$(INCLUDE) -c $(SRC)/sinePDF.cpp

Sine.o: $(SRC)/Sine.cpp $(INCLUDE)/Sine.h
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRC)/Sine.cpp

HaruPDF.o: $(SRC)/HaruPDF.cpp $(INCLUDE)/HaruPDF.h
	$(CC) $(CFLAGS) -I$(LIBHARU)/include -I$(INCLUDE) -c $(SRC)/HaruPDF.cpp

clean:
	rm -f sinePDF *.o