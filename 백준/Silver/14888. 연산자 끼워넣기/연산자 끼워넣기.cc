#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, a[13];
int cn[4], c[12];
int mx = -1000000000, mi = 1000000000;

void f(int fn) {
    if (fn == n - 1) {
        int num = a[0];
        for (int i = 1; i < n; i++) {
            if (c[i - 1] == 1) num += a[i];
            if (c[i - 1] == 2) num -= a[i];
            if (c[i - 1] == 3) num *= a[i];
            if (c[i - 1] == 4) {
                if (num < 0) num = -(-num / a[i]);
                else num /= a[i];
            }
        }
        if (num > mx) mx = num;
        if (num < mi) mi = num;
    } else {
        for (int i = 0; i < 4; i++) {
            if (cn[i] > 0) {
                c[fn] = i + 1;
                cn[i]--;
                f(fn + 1);
                cn[i]++;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < 4; i++) scanf("%d", &cn[i]);
    
    f(0);

    printf("%d\n%d", mx, mi);
    return 0;
}
