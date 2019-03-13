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
HEADERS=$(SRC)/dl_list.h
OBJECTS=$(OBJ)/main.o $(OBJ)/dl_list.o
BINARY= $(BIN)/main

# Specific variables
debug:		CFLAGS +=-DDEBUG
debug_full:	CFLAGS +=-DDEBUG -DINVALID_CALLOC
coverage: CFLAGS +=-fprofile-arcs -ftest-coverage -DINVALID_CALLOC
coverage: LFLAGS +=-lgcov --coverage

# Check if directories created before any build
-include directories

# Targets
all: directories debug

debug debug_full release coverage: $(HEADERS)

debug debug_full release: $(OBJECTS)
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
	rm -rf *.gcno

directories:
	if [ ! -d "$(OBJ)" ]; then mkdir "$(OBJ)"; fi
	if [ ! -d "$(BIN)" ]; then mkdir "$(BIN)"; fi

