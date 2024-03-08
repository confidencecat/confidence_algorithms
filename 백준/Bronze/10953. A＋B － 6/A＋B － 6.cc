#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, a, b;
	scanf("%d", &n);
	while (n--) {
		scanf("%d,%d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}