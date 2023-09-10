#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int map[129][129];
int w = 0, b = 0;

void f(int x, int y, int N) {
	int t = 0;
	for (int i = x; i < x + N; i++) {
		for (int j = y; j < y + N; j++) {
			if (map[i][j]) {
				t++;
			}
		}
	}
	if (!t) w++;
	else if (t == N * N) b++;
	else {
		f(x, y, N / 2);
		f(x, y + N / 2, N / 2);
		f(x + N / 2, y, N / 2);
		f(x + N / 2, y + N / 2, N / 2);
	}
	return;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	f(0, 0, n);
	printf("%d\n", w);
	printf("%d\n", b);
	return 0;
}