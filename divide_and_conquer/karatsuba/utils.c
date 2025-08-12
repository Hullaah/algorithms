#include <karatsuba.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * create_number - Creates a number structure from a string of digits.
 * @digits: The string of digits.
 * @length: The length of the string.
 * Returns: A pointer to the newly created number structure.
 */
struct number *create_number(const char *digits, const ssize_t length)
{
	struct number *num = (struct number *)malloc(sizeof(struct number));
	size_t digits_len = strlen(digits);

	num->digits = (char *)calloc(length + (length % 2 == 1 ? 1 : 0),
				     sizeof(char));
	num->length = length + (length % 2 == 1 ? 1 : 0);
	memcpy(num->digits + num->length - digits_len + 1, digits, digits_len - 1);
	digitize(num->digits + num->length - digits_len + 1, digits_len - 1);
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
	for (ssize_t i = 0; i < num->length; i++) {
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
 * @from_right: If true, pads zeros to the right; otherwise, pads to the left.
 * Returns: A new number structure with the padded digits.
 */
struct number *padWithZeros(const struct number *num, size_t n, bool from_right)
{
	struct number *x = malloc(sizeof(struct number));
	char *d = (char *)calloc(num->length + n, sizeof(char));
	memcpy(d + (from_right ? 0 : n), num->digits, num->length);
	x->digits = d;
	x->length = num->length + n;
	return x;
}
/**
 * removeLeadingZeros - Removes leading zeros from a number structure.
 * @num: The number structure from which to remove leading zeros.
 * Returns: A new number structure with leading zeros removed.
 */
struct number *removeLeadingZeros(const struct number *num)
{
	ssize_t i = 0;
	while (i < num->length && num->digits[i] == 0) {
		i++;
	}
	if (i == num->length) {
		i--;
	}
	struct number *x = malloc(sizeof(struct number));
	x->length = num->length - i;
	x->digits = (char *)calloc(x->length, sizeof(char));
	memcpy(x->digits, num->digits + i, x->length);
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
	memcpy(d, num->digits + start, end - start);
	x->digits = d;
	x->length = end - start;
	return x;
}
