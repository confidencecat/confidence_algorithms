#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int a[16][16];

int main() {
    //freopen("input.txt", "rt", stdin);
    
    for (int i = 1; i <= 15; i++) a[1][i] = i;

    for (int i = 2; i <= 15; i++) {
        for (int j = 1; j <= 15; j++) {
            a[i][j] = a[i - 1][j] + a[i][j - 1];
        }
    }

    int t, aa, bb;
     

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &aa, &bb);
        printf("%d\n", a[aa + 1][bb]);
    }

    return 0;
}
