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

/**
 * digitize - Converts a string of digits into an array of integers.
 * @digits: The string of digits to convert.
 * @length: The length of the string.
 * This function modifies the digits in place, converting characters to integers.
 * For example, '0' becomes 0, '1' becomes 1, ..., '9' becomes 9.
 * It assumes that the input string contains valid digit characters.
 */
static inline void digitize(char *digits, size_t length)
{
	for (size_t i = 0; i < length; i++)
		digits[i] -= '0';
}

struct number *karatsuba(const struct number *x, const struct number *y);

struct number *add(const struct number *x, const struct number *y);

struct number *subtract(const struct number *x, const struct number *y);

struct number *padWithZeros(const struct number *num, size_t n,
			    bool from_right);

struct number *removeLeadingZeros(const struct number *num);

struct number *split(const struct number *num, size_t start, size_t end);

struct number *create_number(const char *digits, const ssize_t length);

void print_number(const struct number *num);

void free_number(struct number *num);

#endif
