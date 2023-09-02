#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    queue<int> a;
    for (int i = 1; i <= n; i++) {
        a.push(i);
    }
    for (int i = 0; i < n - 1; i++) {
        a.pop();
        a.push(a.front());
        a.pop();
    }
    printf("%d\n", a.front());
    return 0;
}
