#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

char mmap[1000][1001];
int n, m, cnt, map[1000][1000], d[250001], dn = 2, sum = 0, chd[250001];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
queue<pair<int, int>> q, bfs;

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%s", mmap[i]);
        for (int j = 0; j < m; j++) {
            if (mmap[i][j] == '0') q.push({i, j});
            else map[i][j] = 1;
        }
    }

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (map[y][x] != 0) continue;

        //printf("x : %d    y : %d\n", x, y);

        cnt = 1;

        bfs.push({ y, x });
        map[y][x] = dn;

        while (!bfs.empty()) {
            int by = bfs.front().first;
            int bx = bfs.front().second;
            bfs.pop();

            for (int i = 0; i < 4; i++) {
                int cy = by + dy[i];
                int cx = bx + dx[i];
                
                if (cx < 0 || cx >= m || cy < 0 || cy >= n) continue;
                if (map[cy][cx] != 0) continue;

                map[cy][cx] = dn;
                cnt++;
                bfs.push({ cy, cx });
            }
        }

        d[dn++] = cnt;
    }

  /*  for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < dn; i++) {
        printf("%d ", d[i]);
    }
    printf("\n");*/

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1) {
                int neighs[4], neighCnt = 0, sum = 1;
                // 4방향에서 서로 다른 ID만 수집
                for (int k = 0; k < 4; k++) {
                    int ni = i + dy[k], nj = j + dx[k];
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                    int id = map[ni][nj];
                    if (id > 1 && !chd[id]) {
                        chd[id] = 1;
                        neighs[neighCnt++] = id;
                    }
                }
                // 수집된 ID만 돌면서 크기 더하고 chd 초기화
                for (int t = 0; t < neighCnt; t++) {
                    sum += d[neighs[t]];
                    chd[neighs[t]] = 0;
                }
                printf("%d", sum % 10);
            }
            else {
                printf("0");
            }
        }
        printf("\n");
    }
       

    return 0;
}