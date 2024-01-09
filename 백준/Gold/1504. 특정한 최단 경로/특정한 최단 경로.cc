#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <queue>
#include <climits>
using namespace std;


void dijkstra(int start, vector<pair<int, int>> graph[], int n, int dist[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist, dist + n + 1, INT_MAX);
    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int current = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        if (dist[current] < distance) continue;

        for (auto edge : graph[current]) {
            int next = edge.first;
            int nextDistance = distance + edge.second;
            if (nextDistance < dist[next]) {
                dist[next] = nextDistance;
                pq.push({ nextDistance, next });
            }
        }
    }
}

vector<pair<int, int>> graph[802];
int dist1[802], dist2[802], dist3[802];

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, m, v1, v2;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }
    scanf("%d %d", &v1, &v2);

    dijkstra(1, graph, n, dist1);
    dijkstra(v1, graph, n, dist2);
    dijkstra(v2, graph, n, dist3);

    int ans = INT_MAX;
    if (v1 != 1 && v2 != n) {
        if (dist1[v1] != INT_MAX && dist2[v2] != INT_MAX && dist3[n] != INT_MAX)
            ans = min(ans, dist1[v1] + dist2[v2] + dist3[n]);
        if (dist1[v2] != INT_MAX && dist3[v1] != INT_MAX && dist2[n] != INT_MAX)
            ans = min(ans, dist1[v2] + dist3[v1] + dist2[n]);
    }
    else if (v1 == 1) {
        ans = (dist2[v2] != INT_MAX && dist3[n] != INT_MAX) ? dist2[v2] + dist3[n] : INT_MAX;
    }
    else if (v2 == n) {
        ans = (dist1[v1] != INT_MAX && dist2[n] != INT_MAX) ? dist1[v1] + dist2[n] : INT_MAX;
    }

    if (ans == INT_MAX) ans = -1;
    printf("%d\n", ans);

    return 0;
}