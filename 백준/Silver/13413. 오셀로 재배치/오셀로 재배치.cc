#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int t, n;
char s1[100001], s2[100001];

int main() {
    scanf("%d", &t);
    while (t--) {
        int d = 0, w = 0, W = 0;
        scanf("%d", &n);
        scanf("%s", s1);
        scanf("%s", s2);
        for (int i = 0; i < n; i++) {
            if (s1[i] == 'W') w++;
            if (s2[i] == 'W') W++;
            if (s1[i] != s2[i]) d++;
        }
        int diff = w - W;
        if (diff < 0) diff = -diff;
        if (w == W)
            printf("%d\n", (d + 1) / 2);
        else
            printf("%d\n", (d + diff) / 2);
    }
    return 0;
}
