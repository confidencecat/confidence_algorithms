#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <stdlib.h>
using namespace std;

typedef struct ST {
    int s, p;
}ST;

int com(const void* aa, const void* bb) {
    ST* A = (ST*)aa;
    ST* B = (ST*)bb;
    return A->s - B->s;
}

int n, i, d, ans, l, p;
ST a[10001];
priority_queue<int> q;
bool tf = false;

int main() {
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].s, &a[i].p);
    }
    qsort(a, n, sizeof(a[0]), com);
    scanf("%d %d", &l, &p);

    while (p < l) {
        for (; i < n && a[i].s <= p; q.push(a[i++].p));

        if (q.empty()) {
            tf = true;
            break;
        }

        p += q.top();
        q.pop();
        ans++;
    }
    printf("%d", tf ? -1 : ans);

    return 0;
}
