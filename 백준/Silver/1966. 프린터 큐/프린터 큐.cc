#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;

int com(const void *first, const void* second) {
	return *(int*)second- *(int*)first;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	int n;
	int m, k;

	scanf("%d", &n);

	while (n--) {
		int max = 0, a[101], ans = 0;
		queue<pair<int, int>> q;
		scanf("%d %d", &m, &k);
		for (int i = 0; i < m; i++) {
			scanf("%d", &a[i]);
			q.push(make_pair(a[i], i));
			if (a[i] > max) {
				max = a[i];
			}
		}
		qsort(a, m, sizeof(int), com);
		while (!q.empty()) {
			if (q.front().first == a[ans]) {
				ans++;
				if (q.front().second == k) {
					printf("%d\n", ans);
					break;
				}
				q.pop();
			}
			else {
				q.push(make_pair(q.front().first, q.front().second));
				q.pop();
			}
		}
	}

	return 0;
}