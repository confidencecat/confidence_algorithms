#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 


int t;

bool f(char s[], int n) {
    if (n == 1) return true;

    for (int i = 0; i < n / 2; i++) {
        s[n - i - 1] = s[n - i - 1] == '0' ? '1' : '0';
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }

    return f(s, n / 2);
}

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d", &t);

    while (t--) {
        char s[3002];
        scanf("%s", s);
        int n = strlen(s);

        bool tf = f(s, n);
        printf("%s\n", tf ? "YES" : "NO");
    }


    return 0;
}
