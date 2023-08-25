#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, arr[1001] = { 1, 1, 2, }, s[1001], max = -999;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
		max = max > s[i] ? max : s[i];
	}
	for (int i = 3; i <= max; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[s[i]]);
	}
	return 0;
}