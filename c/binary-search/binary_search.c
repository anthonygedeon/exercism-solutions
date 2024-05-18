#include "binary_search.h"
#include <stdio.h>

const int *binary_search(int value, const int *arr, size_t length) {
	int mid   = 0;
	int left  = 0;
	int right = length-1;
	
	while (left <= right) {
		mid = (left + right) / 2;

		if (value == arr[mid]) {
			return &arr[mid];
		} else if (value > arr[mid]) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return NULL;
}
