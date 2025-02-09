#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n, l, s, ans = 0;
int a[1002];

int com(const void* A, const void* B) {
    int aa = *(int*)A, bb = *(int*)B;
    return (aa > bb) - (aa < bb);
}

int main() {
    //freopen("input.txt", "rt", stdin);

    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(a[0]), com);



    s = a[0];
    ans++;
    for (int i = 1; i < n; i++) {
        if (s + l > a[i]) continue;
        s = a[i];
        ans++;
    }
    printf("%d\n", ans);



    return 0;
}
