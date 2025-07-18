#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#define INF 210000000
using namespace std;

int n, m, k;
int a, b, c;
vector<pair<int, int>> v[1001];
priority_queue<int> d[1001];
priority_queue<pair<int, int>> q;

int main() {

    scanf("%d %d %d", &n, &m, &k);

    for (int i = 1; i <= n; i++) {
        for(int j = 0; j < k; j++) d[i].push(INF);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back({ b, c });
    }

    d[1].pop();
    d[1].push(0);
    q.push({ 0, 1 });

    while (!q.empty()) {
        int x = q.top().second;
        int w = -q.top().first;
        q.pop();

        for (pair<int, int> dc : v[x]) {
            
            int nd = w + dc.second;
            if (d[dc.first].top() > nd) {
                d[dc.first].pop();
                d[dc.first].push(nd);
                q.push({ -nd, dc.first });
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int to = d[i].top();
        printf("%d\n", to == INF ? -1 : to);
    }

    return 0;
}
