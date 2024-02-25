#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < (n % 4 == 0 ? n / 4 : n / 4 + 1); i++) {
		printf("long ");
	}
	printf("int\n");
	return 0;
}