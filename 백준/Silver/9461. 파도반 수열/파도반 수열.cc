#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int t, n;
long long int a[101] = {0, 1, 1, 1, };

int main() {
    //freopen("input.txt", "rt", stdin);
    
    for (int i = 4; i <= 100; i++) {
        a[i] = a[i - 2] + a[i - 3];
    }

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%lld\n", a[n]);
    }

    return 0;
}
