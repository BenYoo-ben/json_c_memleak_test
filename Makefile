SHELL = /bin/sh

CC=gcc
CFLAGS = -Wall -g

JSON_C_DIR = ./json_1.3/json-c
CFLAGS += -I$(JSON_C_DIR)/include/json-c
LDFLAGS = -L$(JSON_C_DIR)/lib -ljson-c

OBJ_DIR = ./obj
SRC_DIR = ./src
EXE_DIR = ./exe

SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

%: %.c

	$(CC) $(CFLAGS) $(LDFLAGS) -o $(EXE_DIR)/$@ $<

valgrind: $(PROGS)

	valgrind $(EXE_DIR)/*


clean:
	rm -f $(EXE_DIR)/*


