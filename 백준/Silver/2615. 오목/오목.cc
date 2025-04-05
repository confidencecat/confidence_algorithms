#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int map[20][20];
int dx[4] = { 0, 1, 1, 1 };
int dy[4] = { 1, 1, 0, -1 };
bool tf = true, dtf = true;

int ans = 20, ansx = 20, ansy = 20;

int main() {
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++)
            scanf("%d ", &map[i][j]);
    }

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (map[i][j] == 0) continue;
            tf = false;
            //printf("==== %d %d ====\n", j, i);
            for (int k = 0; k < 4; k++) {
                int cx = j, cy = i;
                dtf = true;
                //printf("%d : ", k + 1);
                for (int c = 0; c < 4; c++) {
                    if (c == 0 && (j - dx[k] >= 0 && j - dx[k] < 19 && i - dy[k] >= 0 && i - dy[k] < 19)
                        && map[i - dy[k]][j - dx[k]] == map[i][j]) {
                        dtf = false;
                        break;
                    }

                    cx += dx[k];
                    cy += dy[k];
                    //printf(" %d(%d %d, %d)", map[cy][cx], cx, cy, dtf);
                    if (cx < 0 || cx >= 19 || cy < 0 || cy >= 19) {
                        dtf = false;
                        break;
                    }
                    if (map[cy][cx] != map[i][j]) {
                        dtf = false;
                        break;
                    }
                }
                // 6목 이상 검사: 5목 조건을 만족한 후 다음 돌(6번째)이 같은 색이면 dtf를 false로 설정
                if (dtf) {
                    int nx = cx + dx[k], ny = cy + dy[k];
                    if (nx >= 0 && nx < 19 && ny >= 0 && ny < 19 && map[ny][nx] == map[i][j]) {
                        dtf = false;
                    }
                }
                //printf("\n%d\n", dtf);
                if (dtf) {
                    tf = true;
                    break;
                }
            }
            if (tf) {
                ans = map[i][j];
                if (ansx > j + 1) {
                    ansx = j + 1;
                    ansy = i + 1;
                }
                else if (ansx == j + 1) {
                    if (i + 1 < ansy) ansy = i + 1;
                }
            }
        }
    }
    if (ans == 20)
        printf("0");
    else {
        printf("%d\n%d %d", ans, ansy, ansx);
    }

    return 0;
}
