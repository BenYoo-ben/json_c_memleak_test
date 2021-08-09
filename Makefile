SHELL = /bin/sh

CC=gcc
CFLAGS = -Wall -g 

JSON_C_DIR = ./lib
CFLAGS += -I$(JSON_C_DIR)/include
LDFLAGS = -L$(JSON_C_DIR)/lib -ljson-c

SRC_DIR := src
OBJ_DIR := obj

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRC_FILES))
EXE_FILES := $(patsubst $(SRC_DIR)/%.c,%.out,$(SRC_FILES))


all: $(EXE_FILES)

$(EXE_FILES): $(OBJ_FILES)	
	$(CC) $(CFLAGS)  $(OBJ_DIR)/$*.o -o $*.out $(LDFLAGS) 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS)  -c -o $@ $< $(LDFLAGS)

val: $(EXE_FILES)

	valgrind -v ./$(EXE_FILES)

clean:
	rm -f ./$(OBJ_DIR)/*.o
	rm -f ./*.out
	rm -f ./*.txt
