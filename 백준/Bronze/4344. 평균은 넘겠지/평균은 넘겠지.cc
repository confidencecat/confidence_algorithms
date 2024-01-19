#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    //freopen("input.txt", "rt", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, a[1001];
        double lf = 0, ans = 0;
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            lf += a[i];
        }
        lf /= n;
        for (int i = 0; i < n; i++) {
            if (a[i] > lf) ans++;
        }
        printf("%.3lf%%\n", ans / n * 100);
    }
    return 0;
}
