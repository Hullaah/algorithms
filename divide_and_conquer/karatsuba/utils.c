#include <string.h>
#include <karatsuba.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

/**
 * create_number - Creates a number structure from a string of digits.
 * @digits: The string of digits.
 * @length: The length of the string.
 * Returns: A pointer to the newly created number structure.
 */
struct number *create_number(const char *digits, const size_t length)
{
	struct number *num = (struct number *)malloc(sizeof(struct number));
	int i = length;
	char *d = (char *)calloc(length, sizeof(char));

	while (isdigit(digits[i])) {
		d[i] = digits[i] - '0';
		i--;
	}
	num->digits = d;
	num->length = length;
	return num;
}
/**
 * free_number - Frees the memory allocated for a number structure.
 * @num: The number structure to free.
 */
void free_number(struct number *num)
{
	free(num->digits);
	free(num);
}
/**
 * print_number - Prints the digits of a number structure.
 * @num: The number structure to print.
 *
 * This function prints the digits of the number without leading zeros.
 */
void print_number(const struct number *num)
{
	bool leading_zero = true;
	for (size_t i = 0; i < num->length; i++) {
		if (leading_zero && num->digits[i] == 0) {
			continue;
		}
		leading_zero = false;
		putchar(num->digits[i] + '0');
	}
	putchar('\n');
}
/**
 * padWithZeros - Pads a number structure with zeros at the end.
 * @num: The number structure to pad.
 * @n: The number of zeros to pad.
 * Returns: A new number structure with the padded digits.
 */
struct number *padWithZeros(const struct number *num, size_t n)
{
	struct number *x = malloc(sizeof(struct number));
	char *d = (char *)calloc(num->length + n, sizeof(char));
	strncpy(d, num->digits, num->length);
	x->digits = d;
	x->length = x->length + n;
	return x;
}

/**
 * split - Splits a number structure into a new number structure
 *         containing a substring of the original number.
 * @num: The original number structure.
 * @start: The starting index of the substring.
 * @end: The ending index of the substring.
 * Returns: A new number structure containing the substring.
 */
struct number *split(const struct number *num, size_t start, size_t end)
{
	struct number *x = malloc(sizeof(struct number));
	char *d = calloc(end - start, sizeof(char));
	strncpy(d, num->digits + start, end - start);
	x->digits = d;
	x->length = end - start;
	return x;
}
