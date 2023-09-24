#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdbool.h>
#include <vector>
#include <queue>
using namespace std;

int N;
int ans[100001];
bool visit[100001];
vector<int> graph[100001];

void bfs() {
    queue<int> q;
    visit[1] = true;
    q.push(1);

    while (!q.empty()) {
        int parent = q.front();
        q.pop();

        for (int i = 0; i < graph[parent].size(); i++) {
            int child = graph[parent][i];
            if (!visit[child]) {
                ans[child] = parent;
                visit[child] = true;
                q.push(child);
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    bfs();

    for (int i = 2; i <= N; i++)
        printf("%d\n", ans[i]);

    return 0;
}
