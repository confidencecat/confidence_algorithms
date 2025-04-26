#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, m, ans = 0;
char s[10001][501], c[501];

int com(const void* A, const void* B) {
    return strcmp((char*)A, (char*)B);
}

int isin() {
    int l = 0, r = n - 1, mid, cm;

    while (l <= r) {
        mid = (l + r) / 2;
        cm = strcmp(s[mid], c);
        if (cm == 0) return 1;
        else if (cm < 0) l = mid + 1;
        else r = mid - 1;
    }
    return 0;
}

int main() {

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    qsort(s, n, sizeof(s[0]), com);

    for (int i = 0; i < m; i++) {
        scanf("%s", c);
        ans += isin();
    }
    printf("%d\n", ans);

    return 0;
}
