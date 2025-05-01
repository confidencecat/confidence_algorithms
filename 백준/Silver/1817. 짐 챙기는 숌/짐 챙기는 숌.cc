#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int cnt = 0, curr = 0, w;
    for (int i = 0; i < n; i++) {
        scanf("%d", &w);
        if (curr + w > m) {
            cnt++;
            curr = 0;
        }
        curr += w;
    }
    if (curr > 0) cnt++;

    printf("%d\n", cnt);
    return 0;
}

