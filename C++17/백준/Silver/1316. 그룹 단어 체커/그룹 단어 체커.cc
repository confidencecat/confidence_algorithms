#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


bool f(char s[]) {
    int n = strlen(s);
    bool c[27];
    for (int i = 0; i < 27; i++) {
        c[i] = false;
    }


    for (int i = 0; i < n; i++) {
        if (c[s[i] - 'a'] == true && s[i - 1] != s[i]) return false;
        else c[s[i] - 'a'] = true;
    }
    return true;
}


int main() {
    //freopen("input.txt", "rt", stdin);
    
    int n, ans = 0;
    char s[102];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", &s);

        if (f(s)) ans++;
    }

    printf("%d", ans);

    return 0;
}
