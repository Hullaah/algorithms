#include <count_inversions.h>
/**
 * count_split_inversions - Count inversions across two sorted halves
 * @left: Pointer to the left sorted half
 * @left_size: Size of the left half
 * @right: Pointer to the right sorted half
 * @right_size: Size of the right half
 * @sorted_arr: Pointer to the array where the merged result will be stored
 * Return: The number of split inversions
 */
unsigned long count_split_inversions(int *left, int left_size, int *right, int right_size,
			   int *sorted_arr)
{
	int n = right_size + left_size;
	int j, k;
	unsigned long inversions = 0;

	j = k = 0;
	for (int i = 0; i < n; i++) {
		if (j >= left_size) {
			inversions += left_size - j;
			sorted_arr[i] = right[k++];
		} else if (k >= right_size) {
			sorted_arr[i] = left[j++];
		} else if (left[j] < right[k]) {
			sorted_arr[i] = left[j++];
		} else {
			inversions += left_size - j;
			sorted_arr[i] = right[k++];
		}
	}
	return inversions;
}
