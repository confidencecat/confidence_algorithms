#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//{ 2, 5, 5, 4, 5, 6, 3, 7, 6, 6 }
//  1  2  3  4  5  6  7  8  9  10

int t, c;
int dp[101] = { 0, 0, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88 };
int p[7] = { 888, 108, 188, 200, 208, 288, 688 };

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &c);
        if (c <= 14) printf("%d", dp[c]);
        else {
            printf("%d", p[c % 7]);
            for (int i = 1; i < (c - 1) / 7 - 1; i++) {
                printf("8");
            }
        }

        printf(" ");

        if (c % 2 == 1) {
            printf("7");
            for (int i = 0; i < (c / 2) - 1; i++) printf("1");
        }
        else for (int i = 0; i < c / 2; i++) printf("1");
        printf("\n");
    }

    return 0;
}
