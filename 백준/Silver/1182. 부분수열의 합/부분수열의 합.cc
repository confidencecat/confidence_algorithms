#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m, a[21], c[21], answer = 0;

void f(int x){
    if (x == n) {
        int ans = 1000001;
        for (int i = 0; i < n; i++) {
            if (c[i] == 1) {
                if (ans == 1000001) {
                    ans = 0;
                }
                ans += a[i];
            }
        }
        if (ans == m && ans != 1000001) {
            answer += 1;
        }
    }
    else {
        c[x] = 0;
        f(x + 1);
        
        c[x] = 1;
        f(x + 1);
    }

}

int main(){
    //freopen("input.txt", "rt", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    f(0);

    printf("%d\n", answer);

    return 0;
}
