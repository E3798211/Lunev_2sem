# Compile settings
CC=gcc
CFLAGS=-Wall 
LFLAFS=

# Sources
SRC=src
OBJ=obj
BIN=bin
COV=cov

SOURCES=$(SRC)/$(wildcard *.c)
OBJECTS=$(OBJ)/main.o $(OBJ)/dl_list.o
BINARY= $(BIN)/main

# Specific variables
debug:    CFLAGS +=-DDEBUG
coverage: CFLAGS +=-fprofile-arcs -ftest-coverage
coverage: LFLAGS +=-lgcov --coverage

# Check if directories created before any build
-include directories

# Targets
all: directories debug

debug release: $(OBJECTS)
	$(CC) $(LFLAGS) -o $(BINARY) $^

coverage: $(OBJECTS)
	$(CC) $(LFLAGS) -o $(BINARY) $^
	./$(BINARY) 1>/dev/null 2>/dev/null
	gcov $(OBJECTS)
	if [ ! -d "$(COV)" ]; then mkdir "$(COV)"; fi
	mv *.gcov "$(COV)" 

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@


# Additional targets
.PHONY: clean directories

clean:
	rm -rf $(OBJ)
	rm -rf $(COV)

directories:
	if [ ! -d "$(OBJ)" ]; then mkdir "$(OBJ)"; fi
	if [ ! -d "$(BIN)" ]; then mkdir "$(BIN)"; fi

