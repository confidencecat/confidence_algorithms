#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    int t;
    scanf("%d", &t);
    if (t % 10 != 0) printf("-1");
    else {
        printf("%d %d %d", t / 300, (t % 300) / 60, ((t % 300) % 60) / 10);
    }


    return 0;
}
