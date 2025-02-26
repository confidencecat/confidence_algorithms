#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define max(a, b) (a) > (b) ? (a) : (b)

int com(const void* A, const void* B) {
    return *(int*)A - *(int*)B;
}

int t, n, a[10001], ans;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(a[0]), com);
        ans = max((a[1] - a[0]), (a[n - 1] - a[n - 2]));
        
        for (int i = 0; i < n - 2; i++) {
            ans = max((a[i + 2] - a[i]), ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}
