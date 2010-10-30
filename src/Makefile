CC = gcc
CFLAGS = -g -Wall -lm
BIN = tp4
XFLAGSA = -i ./entrada/p -o p
XFLAGSB = -i ./entrada/m -o m
XFLAGSC = -i ./entrada/g -o g
SAIDAS = p m g
RM = *.o *.h.gch $(BIN) $(SAIDAS)

io: io.c io.h
	$(CC) -c io.c io.h $(CFLAGS)

main: io tp4.c
	$(CC) -o $(BIN) tp4.c io.o $(CFLAGS)

m: clean main
	./$(BIN) $(XFLAGSB)

p: clean main
	./$(BIN) $(XFLAGSA)

g: clean main
	./$(BIN) $(XFLAGSC)

valgrind: clean all
	valgrind ./$(BIN) $(XFLAGSA)
all: main

clean:
	rm -rf $(RM)

run: clean all
	./$(BIN) $(XFLAGSA)
