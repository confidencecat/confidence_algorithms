#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, m, in, i, j, k, max, min;
    int** h;

    scanf("%d %d %d", &n, &m, &in);

    h = (int**)malloc(sizeof(int*) * n);
    for (i = 0; i < n; i++) {
        h[i] = (int*)malloc(sizeof(int) * m);
    }

    max = 0, min = 256;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf(" %d", &h[i][j]);
            if (h[i][j] < min) {
                min = h[i][j];
            }
            else if (h[i][j] > max) {
                max = h[i][j];
            }
        }
    }

    int t = 0, mt = INT_MAX, bh = 256;

    for (i = max; i >= min; i--) {
        int b = in;
        t = 0;

        for (j = 0; j < n; j++) {
            for (k = 0; k < m; k++) {
                int d = h[j][k] - i;

                if (d < 0) {
                    t -= d;
                    b += d;
                }
                else if (d > 0) {
                    t += d * 2;
                    b += d;
                }
            }
        }
        if (b >= 0) {
            if (t < mt) {
                mt = t;
                bh = i;
            }
        }
    }

    printf("%d %d\n", mt, bh);

    for (i = 0; i < n; i++) {
        free(h[i]);
    }
    free(h);

    return 0;
}