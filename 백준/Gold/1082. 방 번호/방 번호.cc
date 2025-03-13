#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct DATA {
    int num, price;
}dd;

int com(const void* A, const void* B) {
    dd* AA = (dd*)A;
    dd* BB = (dd*)B;
    if (BB->price == AA->price) return BB->num - AA->num;
    return AA->price - BB->price;
}

int n, m;
int pri[10], ans[52];
dd a[10];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].price);
        pri[i] = a[i].price;
        a[i].num = i;
    }
    scanf("%d", &m);
    qsort(a, n, sizeof(a[0]), com);

    if (n == 1) {
        printf("0");
        return 0;
    }

    //for (int i = 0; i < n; i++) printf("%d %d\n", a[i].num, a[i].price);
    int maxlen = 0, re = 0;
    if (a[0].num == 0) {
        maxlen = ((m - a[1].price) < 0 ? 0 : (m - a[1].price)) / a[0].price + 1;
        re = ((m - a[1].price) < 0 ? 0 : ((m - a[1].price) % a[0].price));
        if (m - a[1].price >= 0) ans[0] = a[1].num;
        else ans[0] = 0;
        for (int i = 1; i < maxlen; i++) ans[i] = a[0].num;
    }
    else {
        maxlen = m / a[0].price;
        re = m % a[0].price;
        for (int i = 0; i < maxlen; i++) ans[i] = a[0].num;
    }
    
    /*printf("%d\n", maxlen);
    for (int i = 0; i < maxlen; i++) {
        printf("%d", ans[i]);
    }
    printf("\nre: %d\n", re);*/

    for (int i = 0; i < maxlen; i++) {
        for (int j = n-1; j >= (i == 0 ? 1 : 0); j--) {
            if (pri[ans[i]] + re >= pri[j]) {
                //printf("%d + %d >= %d\n", pri[ans[i]], re, pri[j]);
                re -= (pri[j] - pri[ans[i]]);
                ans[i] = j;
                //printf("ch : %d  re : %d\n\n", j, re);
                break;
            }
        }
    }
    for (int i = 0; i < maxlen; i++) {
        printf("%d", ans[i]);
    }

    return 0;
}
