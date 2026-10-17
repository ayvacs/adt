CC = gcc
CFLAGS = -Wall -Wextra -O2 -I.

SRCS = $(wildcard src/*.c)
OBJS = $(patsubst src/%.c,bin/%.o,$(SRCS))
LIB = libadt.a

SRC_DIR = src
BIN_DIR = bin


all: $(LIB)

$(LIB): $(OBJS)
	ar rcs $@ $^

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN_DIR) $(OBJS) $(LIB)

.PHONY: all clean
