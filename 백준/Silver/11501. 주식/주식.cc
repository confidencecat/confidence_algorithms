#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int t, n;
long long int a[1000001], tn = 0;
long long int ans = 0, sum = 0;


int main() {
    
    for (scanf("%d", &t); t--;) {
        scanf("%d", &n);
        ans = 0, sum = 0, tn = 0;

        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        tn = n - 1;
        while(tn > 1) {
            int j = tn - 1;
            for (; j >= 0; j--) {
                if (a[j] < a[tn]) {
                    ans += a[tn] - a[j];
                }
                else break;
            }
            tn = j;
        }

        printf("%lld\n", ans);
    }

    return 0;
}
