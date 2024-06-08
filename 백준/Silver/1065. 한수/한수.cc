#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int N, dp[1001], cnt = 0;

bool f(int n) {
    int l = n % 10;
    int r = (n % 100) / 10;
    int mi = r - l;
    n /= 100;
    while (n > 0) {
        int no = n % 10;
        if (no - r != mi) {
            return false;
        }
        r = no;
        n /= 10;
    }
    return true;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d", &N);

    if (N < 10) {
        printf("%d\n", N);
    }
    else {
        cnt = 9;
        for (int i = 10; i <= N; i++) {
            if (f(i)) {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    
    return 0;
}
