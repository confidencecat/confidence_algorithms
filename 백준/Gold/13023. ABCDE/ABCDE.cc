#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

int n, m;
bool tf = false;
bool ch[2001];

vector<int> v[2001];

void f(int x, int fn) {
	if (fn == 5) {
		tf = true;
		return;
	}
	else {
		for (auto cx : v[x]) {
			if (ch[cx] == false) {
				ch[cx] = true;
				f(cx, fn + 1);
				ch[cx] = false;
			}
		}
	}
	
}

int main() {
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d %d", &n, &m);


	for (int i = 0; i < m; i++) {
		int aa, bb;
		scanf("%d %d", &aa, &bb);
		v[aa].push_back(bb);
		v[bb].push_back(aa);
	}

	for (int i = 0; i < n; i++) {
		ch[i] = true;
		f(i, 1);
		ch[i] = false;
		if (tf) break;
	}

	if (tf) {
		printf("1");
	}
	else printf("0");

	return 0;
}
