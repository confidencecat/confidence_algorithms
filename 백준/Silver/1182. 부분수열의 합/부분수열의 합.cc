#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, s;
int a[30];
int sum;
void f(int x, int fs) {
    int i;
    if (fs + a[x] == s) {
        sum++;
    }
    if (x == n) return;
    f(x + 1, fs);
    f(x + 1, fs + a[x]);

}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d %d", &n, &s);
    int i, j;
    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    f(1, 0);
    printf("%d", sum);
    return 0;
}