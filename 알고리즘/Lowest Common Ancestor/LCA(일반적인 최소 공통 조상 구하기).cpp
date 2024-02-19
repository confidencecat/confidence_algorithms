#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int n, t;
int parent[50001], deep[50001], visit[50001];
vector<int> tree[50001];

void find_deep(int x) {
    visit[x] = 1;
    queue<int> q;
    q.push(x);
    int level = 1, now_size = 1, cnt = 0;
    while (!q.empty()) {
        int nnode = q.front();
        q.pop();
        for (int next : tree[nnode]) {
            if (visit[next] == 0) {
                visit[next] = 1;
                q.push(next);
                parent[next] = nnode;
                deep[next] = level;
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
    if (deep[a] < deep[b]) {
        int temp = a;
        a = b;
        b = temp;
    }
    while (deep[a] != deep[b]) a = parent[a];
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }
    return a;
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

    find_deep(1);

    scanf("%d", &t);
    while (t--) {
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%d\n", lca(s, e));
    }
    return 0;
}
