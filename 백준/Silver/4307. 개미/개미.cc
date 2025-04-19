#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define mx(a, b) ((a) > (b) ? (a) : (b))

int t, l, n, x;
long long int min, max;

int main() {
    for (scanf("%d", &t); t--;) {
        scanf("%d %d", &l, &n);
        min = 0;
        max = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            min = mx(min, (x < l - x ? x : l - x));
            max = mx(max, (x < l - x ? l - x : x));
        }
        printf("%lld %lld\n", min, max);
    }
    
    return 0;
}
