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
int dist_1_to_n[802], dist_v1_to_n[802], dist_v2_to_n[802];

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

    dijkstra(1, graph, n, dist_1_to_n);
    dijkstra(v1, graph, n, dist_v1_to_n);
    dijkstra(v2, graph, n, dist_v2_to_n);

    int ans = INT_MAX;
    if (v1 != 1 && v2 != n) {
        if (dist_1_to_n[v1] != INT_MAX && dist_v1_to_n[v2] != INT_MAX && dist_v2_to_n[n] != INT_MAX)
            ans = min(ans, dist_1_to_n[v1] + dist_v1_to_n[v2] + dist_v2_to_n[n]);
        if (dist_1_to_n[v2] != INT_MAX && dist_v2_to_n[v1] != INT_MAX && dist_v1_to_n[n] != INT_MAX)
            ans = min(ans, dist_1_to_n[v2] + dist_v2_to_n[v1] + dist_v1_to_n[n]);
    }
    else if (v1 == 1) {
        if (dist_v1_to_n[v2] != INT_MAX && dist_v2_to_n[n] != INT_MAX) ans = dist_v1_to_n[v2] + dist_v2_to_n[n];
        else ans = INT_MAX;
    }
    else if (v2 == n) {
        if (dist_1_to_n[v1] != INT_MAX && dist_v1_to_n[n] != INT_MAX) ans = dist_1_to_n[v1] + dist_v1_to_n[n];
        else ans = INT_MAX;
    }

    if (ans == INT_MAX) ans = -1;
    printf("%d\n", ans);

    return 0;
}