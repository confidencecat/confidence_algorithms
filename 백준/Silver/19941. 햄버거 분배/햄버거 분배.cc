#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, k, ans = 0;
int ch[20002];
char s[20002];

int main() {
    //freopen("input.txt", "rt", stdin);
    

    scanf("%d %d", &n, &k);
    scanf("%s", s);

    for (int i = 0; i < n; i++) {
        if (s[i] == 'P') {
            int st = (i - k) < 0 ? 0 : (i - k);
            int e = (i + k) >= n ? n - 1 : (i + k);
            for (int j = st; j <= e; j++) {
                if (s[j] == 'H' && ch[j] == 0) {
                    ans++;
                    ch[j] = 1;
                    break;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

