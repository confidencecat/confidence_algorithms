#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int com(const void* A, const void* B) {
    return ((int*)A)[0] - ((int*)B)[0];
}

int main() {
    //freopen("input.txt", "r", stdin);

    int t;
    for (scanf("%d", &t); t-- > 0;) {
        int n, a[100000][2], ans = 1;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d %d", &a[i][0], &a[i][1]);
        qsort(a, n, sizeof(a[0]), com);


        int i = 0, j = 1;
        for(int j = 1; j < n; j++) {
            if (a[i][1] > a[j][1]) {
                ans++;
                i = j;
            }
        }

        printf("%d\n", ans);
    }


    return 0;
}
