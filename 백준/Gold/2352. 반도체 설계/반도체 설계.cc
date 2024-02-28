#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int a, l[40001], n, ln = 0;

int lower_bound(int key) {
	int s = 0, e = ln - 1, ans = n - 1;

	while (s <= e) {
		int mid = (s + e) / 2;

		if (l[mid] > key) {
			e = mid - 1;
			ans = mid;
		}
		else if (l[mid] < key) {
			s = mid + 1;
		}
		else {
			ans = mid;
			break;
		}
	}
	return ans;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (i == 0) l[ln++] = a;
		else if (l[ln - 1] < a) l[ln++] = a;
		else {
			int t = lower_bound(a);
			l[t] = a;
		}
	}
	printf("%d\n", ln);
	return 0;
}