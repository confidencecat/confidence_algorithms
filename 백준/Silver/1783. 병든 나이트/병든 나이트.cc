#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define min(a, b) a > b ? b : a

int n, m;//세로 가로

int main() {
	//freopen("input.txt", "rt", stdin);
	scanf("%d %d", &n, &m);
	if (n == 1) printf("1");
	else if (n == 2) printf("%d", min(4, (m - 1) / 2 + 1));
	else {
		if (m >= 7) printf("%d", m - 2);
		else printf("%d", min(4, m));
	}
	return 0;
}