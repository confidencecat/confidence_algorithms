#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

typedef struct DATA {
    int m, s, e;
}dd;


int com(const void* A, const void* B) {
    dd* aa = (dd*)A;
    dd* bb = (dd*)B;
    return aa->s - bb->s;
}


int n, i, ans = 1, cnt = 1;

dd a[100001];

int main() {

    for (scanf("%d", &n), i = 0; i < n; i++) {
        scanf("%d %d %d", &a[i].m, &a[i].s, &a[i].e);
    }
    qsort(a, n, sizeof(a[0]), com);
    
    priority_queue<int, vector<int>, greater<int> > q;
    q.push(a[0].e);


    for (i = 1; i < n; i++) {
        while (!q.empty() && q.top() <= a[i].s) {
            q.pop();
        }
        q.push(a[i].e);
        if ((int)q.size() > ans) ans = q.size();
    }


    printf("%d\n", ans);

    return 0;
}
