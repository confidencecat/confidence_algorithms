#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define min(a, b) a > b ? b : a

int era[10001], n, m, mi = 100000, sum = 0;

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d %d", &n, &m);
    for (int i = 2; i <= m; i++) {
        if (era[i] == 0) {
            if (i >= n) {
                sum += i;
                mi = min(i, mi);
            }
            for (int j = i + i; j <= m; j += i) {
                era[j] = 1;
            }
        }
    }
    if (mi == 100000) printf("-1");
    else printf("%d\n%d\n", sum, mi);
    return 0;
}
