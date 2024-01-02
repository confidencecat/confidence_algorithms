#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
bool a[4000001];
int p[4000001], pn = 0;

bool sum(int x) {
	int s = 0;
	while (x >= 0 && s < n) {
		s += p[x--];
		if (s == n) return true;
	}
	return false;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int ans = 0;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		if (!a[i]) {
			for (int j = i; j <= n; j += i) {
				if (i != j) {
					a[j] = true;
				}
			}
			p[pn++] = i;
		}
	}

	for (int i = pn - 1; i >= 0; i--) {
		if (sum(i)) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}