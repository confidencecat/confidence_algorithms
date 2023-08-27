#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, m, a[101], ans = 0;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (a[i] + a[j] + a[k] <= m && a[i] + a[j] + a[k] > ans) {
					ans = a[i] + a[j] + a[k];
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}