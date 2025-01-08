#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int t;

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d", &t);
    
    while (t--) {
        long long int x, y;
        scanf("%lld %lld", &x, &y);
        y -= x;
        //printf("%d\n", y);
        if (y == 1) { printf("1\n"); continue; }
        if (y == 2) { printf("2\n"); continue; }
        long long int k = (int)ceil(((sqrt(1 + 4 * y)) + 1) / 2);
        //printf("%d === %d ===\n", y, k);
        if (y <= (k - 1) * (k - 2) + (k - 1)) printf("%lld\n", (k - 1) * 2 - 1);
        else printf("%lld\n", (k - 1) * 2);
    }

    return 0;
}
