#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>

long long int sx, sy;

long long int len(long long int ax, long long int ay, long long int bx, long long int by) {
    return (ax - sx) * (by - sy) - (bx - sx) * (ay - sy);
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int n;
    long long int p[10001][2];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &p[i][0], &p[i][1]);
    }
    sx = p[0][0];
    sy = p[0][1];
    double ans = 0;
    for (int i = 1; i < n - 1; i++) {
        long long int i_len = len(p[i][0], p[i][1], p[i + 1][0], p[i + 1][1]);
        ans += i_len / 2.0;
    }
    printf("%0.1lf\n", fabs(ans)); 
    return 0;
}
