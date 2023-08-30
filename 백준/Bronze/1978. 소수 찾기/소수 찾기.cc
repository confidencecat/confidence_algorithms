#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, a, ans, m;
	scanf("%d", &n);
	ans = n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a == 1) {
			ans--;
		}
		else {
			for (int j = 2; j < a; j++) {
				if (a % j == 0) {
					ans--;
					break;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}