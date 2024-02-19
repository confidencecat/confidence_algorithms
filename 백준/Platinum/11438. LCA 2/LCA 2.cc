#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector<int> tree[100001];
int n, m, l = 1, km = 0;
int depth[100001], visited[100001], parent[18][100001];

void bfs(int x) {
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    int level = 1, now_size = 1, cnt = 0;
    while (!q.empty()) {
        int nnode = q.front();
        q.pop();
        for (int next : tree[nnode]) {
            if (visited[next] == 0) {
                visited[next] = 1;
                q.push(next);
                parent[0][next] = nnode;
                depth[next] = depth[nnode] + 1;
            }
        }
        cnt++;
        if (cnt == now_size) {
            cnt = 0;
            now_size = q.size();
            level++;
        }
    }
}

int lca(int a, int b) {
    if (depth[a] > depth[b]) {
        int temp = a;
        a = b;
        b = temp;
    }
    for (int i = km; i >= 0; --i) {
        if (depth[b] - depth[a] >= (1 << i)) {
            b = parent[i][b];
        }
    }

    if (a == b) return a;

    for (int i = km; i >= 0; --i) {
        if (parent[i][a] != parent[i][b]) {
            a = parent[i][a];
            b = parent[i][b];
        }
    }

    return parent[0][a];
}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        tree[s].push_back(e);
        tree[e].push_back(s);
    }
    while (l <= n) {
        l = l << 1;
        km++;
    }

    bfs(1);

    for (int i = 1; i <= km; i++) {
        for (int j = 1; j <= n; j++) {
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
        }
    }

    scanf("%d", &m);
    while (m--) {
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", lca(s, e));
    }


    return 0;
}
