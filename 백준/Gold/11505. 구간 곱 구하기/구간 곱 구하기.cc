#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define MOD 1000000007
typedef long long int ll;

ll n, m, k;
ll A, B, C;
ll seg[2097153], st, en, start_index = 1, mul;


int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%lld %lld %lld", &n, &m, &k);
    while (start_index < n) start_index <<= 1;

    for (ll i = 0; i < start_index * 2; i++) seg[i] = 1;

    //printf("%lld\n", start_index);

    for (ll i = start_index; i < start_index + n; i++) {
        scanf("%lld", &seg[i]);
    }

    for (ll i = start_index - 1; i > 0; i--) {
        seg[i] = ((seg[i * 2] % MOD) * (seg[i * 2 + 1] % MOD)) % MOD;
    }

    /*for (int j = 1; j < start_index * 2; j++) {
        printf("%lld ", seg[j]);
    }
    printf("\n");*/

    for (ll i = 0; i < m + k; i++) {
        scanf("%lld %lld %lld", &A, &B, &C);
        //printf(">%lld %lld %lld\n", A, B, C);
        if (A == 1) {
            //printf("1\n");
            st = B + start_index - 1;
            seg[st] = C;
            st >>= 1;
            while (st >= 1) {
                seg[st] = ((seg[st<<1] % MOD) * (seg[st<<1|1] % MOD)) % MOD;
                st >>= 1;
            }
            //printf("e1\n");
        }
        else {
            mul = 1;
            st = B + start_index - 1;
            en = C + start_index - 1;
            //printf("%lld %lld\n", st, en);
            while (st <= en) {
                if (st % 2 == 1) {
                    mul = ((mul % MOD) * (seg[st] % MOD)) % MOD;
                    st++;
                }
                if (en % 2 == 0) {
                    mul = ((mul % MOD) * (seg[en] % MOD)) % MOD;
                    en--;
                }

                st >>= 1;
                en >>= 1;
                //printf("%lld %lld\n", st, en);
            }

            printf("%lld\n", mul);
            /*for (int j = 1; j < start_index * 2; j++) {
                printf("%lld ", seg[j]);
            }
            printf("\n\n");*/
        }
    }


    return 0;
}