#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) > (b) ? (a) : (b)


typedef struct DATA {
    int s, e;
}dd;

int n, m, t, bn = 0;
dd a[200001], b[200001];

int ans[200001];

int main() {
    scanf("%d %d %d", &n, &m, &t);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i].s, &a[i].e);
    }
    for (int i = 0; i < m; i++) {
        int fa, fb;
        scanf("%d %d", &fa, &fb);
        if (a[fa].e <= a[fb].s || a[fb].e <= a[fa].s) continue;
        ans[max(a[fa].s, a[fb].s)]++;
        ans[min(a[fa].e, a[fb].e)]--;
    }
    printf("%d\n", ans[0]);
    for (int i = 1; i < t; i++) {
        ans[i] += ans[i - 1];
        printf("%d\n", ans[i]);
    }
    return 0;
}
