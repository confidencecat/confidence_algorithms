#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, m, sx, sy, t, rld = 1, udd = 1;
	scanf("%d %d %d %d %d", &n, &m, &sx, &sy, &t);
	int x = ((sx + t) / n) % 2 == 0 ? (sx + t) % n : n - ((sx + t) % n);

	int y = ((sy + t) / m) % 2 == 0 ? (sy + t) % m : m - ((sy + t) % m);
	printf("%d %d\n", x, y);
	return 0;
}