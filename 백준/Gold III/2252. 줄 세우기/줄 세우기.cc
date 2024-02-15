#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int a[32002];

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, m;
	vector<int> v[32002];
	queue<int> q;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		v[s].push_back(e);
		a[e]++;
	}

	for (int i = 1; i <= n; i++) {
		if(a[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < v[x].size(); i++) {
			a[v[x][i]]--;
			if (a[v[x][i]] == 0) q.push(v[x][i]);
		}
	}
	return 0;
}