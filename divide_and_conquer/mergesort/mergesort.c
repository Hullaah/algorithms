#include <mergesort.h>
#include <stdlib.h>
#include <string.h>

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
	int *left_half = malloc(left_size * sizeof(int));
	int *right_half = malloc(right_size * sizeof(int));
	left_half = memcpy(left_half, arr, sizeof(int) * left_size);
	right_half =
		memcpy(right_half, arr + left_size, sizeof(int) * right_size);
	int *left = mergesort(left_half, left_size);
	int *right = mergesort(right_half, right_size);
	sorted_arr = merge(left, left_size, right, right_size);
	free(left_half);
	free(right_half);
	free(left);
	free(right);
	return sorted_arr;
}
