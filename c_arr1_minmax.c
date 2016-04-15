/*
Find minimum and maximum elements in an unsorted array
input: arr and len
ouput: return new array, "result" whose result[0] is min and result[1] is max
*/
#include <stdio.h>
int * minmax(int *arr, int len) {
	if (!arr || len < 1) {
		return NULL;
	}
	int min = arr[0];
	int max = arr[0];
	for (int i = 1; i < len; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
		else if (arr[i] > max) {
			max = arr[i];
		}
	}
	int *result = (int*)malloc(sizeof(int) * 2);
	result[0] = min;
	result[1] = max;
	return result;
}