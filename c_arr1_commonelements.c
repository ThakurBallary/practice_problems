/*
Given two arrays of numbers ranging from -10000 to 10000.
Find the common elements?
input: arr1, len1, arr2, len2, count  
output: return new array which consists of common elements

Note:
count = 0; // initialized in main() to store number of common elements
*/
#include <stdio.h>

int validateIndex(int val) {
	val *= -1;
	val += 10000;
	return val;
}

void record_arr_elements(int *arr, int len, int *dp_arr) {
	if (!arr || len < 1 || !dp_arr) {
		return;
	}
	for (int i = 0; i < len; i++) {
		int value = arr[i];
		if (value < 0) {
			value = validateIndex(value);
		}
		dp_arr[value] = 1;
	}
}

int isExists(int *dp_arr, int i) {
	if (!dp_arr || i < 0) {
		return 0;
	}
	if (dp_arr[i] == 1) {
		return 1;
	}
	return 0;
}

void record_common_elements(int *arr, int len, int *dp_arr) {
	if (!arr || len < 1 || !dp_arr) {
		return;
	}
	for (int i = 0; i < len; i++) {
		int value = arr[i];
		if (value < 0) {
			value = validateIndex(value);
		}
		if (isExists(dp_arr, value)) {
			dp_arr[value] = 2;
		}
	}
}

int get_common_len(int len1, int len2) {
	if (len1 < len2) {
		return len1;
	}
	return len2;
}

int validateNumber(int i) {
	i -= 10000;
	i *= -1;
	return i;
}

void get_common_elements(int *dp_arr, int dp_arr_len, int *common_elements_arr, int *count) {
	for (int i = 0; i < dp_arr_len; i++) {
		if (dp_arr[i] == 2) {
			if (i > 10000) {
				common_elements_arr[(*count)] = validateNumber(i);
				(*count)++;
			}
			else {
				common_elements_arr[(*count)] = i;
				(*count)++;
			}
		}
	}
}

int * commonElements(int *arr1, int len1, int *arr2, int len2, int *count) {
	if (!arr1 || len1 < 1 || !arr2 || len2 < 1) {
		return NULL;
	}
	int dp_arr_len = 20001;
	int *dp_arr = (int*)malloc(sizeof(int) * dp_arr_len);
	int i;
	for (i = 0; i < dp_arr_len; i++) {
		dp_arr[i] = 0;
	}
	record_arr_elements(arr1, len1, dp_arr);
	record_common_elements(arr2, len2, dp_arr);
	int common_len = get_common_len(len1, len2);
	int *common_elements_arr = (int*)malloc(sizeof(int) * common_len);
	get_common_elements(dp_arr, dp_arr_len, common_elements_arr, count);
	
	return common_elements_arr;
}