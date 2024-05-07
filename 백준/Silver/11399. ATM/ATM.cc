#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int com(const void* first, const void* second) {
    return *(int*)first - *(int*)second;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int a[1001], n, s = 0, ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), com);
    for (int i = 0; i < n; i++) {
        s += a[i];
        ans += s;
    }
    printf("%d\n", ans);
    return 0;
}

