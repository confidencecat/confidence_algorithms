#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#define INF 3000001
using namespace std;

typedef struct ST {
    int x, v;

    ST(int a, int b) {
        x = a;
        v = b;
    }

    bool operator<(const ST& ss)const {
        return ss.v < v;
    }
}ST;

int v, e, s, A, B, C;
priority_queue<ST> q;
vector<ST> vec[20001];
int d[20001];


int main() {

    scanf("%d %d", &v, &e);
    scanf("%d", &s);

    for (int i = 1; i <= v; i++) {
        d[i] = INF;
    }

    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &A, &B, &C);
        vec[A].push_back({ B, C });
    }

    q.push({ s, 0 });
    d[s] = 0;

    while (!q.empty()) {
        int x = q.top().x;
        int v = q.top().v;
        q.pop();

        if (d[x] < v) continue;

        for (ST cq : vec[x]) {
            if (d[cq.x] > d[x] + cq.v) {
                q.push({ cq.x, d[x] + cq.v });
                d[cq.x] = d[x] + cq.v;
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        if (d[i] == INF) printf("INF\n");
        else printf("%d\n", d[i]);
    }
    return 0;
}
