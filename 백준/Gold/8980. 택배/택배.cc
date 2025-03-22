#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int com(const void* A, const void* B) {
    int* AA = (int*)A;
    int* BB = (int*)B;
    if (AA[1] == BB[1]) {
        return AA[0] - BB[0];
    }
    return AA[1] - BB[1];
}

int n, c, m, a[10001][3];
int ch[2001], ans = 0;

int main() {

    scanf("%d %d", &n, &c);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    }
    qsort(a, m, sizeof(a[0]), com);

    for (int i = 0; i < m; i++) {
        int canCarry = a[i][2];
        for (int j = a[i][0]; j < a[i][1]; j++) {
            canCarry = min(canCarry, c - ch[j]);
        }
        for (int j = a[i][0]; j < a[i][1]; j++) {
            ch[j] += canCarry;
        }
        ans += canCarry;
    }
    printf("%d\n", ans);

    return 0;
}
