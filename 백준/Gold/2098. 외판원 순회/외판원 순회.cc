#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<memory.h>
#define INF 2100000000

int n, w[16][16];
int ans_bit, dp_bit[16][1 << 16];

// Replacing min macro with inline function for safety
inline int min(int a, int b) {
    return a < b ? a : b;
}

int f(int x, int bit) {
    if (bit == ans_bit) {
        if (w[x][0] == 0) return INF;
        else return w[x][0];
    }

    if (dp_bit[x][bit] != -1) return dp_bit[x][bit];
    dp_bit[x][bit] = INF;

    for (int i = 0; i < n; i++) {
        if (w[x][i] == 0 || (bit & (1 << i)) == (1 << i)) continue;
        dp_bit[x][bit] = min(dp_bit[x][bit], f(i, bit | 1 << i) + w[x][i]);
    }
    return dp_bit[x][bit];
}

int main() {
    //freopen("input.txt", "rt", stdin); 

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &w[i][j]);
        }
    }
    ans_bit = (1 << n) - 1;
    memset(dp_bit, -1, sizeof(dp_bit));

    printf("%d", f(0, 1));

    return 0;
}
