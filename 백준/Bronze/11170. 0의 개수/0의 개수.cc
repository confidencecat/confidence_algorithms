#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
    //freopen("input.txt", "rt", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        int s, e, n = 0;
        scanf("%d %d", &s, &e);
        for (int i = s; i <= e; i++) {
            int c = i;
            while (1) {
                if (c % 10 == 0) n++;
                c /= 10;
                if (c / 10 == 0) break;
            }
        }
        printf("%d\n", n);
    }

    return 0;
}
