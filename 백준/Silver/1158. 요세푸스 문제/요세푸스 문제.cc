#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<queue>
using namespace std;

int main() {
    int n, k, x = 0;
    scanf("%d %d", &n, &k);
    queue<int> a;
    for (int i = 1; i <= n; i++) {
        a.push(i);
    }
    printf("<");
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k - 1; j++) {
            a.push(a.front());
            a.pop();
        }
        if (i == n) {
            printf("%d>", a.front());
        }
        else {
            printf("%d, ", a.front());
        }
        a.pop();
    }

    return 0;
}