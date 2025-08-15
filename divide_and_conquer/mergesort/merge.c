#include <mergesort.h>
#include <stdlib.h>

/**
 * merge - Merges two sorted arrays into one sorted array.
 * @left: The first sorted array.
 * @left_size: The size of the first sorted array.
 * @right: The second sorted array.
 * @right_size: The size of the second sorted array.
 * Return: A pointer to the newly merged sorted array.
 */
int *merge(int *left, int left_size, int *right, int right_size)
{
	int *arr = calloc(left_size + right_size, sizeof(int));
	int len = left_size + right_size;
	int j, k;

	j = k = 0;
	for (int i = 0; i < len; i++) {
		if (k >= right_size)
			arr[i] = left[j++];
		else if (j >= left_size)
			arr[i] = right[k++];
		else if (left[j] < right[k])
			arr[i] = left[j++];
		else
			arr[i] = right[k++];
	}
	return arr;
}
