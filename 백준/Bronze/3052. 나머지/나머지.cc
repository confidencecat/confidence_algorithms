#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ans= 0, cnt[11];
bool a[43];

int main() {
    
    for (int i = 0; i < 10; i++) {
        scanf("%d", &cnt[i]);
        if (a[cnt[i] % 42] == false) {
            a[cnt[i] % 42] = true;
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
