#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define min(a, b) a > b ? b : a


int main() {

	int n, a[2501] = { 0 }, ch[2501] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++) {
		int t = a[i];
		ch[i] = ch[i] > ch[i - 1] ? ch[i] : ch[i - 1];
		//printf("(%d %d)\n", t, ch[i]);
		for (int j = i + 1; j < n; j++) {
			t = a[j] - t;
			//printf("%d ", t);
			if (t < 0) break;
			else if (t == 0) {
				ch[j] = (i == 0 ? 0 : ch[i - 1]) + 1;
				//printf("\n%d %d", j, ch[j]);
			}
		}
		//printf("\n");

	}
	printf("%d", n - ch[n - 1]);
	return 0;
}