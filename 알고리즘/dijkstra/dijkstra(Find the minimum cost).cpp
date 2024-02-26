#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<vector>
#include<queue>
using namespace std;

#define INF 2100000000
vector<pair<int, int>> a[100000];
int main(void) {
    //freopen("input.txt", "r", stdin);

    int n, m, ns, ne, nv, A, B;
    int answer[1001];
    priority_queue<pair<int, int>> q;
    

    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        answer[i] = INF;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &ns, &ne, &nv);
        a[ns].push_back({ ne, nv });
    }
    scanf("%d %d", &A, &B);

    answer[A] = 0;
    q.push({ A, 0 });

    while (!q.empty()) {
        int e = q.top().first;
        int v = -q.top().second;
        q.pop();

        if (answer[e] < v) continue;
        for (auto& p : a[e]) {
            int next = p.first;
            int next_v = p.second + v;

            if (next_v < answer[next]) {
                answer[next] = next_v;
                q.push({ next, -next_v });
            }
        }
    }
    printf("%d\n", answer[B]);
    return 0;
}
//boj.1916
