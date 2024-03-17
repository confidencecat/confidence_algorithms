#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)

char s[52][16];
bool l[26];
int ans, n, m;

void f(int ln, int x) {
    if (ln == m - 5) {
        int a = 0;
        for (int i = 0; i < n; i++) {
            int k = 1;
            for (int j = 4; s[i][j] != '\0'; j++) {
                if (!l[s[i][j] - 97]) {
                    k = 0;
                    break;
                }
            }
            if (k == 1) a++;
        }
        ans = max(a, ans);
        return;
    }
    for (int i = x; i < 26; i++) {
        if (!l[i]) {
            l[i] = true;
            f(ln + 1, i + 1);
            l[i] = false;
        }
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }

    l[0] = true;
    l[2] = true;
    l[8] = true;
    l[13] = true;
    l[19] = true;

    if (m < 5) {
        printf("0\n");
    }
    else {
        f(0, 0);
        printf("%d\n", ans);
    }
    return 0;
}
