#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    //freopen("input.txt", "rt", stdin);
    
    int s, e, p = 0, max = -1;
    for (int i = 0; i < 4; i++) {
        scanf("%d %d", &s, &e);
        p += e - s;
        max = max < p ? p : max;
    }
    printf("%d\n", max);

    return 0;
}
