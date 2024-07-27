#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main() {
    //freopen("input.txt", "rt", stdin);
    
    char s[51];
    int num = 0, m_num = 0, n, ans = 0, am = 1;

    scanf("%s", s);
    n = strlen(s);

    for (int i = 0; i < n; i++) {
        if (s[i] == '-') {
            if (am == -1) ans -= num;
            else ans += num;
            am = -1;
            num = 0;
            //printf("%d\n", ans);
        }
        else if (s[i] == '+') {
            if (am == -1) ans -= num;
            else {
                ans += num;
                am = 1;
            }
            num = 0;
            //printf("%d\n", ans);
        }
        else {
            num = num * 10 + s[i] - '0';
        }
        
    }
    ans += am * num;
    printf("%d\n", ans);

    return 0;
}
