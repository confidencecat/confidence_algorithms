#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int num[10] = { 4, 2, 3, 3, 3, 3, 3, 3, 3, 3 };
int n;

int sum(int x) {
    int ans = 1;
    while (x > 0) {
        ans += num[x % 10];
        x /= 10;
        ans++;
    }
    return ans;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        printf("%d\n", sum(n));
    }

    return 0;
}

