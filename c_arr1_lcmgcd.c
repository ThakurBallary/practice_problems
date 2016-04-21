/*
Given an array of N numbers. Find its lcm and gcd.
input : arr, len, *lcm, *gcd
output : modify *lcm and *gcd with respective values
*/
#include<stdio.h>
int gcd(int a, int b){
    if(!b) {
		return a; 
	}
    return gcd(b, a%b);
}
void lcm_gcd(int *arr, int len, int *lcm, int *gcd){
	if(!arr || len < 2) {
		return;
	}
    int l = arr[0], g = arr[0];
    for(int i = 1; i < len; i++){
        g = gcd(g, arr[i]);
        l *= arr[i] / g;
    }
	*lcm = l;
	*gcd = g;
}