#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
    int e, s, m, y = 1;
    scanf("%d %d %d", &e, &s, &m);
    while (1) {
        if ((y - e) % 15 == 0 && (y - s) % 28 == 0 && (y - m) % 19 == 0){
            printf("%d\n", y);
            break;
        }
        else y++;
    }
    return 0;
}
