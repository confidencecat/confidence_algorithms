#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

typedef struct {
    int x, y, d;
} Q;

int main() {
    int n, m, rx, ry, rd, ans = 0;
    int map[52][52]; // 배열의 크기를 52x52로 조정
    int md[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // 상, 우, 하, 좌
    queue<Q> q;

    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &ry, &rx, &rd);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]); // 입력 포맷을 올바르게 수정
        }
    }

    q.push({ rx, ry, rd });

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        q.pop();

        if (map[y][x] == 0) {
            map[y][x] = 2;
            ans++;
        }

        bool allCleaned = true;
        for (int i = 0; i < 4; i++) {
            int nextD = (d + 3) % 4; // 회전하는 방향
            int nx = x + md[nextD][1];
            int ny = y + md[nextD][0];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] == 0) {
                q.push({ nx, ny, nextD }); // 회전한 방향으로 전진
                allCleaned = false;
                break;
            }
            d = nextD; // 다음 방향으로 회전
        }

        if (allCleaned) {
            int backD = (d + 2) % 4; // 반대 방향
            int bx = x + md[backD][1];
            int by = y + md[backD][0];

            if (bx >= 0 && bx < m && by >= 0 && by < n && map[by][bx] != 1) {
                q.push({ bx, by, d }); // 후진
            }
            else {
                break; // 더 이상 후진할 수 없으면 종료
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
