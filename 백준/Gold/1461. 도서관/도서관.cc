#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int com(const void* A, const void* B) {
    return *(int*)A - *(int*)B;
}

int n, m, a[51];
int sr = 0, sl = 0, ans = 0;

int main() {

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; scanf("%d", &a[i++]));
    qsort(a, n, sizeof(int), com);
    //for (int i = 0; i < n; i++) printf("%d ", a[i]);
    for (sr = 0; sr < n && a[sr] < 0; sr++);
    sl = sr - 1;
    //printf("\n%d %d\n", sl, sr);
    
    if ((sl + 1) % m != 0) ans += abs(a[sl - (sl + 1) % m + 1]) * 2;
    if ((n - sr) % m != 0) ans += a[sr + (n - sr) % m - 1] * 2;

    sl -= (sl + 1) % m;
    sr += (n - sr) % m;
    //printf("ans %d\n%d %d\n", ans, sl, sr); 
    
    for (int i = sl - m + 1; i >= 0; i -= m) {
        //printf("%d + %d[%d]\n", ans, abs(a[i]) * 2, i);
        ans += abs(a[i]) * 2;
    }
    for (int i = sr + m - 1; i < n; i += m) {
        //printf("%d + %d[%d]\n", ans, abs(a[i]) * 2, i);
        ans += a[i] * 2;
    }
    ans -= (abs(a[0]) > a[n - 1] ? abs(a[0]) : a[n - 1]);
    printf("%d\n", ans);
    
    return 0;
}
