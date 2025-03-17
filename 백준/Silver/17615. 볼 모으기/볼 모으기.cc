#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n, tf = 0, r_cnt = 0, b_cnt = 0, ans = 5000001;
bool rt = false, bt = false;
char s[500001];


int main() {

    scanf("%d", &n);
    scanf("%s", s);

    for (int i = 0; i < n; i++) {
        if (s[i] == 'B' && !rt) rt = true;
        if (s[i] == 'R' && rt) r_cnt++;

        if (s[i] == 'R' && !bt) bt = true;
        if (s[i] == 'B' && bt) b_cnt++;
    }
    ans = ans > r_cnt ? r_cnt : ans;
    ans = ans > b_cnt ? b_cnt : ans;
    rt = bt = false;
    r_cnt = b_cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'B' && !rt) rt = true;
        if (s[i] == 'R' && rt) r_cnt++;

        if (s[i] == 'R' && !bt) bt = true;
        if (s[i] == 'B' && bt) b_cnt++;
    }

    ans = ans > r_cnt ? r_cnt : ans;
    ans = ans > b_cnt ? b_cnt : ans;

    printf("%d\n", ans);
    return 0;
}
