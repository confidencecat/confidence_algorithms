#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
	//freopen("input.txt", "rt", stdin);
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d + %d = %d\n", i, a, b, a + b);
	}
	return 0;
}