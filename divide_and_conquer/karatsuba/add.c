#include <karatsuba.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * add - Adds two number structures.
 * @x: The first number structure.
 * @y: The second number structure.
 * Returns: A new number structure containing the sum of x and y.
 */
struct number *add(const struct number *x, const struct number *y)
{
	struct number *result;
	ssize_t max_length = max(x->length, y->length);

	result = malloc(sizeof(struct number));
	result->length = max_length + 1;
	result->digits = (char *)calloc(result->length, sizeof(char));

	char carry = 0;
	ssize_t i, j, k;
	for (i = max_length, j = x->length - 1, k = y->length - 1;
	     j >= 0 || k >= 0; i--, j--, k--) {
		char tmp;
		if (j < 0)
			tmp = carry + y->digits[k];
		else if (k < 0)
			tmp = carry + x->digits[j];
		else
			tmp = carry + x->digits[j] + y->digits[k];
		result->digits[i] = tmp % 10;
		carry = tmp / 10;
	}
	result->digits[i] = carry;
	return result;
}
