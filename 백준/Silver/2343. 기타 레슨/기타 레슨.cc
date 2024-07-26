#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	//freopen("input.txt", "rt", stdin);
	
	int n, m, a[100001];
	long long int l = 0, r = 0;


	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (l < a[i]) l = a[i];
		r += a[i];
	}

	while (l <= r) {
		int mid = (r + l) / 2;

		long long int count = 0, sum = 0;
		
		for (int i = 0; i < n; i++) {
			if (sum + a[i] > mid) {
				sum = 0;
				count++;
			}
			sum += a[i];
		}
		if (sum != 0) count++;

		if (count > m) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	printf("%lld\n", l);
	return 0;
}
