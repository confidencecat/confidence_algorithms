#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int com(const void* first, const void* second) {
    return *(int*)first - *(int*)second;
}

bool ch[101];
long long int ans = 0;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void f(int x, int fn, int n, int a[]) {
    if (2 == fn) {
        int q = -1, w;
        for (int i = 0; i < n; i++) {
            if (ch[i]) {
                if (q == -1) q = a[i];
                else w = a[i];
                
            }
            //printf("%d ", ch[i]);
        }
        //printf("\n");
        ans += gcd(q, w);
    }
    else if(x < n) {
        ch[x] = true;
        f(x + 1, fn + 1, n, a);
        ch[x] = false;
        f(x + 1, fn, n, a);
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, a[101];
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        qsort(a, n, sizeof(int), com);
        ans = 0;
        f(0, 0, n, a);
        printf("%lld\n", ans);
        
    }

    return 0;
}
