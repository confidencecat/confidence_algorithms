#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m, a, s, e;
long long int d[100001];

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        d[i] = d[i - 1] + a;
    }

    while (m--) {
        int s, e;
        scanf("%d %d", &s, &e);
        printf("%lld\n", d[e] - d[s - 1]);
    }

    return 0;
}
