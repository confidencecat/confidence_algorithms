#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define max(a, b) a > b ? a : b


int main() {
    //freopen("input.txt", "rt", stdin);
    int n, l1 = 0, l2 = 1, s = 1;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        s = l1 + l2;
        if (s >= 15746) s -= 15746;
        l2 = l1;
        l1 = s;
    }
    printf("%d\n", s);
    

    return 0;
}
