#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int s = 0, a;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &a);
		s += a;
	}
	printf("%d\n", s);
	
	return 0;
}