#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

int t, n, m, a[1001][2];

struct QQ {
    int a, b;
    QQ(int aa, int bb) {
        a = aa;
        b = bb;
    }
    bool operator<(const QQ& qq) const {
        if (b == qq.b) return a > qq.a;
        return b > qq.b;
    }
};

int com(const void* A, const void* B) {
    int* AA = (int*)A;
    int* BB = (int*)B;
    if (AA[0] == BB[0]) return AA[1] - BB[1];
    return AA[0] - BB[0];
}

int main() {
    scanf("%d", &t);
    while (t--) {
        priority_queue<QQ> q;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a[i][0], &a[i][1]);
        }
        qsort(a, m, sizeof(a[0]), com);

        int res = 0;
        int idx = 0;
        for (int book = 1; book <= n; book++) {
            
            while (idx < m && a[idx][0] <= book) {
                q.push(QQ(a[idx][0], a[idx][1]));
                idx++;
            }
           
            while (!q.empty() && q.top().b < book) {
                q.pop();
            }
            if (!q.empty()) {
                q.pop();
                res++;
            }
        }
        printf("%d\n", res);
    }

    return 0;
}
