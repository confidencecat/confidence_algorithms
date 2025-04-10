#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int n, ans = 0;
char s1[1002][10], s2[1002][10];
int order[1002], visited[1002];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s1[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", s2[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (strcmp(s2[i], s1[j]) == 0) {
                order[i] = j;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (order[i] > order[j]) {
                ans++;
                break;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
