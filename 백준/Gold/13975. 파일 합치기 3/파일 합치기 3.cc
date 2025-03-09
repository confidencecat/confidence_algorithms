#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

typedef struct Q {
    long long int v;

    Q(long long int a) {
        v = a;
    }
    bool operator<(const Q& W)const {
        return v > W.v;
    }

}QQ;

char rbuf[1 << 20];
int idx, nidx;
inline char read() {
    if (idx == nidx) {
        nidx = fread(rbuf, 1, 1 << 20, stdin);
        if (!nidx) return 0;
        idx = 0;
    }
    return rbuf[idx++];
}
inline long long rll() {
    long long sum = 0;
    char now = read();
    while (now <= 32) now = read();
    while (now >= 48) {
        sum = sum * 10LL + (now - '0');
        now = read();
    }
    return sum;
}

inline int ri() {
    int sum = 0;
    char now = read();

    while (now <= 32) now = read();
    while (now >= 48) sum = sum * 10 + now - '0', now = read();

    return sum;
}

int t, n;
long long int a, ans = 0;
priority_queue<QQ> q;

int main() {
    for (t = ri(); t; t--) {
        ans = 0;
        n = ri();
        for (int i = 0; i < n; i++) {
            a = rll();
            q.push(a);
        }

        while (q.size() > 1) {
            long long int x = q.top().v; q.pop();
            long long int y = q.top().v; q.pop();
            ans += x + y;
            q.push(x + y);
        }
        q.pop();
        printf("%lld\n", ans);
    }

    return 0;
}
