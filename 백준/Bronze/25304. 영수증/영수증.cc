#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
    //freopen("input.txt", "rt", stdin);
    int m, n, am, an, sum = 0;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &am, &an);
        sum += am * an;
    }
    if (m == sum) printf("Yes\n");
    else printf("No\n");
    return 0;
}
