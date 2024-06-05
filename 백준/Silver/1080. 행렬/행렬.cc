#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m, ans = 0;
char a[54][54];
char b[54][54];


void f(int x, int y) {
	for (int i = y; i < y + 3; i++) {
		for (int j = x; j < x + 3; j++) {
			a[i][j] = a[i][j] == '1' ? '0' : '1';
		}
	}
}

int main() {
	//freopen("input.txt", "rt", stdin);

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%s", a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", b[i]);
	}
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (a[i][j] != b[i][j]) {
				f(j, i);
				ans++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}