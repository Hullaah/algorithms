#include <count_inversions.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	size_t bufsize;
	int capacity, num, n, *arr, *tmp;
	unsigned long inversions;
	char *line;

	line = NULL;
	arr = NULL;
	capacity = n = 0;
	while (getline(&line, &bufsize, stdin) > 0) {
		sscanf(line, "%d", &num);
		if (n >= capacity)
			arr = realloc(arr,
				      sizeof(int) *
					      (capacity = capacity ?
								  capacity * 2 :
								  8));
		arr[n++] = num;
		free(line);
		line = NULL;
		bufsize = 0;
	}
	free(line);
	inversions = count_inversions(arr, n, tmp = malloc(n * sizeof(int)));
	free(tmp);
	free(arr);
	printf("%lu inversions.\n", inversions);
	return 0;
}
