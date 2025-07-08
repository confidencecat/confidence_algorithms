#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct ST {
    int q, r;
} ST;

int n, Q;
int p, q, r;
int k, v;
int d[5001];
vector<ST> a[5001];

int main() {
    scanf("%d %d", &n, &Q);

    for (int i = 1; i <= n; i++) {
        a[i].clear();
    }

    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d %d", &p, &q, &r);
        a[p].push_back({ q, r });
        a[q].push_back({ p, r });
    }

    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &k, &v);

        for (int j = 1; j <= n; j++) {
            d[j] = 0;
        }
        queue<int> qq;
        d[v] = 1000000001;
        qq.push(v);

        while (!qq.empty()) {
            int x = qq.front(); qq.pop();
            for (ST nx : a[x]) {
                int next_node = nx.q;
                int w = nx.r;
                int min_usado = min(d[x], w);
                if (min_usado > d[next_node]) {
                    d[next_node] = min_usado;
                    qq.push(next_node);
                }
            }
        }

        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (j == v) continue;
            if (d[j] >= k) cnt++;
        }

        printf("%d\n", cnt);
    }

    return 0;
}
