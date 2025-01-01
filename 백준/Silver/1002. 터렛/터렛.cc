#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    //freopen("input.txt", "rt", stdin);
    
    int t;
    scanf("%d", &t);
    while (t--) {
        int x1, y1, r1, x2, y2, r2;
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        if (x1 == x2 && y1 == y2 && r1 == r2) { printf("-1\n"); continue; }
        int len = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2), mir = r1 < r2 ? r1 : r2, mxr = r1+r2-mir;
        if ((mxr - mir) * (mxr - mir) < len && len < (mxr + mir) * (mxr + mir)) printf("2\n");
        else if ((mxr - mir) * (mxr - mir) == len || len == (mxr + mir) * (mxr + mir)) printf("1\n");
        else printf("0\n");
    }

    return 0;
}
