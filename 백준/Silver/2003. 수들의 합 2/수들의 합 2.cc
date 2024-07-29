#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ll long long int

int n, a[10001], cnt = 0;
ll m, s[10001];


int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%lld %lld", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }


    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (s[j] - s[i - 1] == m) cnt++;
        }
    }

    printf("%d\n", cnt);

    return 0;
}
