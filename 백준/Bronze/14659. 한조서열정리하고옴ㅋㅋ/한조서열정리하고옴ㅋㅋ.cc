#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, a[30001], s = 0, cnt = 0, ans = 0;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    s = a[0];
    for (int i = 1; i < n; i++) {
        if (s < a[i]) {
            s = a[i];
            cnt = 0;
        }
        else {
            cnt++;
            if (cnt > ans) ans = cnt;
        }
    }
    printf("%d\n", ans);
    return 0;
}
