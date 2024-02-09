#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <vector>
using namespace std;

int sn, en, v, e;
bool visit[6], tf = false;
vector<int> map[6];

void f(int x) {
	if (x == en) {
		tf = true;
	}
	else {
		for (int i = 0; i < map[x].size(); i++) {
			int nx = map[x][i];
			if (visit[nx] == true) continue;
			visit[nx] = true;
			f(nx);
			visit[nx] = false;
		}
	}
}

int main() {
	scanf("%d %d", &v, &e);

	for (int i = 0; i < e; i++) {
		int q, w;
		scanf("%d %d", &q, &w);
		map[q].push_back(w);
	}
	scanf("%d %d", &sn, &en);
	visit[sn] = true;
	f(sn);
	if (tf) printf("Yes\n");
	else printf("No\n");
	return 0;
}
