#include <karatsuba.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void)
{
	char *str1, *str2;
	size_t n;
	ssize_t str1_len, str2_len;

	str1 = str2 = NULL;
	str1_len = getline(&str1, &n, stdin) - 1;
	str2_len = getline(&str2, &n, stdin) - 1;
	str1_len = str2_len = max(str1_len, str2_len) +
			      (max(str1_len, str2_len) % 2 == 1 ? 1 : 0);
	struct number *x, *y, *xy;
	x = create_number(str1, str1_len);
	y = create_number(str2, str2_len);

	xy = karatsuba(x, y);
	print_number(xy);
	free_number(x);
	free_number(y);
	free_number(xy);
	free(str1);
	free(str2);
	return 0;
}
