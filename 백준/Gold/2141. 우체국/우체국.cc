#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct ST {
    int s;
    long long int m;
}ST;

int n;
long long int sm, smt;
ST a[100001];

int com(const void* A, const void* B) {
    ST* AA = (ST*)A;
    ST* BB = (ST*)B;
    return AA->s - BB->s;
}

int main() {
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %lld", &a[i].s, &a[i].m);
        sm += a[i].m;
    }
    sm = (sm+1)/2;
    qsort(a, n, sizeof(a[0]), com);

    for (int i = 0; i < n; i++) {
        smt += a[i].m;
        if (smt >= sm) {
            printf("%d", a[i].s);
            break;
        }
    }
    return 0;
}
