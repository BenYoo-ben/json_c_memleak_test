SHELL = /bin/sh

CC=gcc
CFLAGS = -Wall -g

JSON_C_DIR = ./lib/jsonc_1.3
CFLAGS += -I$(JSON_C_DIR)


SRC_DIR := src
OBJ_DIR := obj

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRC_FILES))
EXE_FILES := $(patsubst $(SRC_DIR)/%.c,%.out,$(SRC_FILES))


all: $(EXE_FILES)

$(EXE_FILES): $(OBJ_FILES)	
	$(CC) $(CFLAGS) $(OBJ_DIR)/$*.o -o $*.out

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

valgrind: $(EXE_FILES)

	valgrind $(EXE_DIR)/$*


clean:
	rm -f ./$(OBJ_DIR)/*
	rm -f ./*.out
