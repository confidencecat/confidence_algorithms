#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	//freopen("input.txt", "rt", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m, a[20], dp[10001] = { 0 };
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		scanf("%d", &m);
		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = a[i]; j <= m; j++) {
				dp[j] = dp[j - a[i]] + dp[j];
			}
		}
		printf("%d\n", dp[m]);
	}
	return 0;
}