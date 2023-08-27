#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define min(a, b) a > b ? b : a

int main() {
	//freopen("input.txt", "rt", stdin);
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	x = min(x, (w - x < 0 ? (w - x) * -1 : w - x));
	y = min(y, (h - y < 0 ? (h - y) * -1 : h - y));
	printf("%d\n", min(x, y));
	return 0;
}