#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

int n, m, s[10001], a, answer[10];
void f(int x) {
    if (x == m) {
        for (int i = 0; i < m; i++) {
            printf("%d ", answer[i]);
        }
        printf("\n");
    }
    else {
        for (int i = 1; i <= 10000; i++) {
            if (s[i] != 0) {
                s[i]--;
                answer[x] = i;
                f(x + 1);
                s[i]++;
            }
        }
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        s[a]++;
    }
    f(0);
    return 0;
}

