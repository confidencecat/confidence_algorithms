#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, a[51][2], r[51];

int main() {
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i][0], &a[i][1]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][0] < a[j][0] && a[i][1] < a[j][1]) {
				r[i]++;
			}
		}
		printf("%d\n", r[i] + 1);
	}
	return 0;
}