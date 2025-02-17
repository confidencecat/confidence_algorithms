#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
int a[3001], t[3001], x = 0, ans = 0;
bool tf[3001];

int main() {
	//freopen("input.txt", "rt", stdin);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &t[i]);

	for (int i = 1; i <= n; i++) {
		if (a[i] >= t[i]) tf[i] = true;
	}
	ans = a[n];
	if (t[n] > a[n]) ans += t[n] - a[n];

	for (int i = n - 1; i >= 0; i--) {
		ans += a[i + 1] - a[i];
		if (tf[i]) {
			continue;
		}
		if (t[i] > ans) ans += (t[i] - ans);
	}
	printf("%d\n", ans);
	return 0;
}