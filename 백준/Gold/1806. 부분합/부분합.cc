#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int n, s, a[100002], min_len, r = 1, l = 1;

int main() {
    scanf("%d %d", &n, &s);
    min_len = n + 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];
    }
    while (l <= n && r <= n && l <= r) {
        int sum = a[r] - a[l - 1];
        if (sum < s) r++;
        else {
            if (min_len >= r - l + 1) min_len = r - l + 1;
            l++;
        }
    }
    printf("%d\n", min_len == n + 1 ? 0 : min_len);
    return 0;
}
