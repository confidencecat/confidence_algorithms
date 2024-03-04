#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <queue>
using namespace std;

int ans[1000001];

int main() {
	//freopen("input.txt", "rt", stdin);
	int f, s, g, u, d;
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

	queue<int> q;
	q.push(s);
	ans[s] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == g) break;

		if (x + u <= f) {
			if (ans[x + u] == 0) {
				ans[x + u] = ans[x] + 1;
				q.push(x + u);
			}
			/*else if(ans[x + u] < ans[x] + 1) {
				ans[x + u] = ans[x] + 1;
				q.push(x + u);
			}*/
		}
		if (x - d >= 1) {
			if (ans[x - d] == 0) {
				ans[x - d] = ans[x] + 1;
				q.push(x - d);
			}
			/*else if (ans[x - d] < ans[x] + 1) {
				ans[x - d] = ans[x] + 1;
				q.push(x - d);
			}*/
		}
	}
	/*for (int i = 1; i <= f; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");*/

	if (ans[g] == 0) printf("use the stairs\n");
	else printf("%d\n", ans[g] - 1);
	return 0;
}