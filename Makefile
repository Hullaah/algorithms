CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu11 -g -Iinclude
KARATSUBA_SRCS = $(wildcard divide_and_conquer/karatsuba/*.c)
KARATSUBA_OBJS = $(KARATSUBA_SRCS:.c=.o)

.PHONY: all clean karatsuba
all: karatsuba

karatsuba: divide_and_conquer/karatsuba/karatsuba

divide_and_conquer/karatsuba/karatsuba: $(KARATSUBA_OBJS)
	$(CC) $(CFLAGS) -o divide_and_conquer/karatsuba/karatsuba $^

divide_and_conquer/karatsuba/%.o: divide_and_conquer/karatsuba/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(KARATSUBA_OBJS) divide_and_conquer/karatsuba/karatsuba
