#include <karatsuba.h>
#include <stdio.h>
#include <stdlib.h>

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
	struct number *e = karatsuba(removeLeadingZeros(add(b, a)),
				     removeLeadingZeros(add(d, c)));
	struct number *ac = karatsuba(a, c);
	struct number *f = subtract(e, add(bd, ac));
	result =
		add(add(padWithZeros(ac, n, true), padWithZeros(f, half, true)),
		    bd);
	free_number(x_padded);
	free_number(y_padded);
	free_number(a);
	free_number(b);
	free_number(c);
	free_number(d);
	free_number(bd);
	free_number(e);
	free_number(ac);
	free_number(f);
	return result;
}
