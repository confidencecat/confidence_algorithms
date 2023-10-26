#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<queue>
using namespace std;

int c[100001];

int main() {
    //freopen("input.txt", "rt", stdin);
    int s, e, answer = 0;
    scanf("%d %d", &s, &e);
    queue<int> q;
    q.push(s);
    c[s] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == e) break;
        if (x * 2 <= 100000 && c[x * 2] == 0) {
            q.push(x * 2);
            c[x * 2] = c[x];
        }
        if (x - 1 >= 0 && c[x - 1] == 0) {
            q.push(x - 1);
            c[x - 1] = c[x] + 1;
        }
        if (x + 1 <= 100000 && c[x + 1] == 0) {
            q.push(x + 1);
            c[x + 1] = c[x] + 1;
        }

    }
    printf("%d", c[e] - 1);
    return 0;
}
