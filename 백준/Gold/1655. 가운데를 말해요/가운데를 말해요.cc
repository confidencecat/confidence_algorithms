#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

struct st {
    int a;
    st(int sa) : a(sa) {}
    bool operator<(const st& sst) const {
        return a > sst.a;
    }
};

priority_queue<int> l;
priority_queue<st> r;
int a, s;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (l.empty() || a < l.top()) {
            l.push(a);
            s++;
        }
        else {
            r.push(a);
        }
        if (s > (i / 2) + 1) {
            r.push(l.top());
            l.pop();
            s--;
        }
        else if (s < (i / 2) + 1) {
            l.push(r.top().a);
            r.pop();
            s++;
        }
        printf("%d\n", l.top());
    }
    return 0;
}
