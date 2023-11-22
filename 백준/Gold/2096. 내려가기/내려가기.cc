#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define max2(a, b) a > b ? a : b
#define max3(a, b, c) b > a ? b > c ? b : c : a > c ? a : c

#define min2(a, b) a < b ? a : b
#define min3(a, b, c) a < b ? a < c ? a : c : b < c ? b : c

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, a[2][3], ma[2][3], mi[2][3];
    scanf("%d", &n);
    
    scanf("%d%d%d", &a[0][0], &a[0][1], &a[0][2]);

    if (n == 1) {
        printf("%d %d\n", max3(a[0][0], a[0][1], a[0][2]), min3(a[0][0], a[0][1], a[0][2]));
        return 0;
    }
    for (int i = 0; i < 3; i++) {
        ma[0][i] = mi[0][i] = a[0][i];
    }
    for (int i = 1; i < n; i++) {
        scanf("%d%d%d", &a[1][0], &a[1][1], &a[1][2]);

        for (int j = 0; j < 3; j++) {
            ma[1][j] = mi[1][j] = a[1][j];
        }
        
        ma[1][0] += max2(ma[0][0], ma[0][1]);
        ma[1][1] += max3(ma[0][0], ma[0][1], ma[0][2]);
        ma[1][2] += max2(ma[0][1], ma[0][2]);

        mi[1][0] += min2(mi[0][0], mi[0][1]);
        mi[1][1] += min3(mi[0][0], mi[0][1], mi[0][2]);
        mi[1][2] += min2(mi[0][1], mi[0][2]);

        for (int j = 0; j < 3; j++) {
            ma[0][j] = ma[1][j];
            mi[0][j] = mi[1][j];
        }
    }
    printf("%d %d\n", max3(ma[1][0], ma[1][1], ma[1][2]), min3(mi[1][0], mi[1][1], mi[1][2]));
    return 0;
}
