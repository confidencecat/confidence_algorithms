#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
void gazurr(int* AC, int n, char* p) {
    int dir = 0, front = 0, rear = n, flag = 0;
    for (int i = 0; p[i]; i++) {
        switch (p[i]) {
        case 'R':
            if (!n) flag = 1;
            dir ^= 1;
            break;
        case 'D':
            flag = 0;
            if (rear <= front) {
                flag = 2;
                goto exit;
            }
            if (dir) rear--;
            else front++;
            break;
        }
    }
exit:
    if (flag == 1)  puts("[]");
    else if (!flag) {
        printf("[");
        if (dir)
            for (int i = rear - 1; i >= front; i--) {
                printf("%d", AC[i]);
                if (i != front) printf(",");
            }
        else
            for (int i = front; i < rear; i++) {
                printf("%d", AC[i]);
                if (i != rear - 1) printf(",");
            }
        printf("]\n");
    }
    else puts("error");
}
int main() {
    //freopen("input.txt", "rt", stdin);
    int tc, n, AC[100000];
    char p[100001];
    scanf("%d%*c", &tc);
    while (tc--) {
        scanf("%s", p);
        scanf("%d%*c%*c", &n);
        if (!n)
            scanf("%*c");
        for (int i = 0; i < n; i++) scanf("%d%*c", &AC[i]);
        gazurr(AC, n, p);
        scanf("%*c");
    }
    return 0;
}