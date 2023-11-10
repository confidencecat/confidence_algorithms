#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define max(a, b) a > b ? a : b

int ans[1001], a[1001];

int main() {
    //freopen("input.txt", "rt", stdin);
    
    int N, Max = -1;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    ans[0] = a[0];
    Max = ans[0];
    for (int i = 1; i < N; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] < a[i]) ans[i] = max(ans[j] + a[i], ans[i]);
        }
        if (ans[i] == 0) ans[i] = a[i];
        if (ans[i] > Max) Max = ans[i];
    }
    printf("%d", Max);
    return 0;
}
