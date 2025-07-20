#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int n, m, k;
long long int seg[2097153], sum;
long long int A, B, C, st, en;


int main() {
    scanf("%d %d %d", &n, &m, &k);

    int start_index = 1;
    while (start_index < n) {
        start_index <<= 1;
    }



    for (int i = start_index; i < start_index + n; i++) {
        scanf("%lld", &seg[i]);
    }
    for (int i = start_index - 1; i >= 1; i--) {
        seg[i] = seg[i * 2] + seg[i * 2 + 1];
    }

    /*for (int i = 1; i < start_index + n; i++) printf("%d ", seg[i]);
    printf("\n");*/
    
    for (int i = 0; i < m + k; i++) {
        scanf("%lld %lld %lld", &A, &B, &C);
        if (A == 1) {
            B += start_index - 1;
            st = B;
            while (st >= 1) {
                st /= 2;
                seg[st] -= seg[B];
                seg[st] += C;
            }
            seg[B] = C;
            /*for (int i = 1; i < start_index + n; i++) printf("%d ", seg[i]);
            printf("\n");*/
        }
        else {
            /*for (int i = 1; i < start_index + n; i++) printf("%lld ", seg[i]);
            printf("\n");*/
            st = B + start_index - 1;
            en = C + start_index - 1;
            sum = 0;
            while (st <= en) {
                sum += (st % 2 == 1 ? seg[st] : 0) + (en % 2 == 0 ? seg[en] : 0);
                st = (st + 1) / 2;
                en = (en - 1) / 2;
            }
            printf("%lld\n", sum);
        }

    }

    return 0;
}