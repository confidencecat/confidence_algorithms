#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <queue>
using namespace std;

int main() {
    //freopen("input.txt", "rt", stdin);
    
    int n;
    scanf("%d", &n);
    queue<int> q;
    
    printf("1 ");
    for (int i = 2; i <= n; i++) q.push(i);
    for (int i = 0; i < n - 1; i++) {
        int b = q.front();
        q.pop();
        q.push(b);
        printf("%d ", q.front());
        q.pop();
    }
    return 0;
}
