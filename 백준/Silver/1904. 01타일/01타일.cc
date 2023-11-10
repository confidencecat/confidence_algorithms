#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define max(a, b) a > b ? a : b


int main() {
    //freopen("input.txt", "rt", stdin);
    int n;
    scanf("%d", &n);
    if (n == 1) printf("1\n");
    else if (n == 2) printf("2\n");
    else {
        int l1 = 2, l2 = 1, s;
        for (int i = 2; i < n; i++) {
            s = (l2 + l1) % 15746;
            l2 = l1;
            l1 = s;
        }
        printf("%d\n", s);
    }
    

    return 0;
}
