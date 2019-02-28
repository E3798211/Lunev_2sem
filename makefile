# Compile settings
CC=gcc
CFLAGS=-Wall -fprofile-arcs -ftest-coverage
LFLAGS=-lgcov --coverage

# Sources
SRC=src
OBJ=obj
BIN=bin

SOURCES=$(SRC)/$(wildcard *.c)
OBJECTS=$(OBJ)/main.o $(OBJ)/dl_list.o
BINARY= $(BIN)/main

# $(info $(SOURCES))

# Tgt
all: main

main: $(OBJECTS)
	$(CC) $(CFLAGS) $(LFLAGS) -o $(BINARY) $^

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $(LFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -rf $(OBJ)/*.o
