#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef long long int ll;

ll l, n, k, r = 0;
ll a[300001], b[300001];

int com(const void* A, const void* B) {
	return *(ll*)A - *(ll*)B;
}

int main() {
	//freopen("input.txt", "rt", stdin);

	scanf("%lld %lld %lld", &l, &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		if (i == 0) b[i] = a[0];
		else b[i] = a[i] - a[i - 1] - 1;
	}
	b[n] = l - a[n - 1];

	if (n >= k) {
		for (int i = 0; i < k; i++) printf("0\n");
		return 0;
	}

	for (int i = 0; i < n; i++) printf("0\n");
	k -= n;

	int d = 1;
	bool tf = true;
	while (tf) {
		for (int i = 0; i <= n; i++) {
			if ((i == 0 || i == n) && b[i] > 0) {
				b[i]--;
				printf("%d\n", d);

				if (!(--k)) tf = false;
			}
			else {
				if (b[i] == 1) {
					b[i]--;
					printf("%d\n", d);

					if (!(--k)) tf = false;
				}
				else if (b[i] >= 2) {
					b[i]--;
					printf("%d\n", d);

					if (!(--k)) {
						tf = false;
						break;
					}

					b[i]--;
					printf("%d\n", d);

					if (!(--k)) tf = false;
				}
			}
			if (!tf) break;
		}

		d++;
	}

	return 0;
}