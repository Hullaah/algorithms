#include <count_inversions.h>
#include <stdlib.h>

unsigned long count_inversions(int *arr, int size, int *sorted_arr)
{
	int left_size = size - size / 2;
	int right_size = size / 2;

	if (size == 1) {
		*sorted_arr = *arr;
		return 0;
	}
	int *left_half = malloc(left_size * sizeof(int));
	int *right_half = malloc(right_size * sizeof(int));
	unsigned long left_inversions =
		count_inversions(arr, left_size, left_half);
	unsigned long right_inversions =
		count_inversions(arr + left_size, right_size, right_half);
	unsigned long split_inversions = count_split_inversions(
		left_half, left_size, right_half, right_size, sorted_arr);
	free(left_half);
	free(right_half);
	return left_inversions + split_inversions + right_inversions;
}
