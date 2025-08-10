#ifndef KARATSUBA_H
#define KARATSUBA_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

struct number {
	char *digits;
	ssize_t length;
};

/**
* max - Returns the maximum of two size_t values.
* @a: First value.
* @b: Second value.
* Returns: The maximum of a and b.
*/
static inline ssize_t max(ssize_t a, ssize_t b)
{
	return (a > b) ? a : b;
}

struct number *karatsuba(const struct number *x, const struct number *y);

struct number *add(const struct number *x, const struct number *y);

struct number *subtract(const struct number *x, const struct number *y);

struct number *padWithZeros(const struct number *num, size_t n,
			    bool from_right);

struct number *removeLeadingZeros(const struct number *num);

struct number *split(const struct number *num, size_t start, size_t end);

struct number *create_number(const char *digits, const size_t length);

void print_number(const struct number *num);

void free_number(struct number *num);

#endif
