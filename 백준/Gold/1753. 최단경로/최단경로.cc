#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
#define INF 200000000
using namespace std;

struct Q {
    int e, w;

    Q(int a, int b) {
        e = a;
        w = b;
    }

    bool operator<(const Q& q)const {
        return w > q.w;
    }
};

int n, m, st;
int d[20002];

priority_queue<Q> q;
vector<pair<int, int>> v[20002];

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d %d %d", &n, &m, &st);

    for (int i = 1; i <= n; i++) d[i] = INF;

    for (int i = 0; i < m; i++) {
        int ss, ee, vv;
        scanf("%d %d %d", &ss, &ee, &vv);
        v[ss].push_back({ ee, vv });
    }

    d[st] = 0;
    q.push({ st, 0 });

    while (!q.empty()) {
        int x = q.top().e;
        int w = q.top().w;
        q.pop();

        for (auto cx : v[x]) {
            if (w + cx.second < d[cx.first]) {
                d[cx.first] = w + cx.second;
                q.push({ cx.first, w + cx.second });
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (d[i] == INF) printf("INF\n");
        else printf("%d\n", d[i]);
    }

    return 0;
}