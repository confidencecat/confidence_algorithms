#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	char s[16];
	scanf("%s", s);
	int ans = 0, n = strlen(s);
	int a[30] = { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };


	for (int i = 0; i < n; i++) {
		ans += a[s[i] - 65];
	}
	printf("%d\n", ans);
	return 0;
}