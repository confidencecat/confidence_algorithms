#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int a;
	while (1) {
		scanf("%d", &a);
		if (a == 0) break;
		printf("%d\n", a * (a + 1) / 2);
	}
	
	return 0;
}