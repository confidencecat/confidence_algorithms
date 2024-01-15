#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int m = 0;
int recursion(const char* s, int l, int r) {
    m++;
    if (l >= r) {
        return 1;
    }
    else if (s[l] != s[r]) {
        return 0;
    }
    else {
        return recursion(s, l + 1, r - 1);
    }
}

int isPalindrome(const char* s) {
    printf("%d ", recursion(s, 0, strlen(s) - 1));
    int ans = m;
    m = 0;
    return ans;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int n;
    scanf("%d", &n);
    while(n--) {
        char s[1001];
        scanf("%s", s);
        printf("%d\n", isPalindrome(s));
    }
    return 0;
}