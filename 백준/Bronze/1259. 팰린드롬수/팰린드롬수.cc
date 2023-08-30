#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, ans;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		ans = 0;
		for (int i = n; i > 0; i /= 10) {
			ans = ans * 10 + (i % 10);
		}
		if (n == ans)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}