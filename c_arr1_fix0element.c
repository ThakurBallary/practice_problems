/*
Given an unsorted array of numbers ranging from 1 to 500, now one element in the array is changed to 0.
Find that element?
input: arr and len
output: return index of element whose value is 0

Note: return -1 for invalid cases
*/
#include <stdio.h>
int fix0element(int *arr, int len) {
	if (!arr || len < 1) {
		return -1;
	}
	for (int i = 0; i < len; i++) {
		if (arr[i] == 0) {
			return i;
		}
	}
	return -1;
}