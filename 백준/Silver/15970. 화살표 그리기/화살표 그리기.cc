#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#define min(a, b) a > b ? b : a

int com(const void* first, const void* second) {
    return *(int*)first - *(int*)second;
}

int a, b, c[5001], cn = 0, n;
long long int ans = 0;
int arr[5001][5001];

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        if (b > cn) cn = b;
        arr[b][c[b]++] = a;
    }
    for (int i = 1; i <= cn; i++) {
        qsort(arr[i], c[i], sizeof(int), com);
    }
    for (int i = 1; i <= cn; i++) {
        ans += arr[i][1] - arr[i][0];
        for (int j = 1; j < c[i] - 1; j++) {
            int f = arr[i][j] - arr[i][j - 1];
            int s = arr[i][j + 1] - arr[i][j];
            ans += min(f, s);
        }
        ans += arr[i][c[i] - 1] - arr[i][c[i] - 2];
    }
    printf("%lld\n", ans);
    
    return 0;
}