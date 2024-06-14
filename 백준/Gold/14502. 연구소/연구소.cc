#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;


int n, m, fsafe_zone = 0, ans = 0;
int fmap[9][9];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };
vector<pair<int, int>> v;
vector<pair<int, int>> qv;


int bfs(int vx1, int vx2, int vx3) {
    int map[9][9], safe_zone = fsafe_zone - 3;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            map[i][j] = fmap[i][j];
        }
    }

    queue<pair<int, int>> q;
    for (auto& fq : qv) {
        q.push({ fq.first, fq.second });
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //printf("%d %d\n", x, y);

        for (int i = 0; i < 4; i++) {
            int cx = dx[i] + x;
            int cy = dy[i] + y;
            //printf("%d %d\n", cx, cy);
            if (cx < 0 || cx >= m || cy < 0 || cy >= n) continue;
            
            if (map[cy][cx] == 2 || map[cy][cx] == 1) continue;
            q.push({ cx, cy });
            map[cy][cx] = 2;
            safe_zone--;
        }

        /*for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
        printf("\n");*/
    }
    //printf("%d\n", safe_zone);
    //printf("--------------------------\n");
    return safe_zone;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &fmap[i][j]);
            if (fmap[i][j] == 0) {
                v.push_back({ j, i });
                fsafe_zone++;
            }
            if (fmap[i][j] == 2) qv.push_back({ j, i });
        }
    }

    for (int i = 0; i < fsafe_zone - 2; i++) {
        fmap[v[i].second][v[i].first] = 1;
        for (int j = i + 1; j < fsafe_zone - 1; j++) {
            fmap[v[j].second][v[j].first] = 1;
            for (int k = j + 1; k < fsafe_zone; k++) {
                fmap[v[k].second][v[k].first] = 1;

                //printf("%d %d %d\n", i, j, k);
                int ret = bfs(i, j, k);
                if (ret > ans) ans = ret;

                fmap[v[k].second][v[k].first] = 0;
            }
            fmap[v[j].second][v[j].first] = 0;
        }
        fmap[v[i].second][v[i].first] = 0;
    }

    printf("%d\n", ans);
    return 0;
}
