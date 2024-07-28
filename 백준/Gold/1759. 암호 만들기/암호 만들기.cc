#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int n, m;
char a[16];
bool ch[16];

int com(const void* first, const void* second) {
    return *(char*)first - *(char*)second;
}

int c(int i) {
    if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') {
        return 1;
    }
    return 0;
}

void dfs(int x, int fn, int on) {

    

    if (fn == n && on >= 1 && n - on >= 2) {
        /*for (int i = 0; i < m; i++) {
            printf("%d ", ch[i]);
        }
        printf("\n");*/
        for (int i = 0; i < m; i++) {
            if (ch[i]) printf("%c", a[i]);

        }
        printf("\n");
    }
    else {
        for (int i = x + 1; i < m; i++) {
            ch[i] = true;

            dfs(i, fn + 1, (on + c(i)));

            ch[i] = false;
        }
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf(" %c", &a[i]);
    }

    qsort(a, m, sizeof(char), com);

    //printf("%s\n", a);

    dfs(-1, 0, 0);

    return 0;
}
