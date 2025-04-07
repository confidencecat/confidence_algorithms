#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct QQ {
    int n, i, *c;
}Q;

int m, n, a[1001], c[101], dn = 0;
Q d[21];

int com(const void* A, const void* B) {
    Q* AA = (Q*)A;
    Q* BB = (Q*)B;
    if (*(AA->c) == *(BB->c)) return AA->i - BB->i;
    return *(AA->c) - *(BB->c);
}

int com_a(const void* A, const void* B) {
    Q *AA = (Q*)A;
    Q *BB = (Q*)B;
    return AA->n - BB->n;
}

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (c[a[i]] == 0) {
            if (dn == m) {
                c[d[0].n] = 0;
                d[0] = Q{ a[i], i, &c[a[i]] };
            }
            else d[dn++] = Q{ a[i], i, &c[a[i]] };
            c[a[i]] = 1;
        }
        else c[a[i]]++;
        qsort(d, dn, sizeof(d[0]), com);
    }
    qsort(d, dn, sizeof(d[0]), com_a);
    for (int i = 0; i < dn; i++) {
        printf("%d ", d[i].n);
    }

    return 0;
}
