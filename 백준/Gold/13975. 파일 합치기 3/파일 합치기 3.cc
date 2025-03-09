#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

int com(const void* A, const void* B) {
    return *(int*)A - *(int*)B;
}

typedef struct Q {
    long long int v;

    Q(long long int a) {
        v = a;
    }
    bool operator<(const Q& W)const {
        return v > W.v;
    }

}QQ;

int t, n;
long long int a, ans = 0;
priority_queue<QQ> q;

int main() {
    for (scanf("%d", &t); t; t--) {
        ans = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a);
            q.push(a);
        }

        while (q.size() > 1) {
            long long int x = q.top().v; q.pop();
            long long int y = q.top().v; q.pop();
            ans += x + y;
            //printf("%d %d -> ans:%d\n", x, y, ans);
            q.push(x + y);
        }
        q.pop();
        printf("%lld\n", ans);
    }

    return 0;
}
