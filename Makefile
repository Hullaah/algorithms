CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu11 -g -Iinclude

KARATSUBA_SRCS = $(wildcard divide_and_conquer/karatsuba/*.c)
KARATSUBA_OBJS = $(KARATSUBA_SRCS:.c=.o)
MERGESORT_SRCS = $(wildcard divide_and_conquer/mergesort/*.c)
MERGESORT_OBJS = $(MERGESORT_SRCS:.c=.o)
COUNT_INVERSIONS_SRCS = $(wildcard divide_and_conquer/count_inversions/*.c)
COUNT_INVERSIONS_OBJS = $(COUNT_INVERSIONS_SRCS:.c=.o)

.PHONY: all clean karatsuba divide_and_conquer mergesort count_inversions
all: divide_and_conquer

divide_and_conquer: karatsuba mergesort

karatsuba: divide_and_conquer/karatsuba/karatsuba

mergesort: divide_and_conquer/mergesort/mergesort

count_inversions: divide_and_conquer/count_inversions/count_inversions

divide_and_conquer/karatsuba/karatsuba: $(KARATSUBA_OBJS)

divide_and_conquer/karatsuba/%.o: divide_and_conquer/karatsuba/%.c

divide_and_conquer/mergesort/mergesort: $(MERGESORT_OBJS)

divide_and_conquer/mergesort/%.o: divide_and_conquer/mergesort/%.c

divide_and_conquer/count_inversions/count_inversions: $(COUNT_INVERSIONS_OBJS)

divide_and_conquer/count_inversions/%.o: divide_and_conquer/count_inversions/%.c

clean:
	rm -f $(KARATSUBA_OBJS) $(MERGESORT_OBJS) $(COUNT_INVERSIONS_OBJS) \
		divide_and_conquer/karatsuba/karatsuba \
		divide_and_conquer/mergesort/mergesort \
		divide_and_conquer/count_inversions/count_inversions
