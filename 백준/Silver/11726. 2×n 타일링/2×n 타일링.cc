#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	//freopen("input.txt", "rt", stdin);

	int n, arr[1001] = { 1,1, };
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 2] + arr[i - 1];
		arr[i] %= 10007;
	}
	printf("%d", arr[n]);
	return 0;
}