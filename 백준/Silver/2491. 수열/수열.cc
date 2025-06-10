#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int n, l, c, mxc = 0, mic = 0, mx = 0, mi = 0;

int main() {
    
    scanf("%d", &n);

    l = -1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c);

        if (c >= l) {
            mxc++;
        }
        else {
            mx = max(mx, mxc);
            mxc = 1;
        }

        if (c <= l) {
            mic++;
        }
        else {
            mi = max(mi, mic);
            mic = 1;
        }
        l = c;
    }
    mx = max(mx, mxc);
    mi = max(mi, mic);

    printf("%d", max(mx, mi));


    return 0;
}
