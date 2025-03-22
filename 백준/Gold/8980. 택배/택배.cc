#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int com(const void* A, const void* B) {
    int* AA = (int*)A;
    int* BB = (int*)B;
    if (AA[1] == BB[1]) {
        if (AA[0] == BB[0]) return BB[2] - AA[2];
        else return AA[0] - BB[0];
    }
    return AA[1] - BB[1];
}

int n, c, m, a[2001][3];
int ch[2001], ans = 0;

int main() {

    scanf("%d %d", &n, &c);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
        a[i][2] = min(a[i][2], c);
    }
    qsort(a, m, sizeof(a[0]), com);

    for (int i = 0; i < m; i++) {
        int mx = 0;
        for (int j = a[i][0]; j < a[i][1]; j++) {
            mx = max(mx, ch[j]);
        }
        for (int j = a[i][0]; j < a[i][1]; j++) {
            ch[j] += min(a[i][2], c - mx);
        }
        ans += min(a[i][2], c - mx);
    }
    printf("%d\n", ans);

    return 0;
}
