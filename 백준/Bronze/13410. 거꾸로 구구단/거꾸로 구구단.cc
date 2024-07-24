#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int re(int a) {
	int r = 0;
	while (a > 0) {
		r = r * 10 + (a % 10);
		a /= 10;
	}
	return r;
}

int main() {
	//freopen("input.txt", "rt", stdin);


	int a, b, max = 0, r = 0;

	scanf("%d %d", &a, &b);

	for (int i = 1; i <= b; i++) {
		r = re(i * a);
		max = max < r ? r : max;
	}
	printf("%d\n", max);

	return 0;
}