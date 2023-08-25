#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define max(a, b) a > b ? a : b;
int n, m = -1001, a[100001], d[100001];

int main() {
	//freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	d[0] = m = a[0];
	for (int i = 1; i < n; i++) {
		d[i] = max(a[i] + d[i - 1], a[i]);
		m = max(d[i], m);
	}
	printf("%d\n", m);
	return 0;
}