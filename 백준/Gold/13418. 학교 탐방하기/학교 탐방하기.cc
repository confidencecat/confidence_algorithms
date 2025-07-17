#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

typedef struct ST {
    int a, b, c;
    ST(int aa, int bb, int cc) {
        a = aa;  b = bb;  c = cc;
    }
    bool operator<(const ST& ss) const {
        return c < ss.c; 
    }
} ST;

typedef struct ST1 {
    int a, b, c;
    ST1(int aa, int bb, int cc) {
        a = aa;  b = bb;  c = cc;
    }
    bool operator<(const ST1& ss) const {
        return c > ss.c; 
    }
} ST1;

int n, m, A, B, C;
int mx = 0, mi = 0, use = 0;
int d[1001];
int a0c;
priority_queue<ST>    q;
priority_queue<ST1>  qq;

int find(int x) {
    return d[x] == x ? x : (d[x] = find(d[x]));
}
void uni(int a, int b) {
    a = find(a);  b = find(b);
    if (a != b) d[b] = a;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i <= m; i++) {
        scanf("%d %d %d", &A, &B, &C);
       
        int cost = (C == 0 ? 1 : 0);

        if (A == 0 && B == 1) {
            a0c = cost;
        }
        else {
            q.push(ST(A, B, cost));
            qq.push(ST1(A, B, cost));
        }
    }

    for (int i = 0; i <= n; i++) d[i] = i;
    uni(0, 1);
    mx += a0c;
    use = 0;
    while (use < n - 1) {
        ST t = q.top();  q.pop();
        if (find(t.a) != find(t.b)) {
            uni(t.a, t.b);
            mx += t.c;
            use++;
        }
    }

    for (int i = 0; i <= n; i++) d[i] = i;
    uni(0, 1);
    mi += a0c;
    use = 0;
    while (use < n - 1) {
        ST1 t = qq.top();  qq.pop();
        if (find(t.a) != find(t.b)) {
            uni(t.a, t.b);
            mi += t.c;
            use++;
        }
    }

    printf("%d\n", mx * mx - mi * mi);
    return 0;
}
