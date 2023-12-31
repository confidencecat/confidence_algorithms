#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int a[10001];

int f(int n) {
    int ans = n;
    while (n) {
        ans += n % 10;
        n /= 10;
    }
    return ans ;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    
    for (int i = 1; i <= 10000; i++) {
        a[f(i)] = 1;
        if (a[i] == 1) continue;
        printf("%d\n", i);
    }
    return 0;
}
