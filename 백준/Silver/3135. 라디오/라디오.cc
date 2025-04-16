#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(a, b) ((a < b) ? (a) : (b))
#define abs(a, b) ((a < b) ? (b - a) : (a - b))

int s, e, n, a, ans;

int main() {
    scanf("%d %d", &s, &e);
    scanf("%d", &n);
    ans = abs(s, e);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        ans = min(ans, abs(a, e)+1);
    }
    printf("%d\n", ans);

    return 0;
}
