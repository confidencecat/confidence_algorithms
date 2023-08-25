#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define max(a, b) a > b ? a : b;

int n, m = 0, a[1001], d[1001], dl[1001];

int main() {
	//freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		d[i] = 1;
		dl[i] = 1;
	}
	for (int i = 2; i <= n; i++) {

		for (int j = i - 1; j >= 1; j--) {
			if (a[j] < a[i]) {
				if (d[i] < d[j] + 1) d[i] = d[j] + 1;
			}
		}

	}
	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 1; j <= n; j++) {
			if (a[j] < a[i]) {
				if (dl[i] < dl[j] + 1) dl[i] = dl[j] + 1;
			}
		}

	}
	for (int i = 1; i <= n; i++) {

		if (d[i] + dl[i] - 1 > m) {
			m = d[i] + dl[i] - 1;
		}
		if (d[i] > m) {
			m = d[i];
		}
		else if (dl[i] > m) {
			m = dl[i];
		}

	}

	printf("%d\n", m);
	return 0;
}