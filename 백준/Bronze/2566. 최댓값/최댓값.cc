#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	//freopen("input.txt", "rt", stdin);
	int a, mx = -1, mi = 1, mj = 1;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			scanf("%d", &a);
			if (mx < a) {
				mx = a;
				mi = i;
				mj = j;
			}
		}
	}
	printf("%d\n", mx);
	printf("%d %d\n", mi, mj);
	return 0;
}