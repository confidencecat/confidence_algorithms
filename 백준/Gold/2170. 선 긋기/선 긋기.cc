#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

typedef struct ST {
    int s, e;

    ST(int a, int b) {
        s = a;
        e = b;
    }

    bool operator<(const ST& ss)const {
        return ss.s < s;
    }
}ST;

priority_queue<ST> q;
int as, ae, cs, ce;
long long len = 0, ans = 0;

int main() {
    
    int n, s, e;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &s, &e);
        q.push({ s, e });
    }

    as = q.top().s;
    ae = q.top().e;
    len = ae - as;
    q.pop();

    while (!q.empty()) {
        cs = q.top().s;
        ce = q.top().e;
        //printf("%d %d\n", cs, ce);
        q.pop();

        if (cs <= ae && ce > ae) {
            ae = ce;
        }
        else if (cs > ae) {
            ans += len;
            as = cs;
            ae = ce;
        }
        len = ae - as;

    }
    ans += len;
    printf("%lld\n", ans);

    return 0;
}
