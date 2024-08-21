#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int com(const void* first, const void* second) {
    return *(int*)first - *(int*)second;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int sum = 0, a[10];
    int ni, nj;
    bool tf = false;

    for (int i = 0; i < 9; i++) {
        scanf("%d", &a[i]);

        sum += a[i];
    }

    qsort(a, 9, sizeof(int), com);

    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - a[i] - a[j] == 100) {
                ni = i;
                nj = j;
                tf = true;
                break;
            }
        }
        if (tf) break;
    }
    for (int i = 0; i < 9; i++) {
        if (i != ni && i != nj) {
            printf("%d\n", a[i]);
        }
    }

    return 0;
}
