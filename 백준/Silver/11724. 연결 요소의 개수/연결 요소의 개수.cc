#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;


int u, v, n, m, a[1001];
bool ch[1001];

vector<int> vi[1001];

void dfs(int x) {

	ch[x] = true;
	for (int i = 0; i < vi[x].size(); i++){
		int cx = vi[x][i];
		if (ch[cx] == false) {
			dfs(cx);
		}
	}
}

int main() {
	//freopen("input.txt", "rt", stdin);

	scanf("%d %d", &n, &m);


	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		vi[u].push_back(v);
		vi[v].push_back(u);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!ch[i]) {
			dfs(i);
			cnt++;
		}
	}

	printf("%d\n", cnt);
	return 0;
}