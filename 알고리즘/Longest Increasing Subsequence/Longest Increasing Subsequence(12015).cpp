#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int n, a, ln = 0, l[1000001];

int lower_bound(int key) {
	int start = 0, end = ln - 1;
	int ans = ln - 1;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (l[mid] > key) {
			end = mid - 1;
			ans = mid;
		}
		else if (l[mid] < key) {
			start = mid + 1;
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

		if (ln == 0) l[ln++] = a;
		else if (l[ln - 1] < a) l[ln++] = a;
		else {
			int pos = lower_bound(a);
			l[pos] = a;
		}
	}
	//for (int i = 0; i < ln; i++) printf("%d ", l[i]);
	printf("%d\n", ln);
	return 0;
}
