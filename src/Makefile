CC = gcc
CFLAGS = -g -Wall -lm
BIN = tp4
XFLAGSA = -i ./entrada/p -o p
XFLAGSB = -i ./entrada/m -o m
XFLAGSC = -i ./entrada/g -o g
XFLAGSD = -i ./entrada/pp -o pp
SAIDAS = p m g
RM = *.o *.h.gch $(BIN) $(SAIDAS) temp_*

io: io.c io.h
	$(CC) -c io.c io.h $(CFLAGS)

externo: externo.c externo.h
	$(CC) -c externo.c externo.h $(CFLAGS)

ordena: ordena.c ordena.h
	$(CC) -c ordena.c ordena.h $(CFLAGS)

main: externo io ordena tp4.c
	$(CC) -o $(BIN) tp4.c io.o ordena.o externo.o $(CFLAGS)

m: clean main
	./$(BIN) $(XFLAGSB)

p: clean main
	./$(BIN) $(XFLAGSA)
	
pp: clean main
	./$(BIN) $(XFLAGSD)

g: clean main
	./$(BIN) $(XFLAGSC)

valgrind: clean main
	valgrind ./$(BIN) $(XFLAGSA)
all: main

clean:
	rm -rf $(RM)

run: clean main
	./$(BIN) $(XFLAGSA)
