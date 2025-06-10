#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int n, l, c, ans, mxc, mic;

int main() {
    scanf("%d", &n);

    l = -1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c);

        mxc = c >= l ? mxc + 1 : 1;
        mic = c <= l ? mic + 1 : 1;
        ans = max(max(mxc, mic), ans);
        
        l = c;
    }

    printf("%d", ans);


    return 0;
}
