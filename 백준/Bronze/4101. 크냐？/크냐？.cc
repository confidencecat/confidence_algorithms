#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {

	int a, b;

	while (1) {
		scanf("%d %d", &a, &b);
		if (!a && !b) break;
		printf("%s\n", a > b ? "Yes" : "No");
	}
	
	return 0;
}