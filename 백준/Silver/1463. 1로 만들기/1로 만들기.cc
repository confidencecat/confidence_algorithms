#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define min(a, b) a > b ? b : a

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, arr[1000001] = { 0 };
	scanf("%d", &n);

	for (int i = 2; i < n + 1; i++) {
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0) {
			arr[i] = min(arr[i / 2] + 1, arr[i]);
		}
		if (i % 3 == 0) {
			arr[i] = min(arr[i / 3] + 1, arr[i]);
		}  
	}
	printf("%d", arr[n]);
	return 0;
}