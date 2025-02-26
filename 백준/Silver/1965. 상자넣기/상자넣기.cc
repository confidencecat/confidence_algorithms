#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, a[1001], d[1001], ans = 0;

int main() {

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        d[i] = 1;
        if (i == 0) continue;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && d[i] < d[j] + 1) d[i] = d[j] + 1;
        }
        ans = ans < d[i] ? d[i] : ans;
    }

    printf("%d\n", ans);
    return 0;
}
