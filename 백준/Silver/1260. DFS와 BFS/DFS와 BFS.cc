#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

int n, m, v, a[1001][10001], dc[1001], bc[1001], nd, li;

void df(int node){
    for (int i = 1; i <= n; i++) {
        //printf("%d %d %d\n", node, i, dc[i]);
        if (a[node][i] == 1 && dc[i] == 0) {
            printf("%d ", i);
            dc[i] = 1;
            df(i);
        }
    }
}

int main(){
    //freopen("input.txt", "rt", stdin);
    queue<int> q;
    scanf("%d %d %d", &n, &m, &v);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &nd, &li);
        a[nd][li] = 1;
        a[li][nd] = 1;
    }
    dc[v] = 1;
    printf("%d ", v);
    df(v);

    bc[v] = 1;
    printf("\n%d ", v);
    q.push(v);
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (a[node][i] == 1 && bc[i] == 0) {
                printf("%d ", i);
                q.push(i);
                bc[i] = 1;
            }
        }
    }
    return 0;
}
