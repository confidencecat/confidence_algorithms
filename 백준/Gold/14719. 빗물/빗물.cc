#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(a, b) ((a) > (b) ? (b) : (a))

int h, w, ans;
int a[501];
int l[501], r[501];

int main() {
    scanf("%d %d", &h, &w);
    for (int i = 0; i < w; i++) {
        scanf("%d", &a[i]);
    }

    l[0] = a[0];
    for (int i = 1; i < w; i++) {
        l[i] = (a[i] > l[i - 1] ? a[i] : l[i - 1]);
    }

    r[w - 1] = a[w - 1];
    for (int i = w - 2; i >= 0; i--) {
        r[i] = (a[i] > r[i + 1] ? a[i] : r[i + 1]);
    }

    for (int i = 0; i < w; i++) {
        ans += min(l[i], r[i]) - a[i];
    }

    printf("%d", ans);
    return 0;
}
