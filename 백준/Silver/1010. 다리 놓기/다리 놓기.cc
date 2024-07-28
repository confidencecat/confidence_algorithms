#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, a[32][32];

int main() {
    //freopen("input.txt", "rt", stdin);
    
    for (int i = 1; i <= 30; i++) a[1][i] = i;

    for (int i = 2; i <= 30; i++) {
        for (int j = i; j <= 30; j++) {
            a[i][j] = a[i - 1][j - 1] + a[i][j - 1];
        }
    }

    /*for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= 30; j++) {
            printf("%8d ", a[i][j]);
        }
        printf("\n");
    }*/

    int t, s, e;
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &s, &e);
        //printf("%d %d\n", s, e);
        printf("%d\n", a[s][e]);
    }
    return 0;
}
