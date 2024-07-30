#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int w, h, x, y, t;

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d %d %d %d %d", &w, &h, &x, &y, &t);

    printf("%d %d", (x + t) / w % 2 == 0 ? (x + t) % w : w - (x + t) % w, (y + t) / h % 2 == 0 ? (y + t) % h : h - (y + t) % h);

    return 0;
}
