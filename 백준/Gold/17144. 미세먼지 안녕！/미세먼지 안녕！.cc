#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m, t, ans = 0;
int air_cleaner_up_y = -1, air_cleaner_down_y;
int map[51][51], sum_map[51][51];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void diffusion() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] > 0) {
                int diffused = 0;
                for (int k = 0; k < 4; k++) {
                    int nx = j + dx[k];
                    int ny = i + dy[k];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] != -1) {
                        sum_map[ny][nx] += map[i][j] / 5;
                        diffused += map[i][j] / 5;
                    }
                }
                map[i][j] -= diffused;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            map[i][j] += sum_map[i][j];
            sum_map[i][j] = 0;
        }
    }
}

void work_air_cleaner() {
    // Up cleaner
    for (int i = air_cleaner_up_y - 1; i > 0; i--) map[i][0] = map[i - 1][0];
    for (int i = 0; i < m - 1; i++) map[0][i] = map[0][i + 1];
    for (int i = 0; i < air_cleaner_up_y; i++) map[i][m - 1] = map[i + 1][m - 1];
    for (int i = m - 1; i > 1; i--) map[air_cleaner_up_y][i] = map[air_cleaner_up_y][i - 1];
    map[air_cleaner_up_y][1] = 0;

    // Down cleaner
    for (int i = air_cleaner_down_y + 1; i < n - 1; i++) map[i][0] = map[i + 1][0];
    for (int i = 0; i < m - 1; i++) map[n - 1][i] = map[n - 1][i + 1];
    for (int i = n - 1; i > air_cleaner_down_y; i--) map[i][m - 1] = map[i - 1][m - 1];
    for (int i = m - 1; i > 1; i--) map[air_cleaner_down_y][i] = map[air_cleaner_down_y][i - 1];
    map[air_cleaner_down_y][1] = 0;
}


int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d %d %d", &n, &m, &t);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d ", &map[i][j]);
            if (air_cleaner_up_y == -1 && map[i][j] == -1) {
                air_cleaner_up_y = i;
                air_cleaner_down_y = i + 1;
            }
        }
    }
    while (t--) {
        diffusion();
        work_air_cleaner();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] != -1) ans += map[i][j];
        }
    }
    printf("%d\n", ans);
    return 0;
}
