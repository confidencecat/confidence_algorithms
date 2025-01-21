#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INF 922000000000000000

long long int n;
long long int num[7], min3 = INF, min2 = INF, min1 = INF, min = INF;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%lld %lld %lld %lld %lld %lld %lld", &n, &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]);
    
    if (n == 1) {
        int sum = num[0], mx = num[0];
        for (int i = 0; i < 6; i++, mx = mx < num[i] ? num[i] : mx, sum += num[i]);
        printf("%d\n", sum - mx);
        return 0;
    }

    long long int bcde = num[1] + num[2] + num[3] + num[4];
    int x[4] = { 1, 2, 4, 3 };
    int y[4] = { 2, 4, 3, 1 };
    min = min1 = num[0] > num[5] ? num[5] : num[0];
    for (int i = 1; i <= 4; i++) {
        int d = (bcde - num[x[i - 1]] - num[y[i - 1]]);
        min1 = min1 > num[i] ? num[i] : min1;
        min2 = min2 > d ? d : min2;
        min2 = min2 > min + num[i] ? min + num[i] : min2;
        min3 = min3 > d ? d : min3;
    }
    printf("%lld\n", (min3+min) * 4 + min2 * ((n - 1) * 4 + (n - 2) * 4) + min1 * ((n - 2) * (n - 2) + (n - 2) * (n - 1) * 4));
    
    return 0;
}
