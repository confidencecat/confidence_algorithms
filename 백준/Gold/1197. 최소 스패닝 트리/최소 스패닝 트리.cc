#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

struct Q {
    int s, e, v;

    Q(int a, int b, int c) {
        s = a;
        e = b;
        v = c;
    }

    bool operator<(const Q &q)const {
        return v > q.v;
    }
};

int n, m, u = 0, ans = 0;
int d[10002];
priority_queue<Q> q;

int find(int a) {
    if (d[a] == a) return a;
    else return d[a] = find(d[a]);
}

void uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) d[b] = a;
}

int main() {
    //freopen("input.txt", "rt", stdin);

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) d[i] = i;

    for (int i = 0; i < m; i++) {
        int s, e, v;
        scanf("%d %d %d", &s, &e, &v);
        q.push({ s, e, v });
    }

    while (u < n - 1) {
        int s = q.top().s;
        int e = q.top().e;
        int v = q.top().v;
        q.pop();

        //printf("%d\n", v);

        if (find(s) != find(e)) {
            uni(s, e);
            u++;
            ans += v;
        }
        //if () break;
    }

    printf("%d\n", ans);
    return 0;
}
