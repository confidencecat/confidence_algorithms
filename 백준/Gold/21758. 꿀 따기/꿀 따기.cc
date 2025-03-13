#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int n, a[100001], sum[100001];
int mx = 0;

int main() {

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum[i] = (i == 0 ? 0 : sum[i - 1]) + a[i];
    }
    //printf("=========1========\n");
    for (int i = 1; i < n - 1; i++) {
        int p = (sum[n - 1] - a[0] - a[i]) + (sum[n - 1] - sum[i]);
        //printf("%d : %d\n", i, p);
        mx = max(mx, p);
    }
    //printf("=========2========\n");
    for (int i = n - 2; i >= 1; i--) {
        int p = (sum[n - 2] - a[i]) + (sum[i - 1]);
        //printf("%d : %d\n", i, p);
        mx = max(mx, p);
    }
    //printf("=========3========\n");
    for (int i = 1; i < n - 1; i++) {
        int p = sum[n - 1] - a[0] - a[n - 1] + a[i];
        //printf("%d : %d\n", i, p);
        mx = max(mx, p);
    }
    printf("%d\n", mx);

    return 0;
}
