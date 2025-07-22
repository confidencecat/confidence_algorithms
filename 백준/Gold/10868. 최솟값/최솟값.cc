#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INF 1000000001
#define min(a, b) ((a) < (b) ? (a) : (b))

int n, m, start_index = 1;
int a[262144];
int A, B, st, en, ans;


int main() {
    
    scanf("%d %d", &n, &m);

    while (start_index < n) start_index <<= 1;

    for (int i = 0; i < start_index * 2; i++) a[i] = INF;

    for (int i = start_index; i < start_index + n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = start_index - 1; i > 0; i--) {
        a[i] = min(a[i * 2], a[i * 2 + 1]);
    }

    //for (int i = 1; i < start_index * 2; i++) printf("%d ", a[i] == INF ? -1 : a[i]);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &A, &B);
        st = A + start_index - 1;
        en = B + start_index - 1;
        
        ans = INF;

        while (st <= en) {
            if (st % 2 == 1) {
                ans = min(ans, a[st]);
                st++;
            }
            if (en % 2 == 0) {
                ans = min(ans, a[en]);
                en--;
            }
            st >>= 1;
            en >>= 1;
        }
        printf("%d\n", ans);
    }

    return 0;
}
