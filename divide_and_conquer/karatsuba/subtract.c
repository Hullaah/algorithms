#include <karatsuba.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * subtract - Subtracts two number structures.
 * @x: The first number structure (minuend).
 * @y: The second number structure (subtrahend).
 * Returns: A new number structure representing the result of the subtraction.
 *
 * If the result is negative, it will still be represented as a number structure,
 * but the caller should handle the sign appropriately.
 * The function assumes that the digits in x and y are non-negative and that
 * the subtraction does not result in a negative number.
 * If the result is negative, the caller should handle it accordingly.
 * Note: The function does not check for negative results and will not raise an error
 */
struct number *subtract(const struct number *x, const struct number *y)
{
	struct number *result, *leading_zero_removed_x, *leading_zero_removed_y;
	ssize_t max_length;

	leading_zero_removed_x = removeLeadingZeros(x);
	leading_zero_removed_y = removeLeadingZeros(y);
	max_length = max(leading_zero_removed_x->length,
			 leading_zero_removed_y->length);
	result = malloc(sizeof(struct number));
	result->length = max_length;
	result->digits = (char *)calloc(result->length, sizeof(char));

	ssize_t i, j, k;
	for (i = max_length - 1, j = leading_zero_removed_x->length - 1,
	    k = leading_zero_removed_y->length - 1;
	     j >= 0; i--, j--, k--) {
		char tmp;
		if (k < 0) {
			tmp = leading_zero_removed_x->digits[j];
			result->digits[i] = tmp;
			continue;
		} else if (leading_zero_removed_y->digits[k] > leading_zero_removed_x->digits[j]) {
			leading_zero_removed_x->digits[j - 1]--;
			leading_zero_removed_x->digits[j] += 10;
		}
		tmp = leading_zero_removed_x->digits[j] -
		      leading_zero_removed_y->digits[k];
		result->digits[i] = tmp;
	}
	free_number(leading_zero_removed_x);
	free_number(leading_zero_removed_y);
	return result;
}
