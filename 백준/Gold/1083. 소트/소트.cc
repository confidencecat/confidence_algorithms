#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, a[51], s;
int st, en, mx = 0, mxi;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &s);

    while (s && st < n) {
        en = (st + s) > (n - 1) ? (n-1): (st + s);
        mx = 0;
        mxi = st;
        for (int i = st; i <= en; i++) {
            //printf("%d ", i);
            if (mx < a[i]) {
                mxi = i;
                mx = a[i];
            }
        }
        if (mxi != st) {
            s-= (mxi - st);

            int t = a[mxi];
            for (int i = mxi; i > st; i--) {
                a[i] = a[i - 1];
            }
            a[st] = t;
        }
        st++;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
