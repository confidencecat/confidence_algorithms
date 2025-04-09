#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(a, b) (a) > (b) ? (b) : (a)

int n, l, h, mx = 0, ans = 0;
int map[1001];
int lmx[1002], rmx[1002];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &l, &h);
        mx = mx < l ? l : mx;
        map[l] = h;
    }

    for (int i = 1; i <= mx; i++) {
        if (lmx[i - 1] < map[i]) lmx[i] = map[i];
        else lmx[i] = lmx[i - 1];
    }
    for (int i = mx; i >= 1; i--) {
        if (rmx[i + 1] < map[i]) rmx[i] = map[i];
        else rmx[i] = rmx[i + 1];
    }
    for (int i = 1; i <= mx; i++) {
        ans += min(lmx[i], rmx[i]);
    }
    printf("%d\n", ans);
    return 0;
}
