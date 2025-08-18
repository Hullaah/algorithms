#include <mergesort.h>
#include <stdlib.h>

/**
 * mergesort - Sorts an array of integers using the merge sort algorithm.
 * @arr: The array to be sorted.
 * @size: The number of elements in the array.
 * Return: A pointer to the newly sorted array.
 */
int *mergesort(int *arr, int size)
{
	int *sorted_arr;
	int left_size = size - size / 2;
	int right_size = size / 2;

	if (size == 1) {
		sorted_arr = malloc(sizeof(int));
		*sorted_arr = *arr;
		return sorted_arr;
	}
	int *left = mergesort(arr, left_size);
	int *right = mergesort(arr + left_size, right_size);
	sorted_arr = merge(left, left_size, right, right_size);
	free(left);
	free(right);
	return sorted_arr;
}
