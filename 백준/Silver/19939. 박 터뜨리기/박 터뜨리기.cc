#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, k, a = 0;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; i++) {
		a += i;
	}
	if (n < a) printf("-1");
	else {
		if ((n == a) || (n - a) % k == 0) {
			printf("%d", k - 1);
		}
		else {
			printf("%d", k);
		}
	}
	return 0;
}