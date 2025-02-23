#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int t, l, n, a[22], ans = 0;

int main() {
    scanf("%d %d", &t, &l);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int s = 1, e = l;
    for (int i = 0; i < n; i++) {
        if(a[i] > e) {
            ans += a[i] - e;
            e = a[i];
            s = a[i] - l + 1;
        }
        else if (a[i] < s) {
            ans += s - a[i];
            s = a[i];
            e = a[i] + l - 1;
        }
    }
    printf("%d\n", ans);

    return 0;
}

