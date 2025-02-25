#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int g, n;
int i = 0, mx = 0, s = 0;
int a[100001], r[100001];
bool ch[100001];

int main() {
    scanf("%d", &g);
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= g; i++) r[i] = i;

    for (i = 0; i < n; i++) {
        bool tf = false;
        for (int j = r[a[i]]; j > 0; j--) {
            if (ch[j] == false) {
                ch[j] = true;
                r[a[i]] = j - 1;
                tf = true;
                break;
            }
        }
        if (!tf)break;
    }
    printf("%d\n", i);

    return 0;
}

