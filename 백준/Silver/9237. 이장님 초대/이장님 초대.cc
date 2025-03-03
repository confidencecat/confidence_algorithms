#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char rbuf[1 << 20];
int idx, nidx;
inline char read() {
    if (idx == nidx) {
        nidx = fread(rbuf, 1, 1 << 20, stdin);
        if (!nidx) return 0;
        idx = 0;
    }
    return rbuf[idx++];
}

inline int ri() {
    int sum = 0;
    char now = read();

    while (now <= 32) now = read();
    while (now >= 48) sum = sum * 10 + now - '0', now = read();

    return sum;
}

int n, i, a[100001], mx = 0;

int com(const void* A, const void* B) {
    return *(int*)B - *(int*)A;
}

int main() {    
    for (n=ri(), i =0; i < n; i++) a[i] = ri();
    qsort(a, n, sizeof(a[0]), com);

    for (int i = 0; i < n; i++) {
        if ((a[i] - (n - i - 1)) > mx) mx = a[i] - (n - i - 1);
    }
    printf("%d\n", mx + n + 1);
    return 0;
}
