#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

int n, a[100001], mxc = 0, mic = 0, mx = 0, mi = 0;
bool mxt = true, mit = true;

int main() {
    
    scanf("%d", &n);

    a[0] = -1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);

        if (a[i] >= a[i - 1]) {
            mxc++;
        }
        else {
            mx = max(mx, mxc);
            mxc = 1;
        }

        if (a[i] <= a[i - 1]) {
            mic++;
        }
        else {
            mi = max(mi, mic);
            mic = 1;
        }


    }
    mx = max(mx, mxc);
    mi = max(mi, mic);

    printf("%d", max(mx, mi));


    return 0;
}
