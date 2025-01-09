#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    //freopen("input.txt", "rt", stdin);
    
    int n, n1, k, c = 0, m = 0, a[26];
    int cone = 0, t = 0;
    scanf("%d %d", &n1, &k);
    n = n1;
    while (n) {
        if (n % 2 == 1) cone++;
        a[m++] = n % 2;

        n /= 2;
    }

    //for (int i = m - 1; i >= 0; i--) printf("%d ", a[i]);
    //printf("\n%d\n", cone);

    if (cone <= k) {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < m; i++) {
        if (a[i] == 1) {
            if (++c == cone - k + 1) {
                printf("%d\n", (int)pow(2, i) - t);
                break;
            }
            else {
                t = (int)pow(2, i) + t;
            }
        }
    }



    return 0;
}
