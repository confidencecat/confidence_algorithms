#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main() {
	int n, m = 1, c = 1;
	scanf("%d", &n);
	while (n > m) {
		m += 6 * c;
		c++;
	}
	printf("%d\n", c);
	return 0;
}