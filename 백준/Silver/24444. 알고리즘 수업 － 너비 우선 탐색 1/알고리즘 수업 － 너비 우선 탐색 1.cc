#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, s, cnt = 1;
int ans[100001];
bool c[100001];
vector<int> v[100001];
queue<int> q;

int main() {
	//freopen("input.txt", "rt", stdin);

	scanf("%d %d %d", &n, &m, &s);

	for (int i = 0; i < m; i++) {
		int ss, ee;
		scanf("%d %d", &ss, &ee);
		v[ss].push_back(ee);
		v[ee].push_back(ss);
	}

	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}

	c[s] = true;

	ans[s] = cnt++;
	q.push(s);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			if (!c[v[x][i]]) {
				q.push(v[x][i]);

				ans[v[x][i]] = cnt++;
				c[v[x][i]] = true;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}