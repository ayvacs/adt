CC = gcc
CFLAGS = -Wall -Wextra -O2 -I.

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

LIB = libadt.a

all: $(LIB)

$(LIB): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIB)

.PHONY: all clean