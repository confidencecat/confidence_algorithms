#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int com(const void* first, const void* second) {
	return *(long long int*)first - *(long long int*)second;
}

long long int n, c, ans = 0;
long long int a[200001];

int main() {
	//freopen("input.txt", "rt", stdin);
	

	scanf("%lld %lld", &n, &c);

	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}

	qsort(a, n, sizeof(long long int), com);


	int l = 1, r = a[n - 1] - a[0], mid = 0;

	while (l <= r) {
		mid = (l + r) / 2;

		int cnt = 1 ,s = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] - a[s] >= mid) {
				cnt++;
				s = i;
			}
		}

		if (cnt >= c) {
			l = mid + 1;
			ans = mid;
		}
		else r = mid - 1;

	}

	printf("%lld\n", ans);

	return 0;
}
