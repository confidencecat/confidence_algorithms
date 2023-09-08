#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

int n, m, s, e, v[101], a[101][101],x, ans = 0;


int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d %d", &n, &m);
    queue<int> q;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &s, &e);
        a[s][e] = 1;
        a[e][s] = 1;
    }

    v[1] = 1;
    q.push(1);
    while (!q.empty()) {
        x = q.front();
        //printf("%d\n", x);
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (a[x][i] == 1 && v[i] == 0) {
                v[i] = 1;
                q.push(i);
                ans++;
            }
        }
        
    }
    printf("%d\n", ans);
    return 0;
}