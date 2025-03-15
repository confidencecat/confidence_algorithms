#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int com(const void* A, const void* B) {
    int* AA = (int*)A;
    int* BB = (int*)B;
    return AA[0] - BB[0];
}

int n, l, a[10001][2];

int main() {
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
        a[i][1]--;
    }
    qsort(a, n, sizeof(a[0]), com);

    int ans = 0, s = 0, e;
    for (int i = 0; i < n; i++) {
        //printf("%d %d\n", a[i][0], a[i][1]);
        e = a[i][1];
        if (s > e) {
            continue;
        }
        s = s > a[i][0] ? s : a[i][0];

        int len = e - s + 1;

        int t = (len / l) + (len % l == 0 ? 0 : 1);
        ans += t;
        s += t * l;

        //printf("%d %d\n", s, e);
    }
    printf("%d\n", ans);
    return 0;
}
