#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, a, b;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		printf("yes\n");
	}
	return 0;
}