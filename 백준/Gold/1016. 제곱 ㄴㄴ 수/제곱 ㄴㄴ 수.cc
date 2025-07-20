#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

long long int mi, mx, st, era[1000001], ans;

int main() {
    //freopen("input.txt", "rt", stdin);

    scanf("%lld %lld", &mi, &mx);

    for (long long int i = 2; i <= (int)(sqrt(mx)); i++) {
        st = mi / (i * i);
        if (mi % (i * i) != 0) st++;
        for (long long int j = st; j <= mx / (i * i); j++) era[j * (i * i) - mi]=1;
    }
    for (long long int i = 0; i <= mx - mi; i++) {
        ans += 1-era[i];
    }
    printf("%lld", ans);

    return 0;
}