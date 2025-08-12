#include <karatsuba.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * karatsuba - Implements the Karatsuba algorithm for multiplying two numbers.
 * @x: The first number structure.
 * @y: The second number structure.
 * Returns: A new number structure containing the product of x and y.
 *
 * This function uses the Karatsuba algorithm to multiply two numbers represented
 * as structures. It handles padding, splitting, and recursive multiplication.
 */
struct number *karatsuba(const struct number *x, const struct number *y)
{
	struct number *result;

	if (x->length == 1 && y->length == 1) {
		result = malloc(sizeof(struct number));
		result->length = x->digits[0] * y->digits[0] < 10 ? 1 : 2;
		result->digits = calloc(result->length, sizeof(char));
		if (result->length == 2) {
			result->digits[1] = (x->digits[0] * y->digits[0]) % 10;
			result->digits[0] = (x->digits[0] * y->digits[0]) / 10;
		} else {
			result->digits[0] = x->digits[0] * y->digits[0];
		}
		return result;
	}
	ssize_t n = max(x->length, y->length);
	if (n % 2 == 1) {
		n++;
	}
	struct number *x_padded = padWithZeros(x, n - x->length, false);
	struct number *y_padded = padWithZeros(y, n - y->length, false);
	ssize_t half = n / 2;
	struct number *a = split(x_padded, 0, half);
	struct number *b = split(x_padded, half, n);
	struct number *c = split(y_padded, 0, half);
	struct number *d = split(y_padded, half, n);
	struct number *bd = karatsuba(b, d);
	struct number *b_plus_a = add(b, a);
	struct number *c_plus_d = add(c, d);
	struct number *leading_removed_b_plus_a = removeLeadingZeros(b_plus_a);
	struct number *leading_removed_c_plus_d = removeLeadingZeros(c_plus_d);
	struct number *e =
		karatsuba(leading_removed_b_plus_a, leading_removed_c_plus_d);
	struct number *ac = karatsuba(a, c);
	struct number *bd_plus_ac = add(bd, ac);
	struct number *f = subtract(e, bd_plus_ac);
	struct number *ac_padded = padWithZeros(ac, n, true);
	struct number *f_padded = padWithZeros(f, half, true);
	struct number *ac_padded_plus_f_padded = add(ac_padded, f_padded);
	result = add(ac_padded_plus_f_padded, bd);
	free_number(x_padded);
	free_number(y_padded);
	free_number(a);
	free_number(b);
	free_number(c);
	free_number(b_plus_a);
	free_number(c_plus_d);
	free_number(leading_removed_b_plus_a);
	free_number(leading_removed_c_plus_d);
	free_number(bd_plus_ac);
	free_number(d);
	free_number(bd);
	free_number(e);
	free_number(ac);
	free_number(f);
	free_number(ac_padded);
	free_number(f_padded);
	free_number(ac_padded_plus_f_padded);
	return result;
}
