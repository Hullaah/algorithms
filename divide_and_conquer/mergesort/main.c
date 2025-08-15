#include <mergesort.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	size_t bufsize;
	int capacity, num, n, *arr, *tmp;
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
	tmp = arr;
	arr = mergesort(arr, n);
	free(tmp);
	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}
	free(arr);
	return 0;
}
