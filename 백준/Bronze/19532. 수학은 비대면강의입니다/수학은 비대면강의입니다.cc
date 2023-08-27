#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	//freopen("input.txt", "rt", stdin);
	int a, b, c, d, e, f, x, y;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	y = (c * d - a * f) / (b * d - a * e);
	x = (c * e - b * f) / (a * e - b * d);
	printf("%d %d", x, y);
	return 0;
}