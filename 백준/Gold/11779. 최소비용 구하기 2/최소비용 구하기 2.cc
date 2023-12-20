#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<vector>
#include<queue>
#define INF 2100000000
using namespace std;

typedef struct {
    int start, value;
}Q;

int n, m, s, e, dist[1001], dist_t[1001];
vector<pair<int, int>> v[1001];
vector<int> dist_r[1001];
queue<Q> q;

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        dist_t[i] = 0;
        dist_r[i].clear();
    }

    for (int i = 0; i < m; i++) {
        int vs, ve, vv;
        scanf("%d %d %d", &vs, &ve, &vv);
        v[vs].push_back({ ve, vv });
    }

    scanf("%d %d", &s, &e);

    q.push({ s, 0 });
    dist[s] = 0;

    while (!q.empty()) {
        int x = q.front().start;
        int value = -q.front().value;
        q.pop();

        if (x < 1 || x > n) continue;
        if (value > dist[x]) continue;

        int xn = v[x].size();
        for (int i = 0; i < xn; i++) {
            int ex = v[x][i].first;
            if (ex < 1 || ex > n) continue;

            int evalue = value + v[x][i].second;
            if (evalue < dist[ex]) {
                dist[ex] = evalue;
                dist_t[ex] = dist_t[x] + 1;

                if (x <= n) dist_r[x].push_back(ex);
                if (ex <= n) {
                    dist_r[ex] = dist_r[x];
                    if (!dist_r[x].empty()) dist_r[x].pop_back(); // dist_r[x]가 비어있지 않은지 검사
                }

                q.push({ ex, -evalue });
            }
        }
    }

    printf("%d\n%d\n%d ", dist[e], dist_t[e] + 1, s);
    for (int i = 0; i < dist_r[e].size(); i++) {
        printf("%d ", dist_r[e][i]);
    }

    return 0;
}
