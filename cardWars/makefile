CC=g++

CFLAGS =-c -Wall

all: war

war: warMain.o Card.o Player.o Deck.o 
	$(CC) warMain.o Card.o Player.o Deck.o -o war

warMain.o: warMain.cpp
	$(CC) $(CFLAGS) warMain.cpp

Card.o: Card.cpp
	$(CC) $(CFLAGS) Card.cpp

Player.o: Player.cpp
	$(CC) $(CFLAGS) Player.cpp

Deck.o: Deck.cpp
	$(CC) $(CFLAGS) Deck.cpp
	
clean:
	rm *.o war
