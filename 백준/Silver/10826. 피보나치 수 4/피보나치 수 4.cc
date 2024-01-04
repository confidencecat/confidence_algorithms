#include <stdio.h>

typedef long long ll;

ll arr[2][120];

int main() {
    int n;
    ll *a1, *a2, *tmp;
    a1 = arr[0];
    a2 = arr[1];
    a1[0] = 0;
    a2[0] = 1;

    scanf("%d", &n);

    ll p = 1000000000000000000LL;
    for (int i = 0; i < n; i++) {
        ll carry = 0;
        for (int j = 0; (j < 120) && (a1[j] + carry != 0); j++) {
            a2[j] += a1[j] + carry;
            carry = a2[j] / p;
            a2[j] %= p;
        }

        tmp = a1;
        a1 = a2;
        a2 = tmp;
    }

    int flag = 0;
    for (int i = 119; i >= 0; i--) {
        if (flag == 0 && a1[i] == 0) {
            if (i == 0) {
                printf("0");
            }
            else {
                continue;
            }
        }
        else if (flag == 0) {
            flag = 1;
            printf("%lld", a1[i]);
        }
        else {
            printf("%018lld", a1[i]);
        }
    }
    printf("\n");

    return 0;
}
