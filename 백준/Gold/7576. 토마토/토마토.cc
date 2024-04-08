#define _CRT_SECURE_NO_WARNINGS 
#include <queue>
#include <stdio.h>

using namespace std;

struct tomato {
    int y, x;
};

queue<tomato> q;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0 , -1 };

int n, m, result = 0;
int graph[1001][1001];

bool IsInside(int ny, int nx) {
    return (0 <= nx && 0 <= ny && nx < m&& ny < n);
}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d %d", &m, &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 1) {
                q.push({ i, j });
            }
        }
    }

    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (IsInside(ny, nx) == 1 && graph[ny][nx] == 0) {
                graph[ny][nx] = graph[y][x] + 1;
                q.push({ ny, nx });
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 0) {
                printf("-1\n");
                return 0;
            }
            if (result < graph[i][j]) {
                result = graph[i][j];
            }
        }
    }
    printf("%d\n", result - 1);
    return 0;
}