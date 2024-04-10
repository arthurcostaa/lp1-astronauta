NAME = lp1

SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = bin
OBJ_DIR = obj

CC = g++
CFLAGS = -I$(INCLUDE_DIR) -pedantic -Wall -Wextra -ansi -std=c++11

EXECUTABLE = $(BIN_DIR)/$(NAME)

_DEPS = astronaut.h flight.h
DEPS = $(patsubst %,$(INCLUDE_DIR)/%,$(_DEPS))

_OBJS = main.o astronaut.o flight.o
OBJS = $(patsubst %,$(OBJ_DIR)/%,$(_OBJS))

all: directories $(EXECUTABLE)

directories:
	mkdir -p $(BIN_DIR) $(OBJ_DIR)

$(EXECUTABLE): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)

.PHONY: clean

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)