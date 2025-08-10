#include <karatsuba.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * subtract
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
		if (leading_zero_removed_y->digits[k] < 0) {
			tmp = leading_zero_removed_x->digits[j];
		} else if (leading_zero_removed_y->digits[i] > x->digits[i]) {
			leading_zero_removed_x->digits[i - 1]--;
			leading_zero_removed_x->digits[i] += 10;
		}
		tmp = leading_zero_removed_x->digits[i] -
		      leading_zero_removed_y->digits[i];
		result->digits[i] = tmp;
	}
	return result;
}
