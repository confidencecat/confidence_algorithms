#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n;
int a, m, ans;

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a >= m) {
            ans++;
        }
        m = a;
    }
    printf("%d\n", ans);
    return 0;
}
