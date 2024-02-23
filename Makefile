SRC=main.c
BIN=main
CC=gcc
CFLAGS=-Wall
LIBS=-lm

all:
	$(CC) $(CFLAGS) -o $(BIN) $(SRC) $(LIBS)

clean:
	$(RM) $(BIN) $(BIN).exe