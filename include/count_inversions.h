#ifndef COUNT_INVERSIONS_H
#define COUNT_INVERSIONS_H

unsigned long count_inversions(int *arr, int size, int *sorted_arr);

unsigned long count_split_inversions(int *left, int left_size, int *right,
				     int right_size, int *sorted_arr);

#endif
