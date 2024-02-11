#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int gcd(int a, int b) {
	if (b) return gcd(b, a % b);
	return a;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int t, n, arr[101];
	long long int ans = 0;
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		scanf("%d", &n);
		scanf("%d", &arr[0]);
		for (int i = 1; i < n; i++) {
			scanf("%d", &arr[i]);
			for (int j = 0; j < i; j++) {
				ans += gcd(arr[i], arr[j]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}