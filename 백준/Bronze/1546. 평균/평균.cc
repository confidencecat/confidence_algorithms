#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	//freopen("input.txt", "rt", stdin);
	double ans = 0, a[1001], mx = -1;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &a[i]);
		if (a[i] > mx) mx = a[i];
	}
	for (int i = 0; i < n; i++) {
		ans += a[i] / mx * 100;
	}
	printf("%lf", ans / n);
	return 0;
}