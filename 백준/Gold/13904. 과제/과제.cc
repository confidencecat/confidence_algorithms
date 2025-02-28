#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int com(const void* A, const void* B) {
    int* aa = (int*)A;
    int* bb = (int*)B;
    if (bb[1] == aa[1]) {
        return aa[0] - bb[0];
    }
    else return bb[1] - aa[1];
}

int n, a[1001][2], ch[1001], ans = 0;

int main() {

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    qsort(a, n, sizeof(a[0]), com);
    for (int i = 0; i < n; i++) {
        for (int j = a[i][0]; j >= 1; j--) {
            //printf("%d ", j);
            if (ch[j] == 0) {
                ans += a[i][1];
                ch[j] = a[i][1];
                break;
            }
        }
        //printf("\n");
        //for (int j = 0; j < n; j++) printf("%d ", ch[j]);
        //printf("\n");
    }
    printf("%d\n", ans);
    return 0;
}
