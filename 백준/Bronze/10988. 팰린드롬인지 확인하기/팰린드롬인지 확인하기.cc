#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	char s[102];

	scanf("%s", s);

	int n = strlen(s);

	for (int i = 0; i < n / 2; i++) {
		if (s[i] != s[n - 1 - i]) {
			printf("0\n");
			return 0;
		}
	}
	printf("1\n");
	return 0;
}