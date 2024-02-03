#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int len(int n) {
	int count = 0;
	while (1) {
		if (n <= 0) break;
		n /= 10;
		count++;
	}
	return count;
}

int sq(int n) {
	int a = 1;
	for (int i = 0; i < n; i++) {
		a *= 10;
	}
	return a;
}

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n%d\n", a + b - c, ((a * sq(len(b)) + b) - c));
	return 0;
}