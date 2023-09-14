#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(a, b) a > b ? b : a 
using namespace std;

int a[101][101], n, m, s, e, ans = 5001, ans_i;

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = 10000;
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &s, &e);
        a[s][e] = 1;
        a[e][s] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j) {
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
                }
            }
        }
    }


    for (int i = 1; i <= n; i++) {
        int l = 0;
        for (int j = 1; j <= n; j++) {
            
            if (a[i][j] != 10000) {
                l += a[i][j];
            }
        }
        if (l < ans) {
            ans = l;
            ans_i = i;
        }
    }

    printf("%d\n", ans_i);
    return 0;
}