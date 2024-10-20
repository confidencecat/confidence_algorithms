#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char s[1002];
		int m;
		scanf("%s", s);
		m = strlen(s);
		printf("%c%c\n", s[0], s[m - 1]);
	}

	return 0;
}