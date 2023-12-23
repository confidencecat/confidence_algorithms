#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int a[1000001], b[1000001];

int main() {
    //freopen("input.txt", "rt", stdin); 
    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) scanf("%d ", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d ", &b[i]);

    int i = 0, j = 0;
    while (i + j < m + n) {
        if (i == n) {
            printf("%d ", b[j++]);
        }
        else if (j == m) {
            printf("%d ", a[i++]);
        }
        else if (a[i] < b[j]) {
            printf("%d ", a[i++]);
        }
        else if (a[i] >= b[j]) {
            printf("%d ", b[j++]);
        }
    }
    return 0;
}
