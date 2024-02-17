#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int a[100001], n, mx = 0;
int era[1000001], num[1000001];

int main() {
	//freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		num[a[i]] = 1;
		if (a[i] > mx) mx = a[i];
	}

	for (int i = 1; i <= mx; i++) {
		if (num[i] == 1) {
			for (int j = i + i; j <= mx; j+=i) {
				if (num[j] == 1) {
					era[j]--;
					era[i]++;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", era[a[i]]);
	}
	return 0;
}