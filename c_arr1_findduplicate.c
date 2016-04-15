/*
Given an array of N unique number except 1. Find that number?
input: arr, len
output: return duplicate number or -1 for invalid cases
*/
#include <stdio.h>
int findduplicate(int *arr, int len) {
	if (!arr || len < 1) {
		return -1;
	}
	int dp_arr[1000] = { 0 };
	int i;
	for (i = 0; i < len; i++) {
		dp_arr[arr[i]]++;
	}
	for (i = 0; i < 1000; i++) {
		if (dp_arr[i] == 2) {
			return i;
		}
	}
	return -1;
}