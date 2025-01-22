#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m, x, y, k;
int map[20][20];
int dice[6] = { 0, 0, 0, 0, 0, 0 };
int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };

void roll_dice(int direction) {
    int temp[6];
    for (int i = 0; i < 6; i++) temp[i] = dice[i];

    if (direction == 1) {
        dice[0] = temp[3];
        dice[2] = temp[0];
        dice[3] = temp[5];
        dice[5] = temp[2];
    }
    else if (direction == 2) {
        dice[0] = temp[2];
        dice[2] = temp[5];
        dice[3] = temp[0];
        dice[5] = temp[3];
    }
    else if (direction == 3) {
        dice[0] = temp[4];
        dice[1] = temp[0];
        dice[4] = temp[5];
        dice[5] = temp[1];
    }
    else if (direction == 4) {
        dice[0] = temp[1];
        dice[1] = temp[5];
        dice[4] = temp[0];
        dice[5] = temp[4];
    }
}

int main() {
    //freopen("input.txt", "r", stdin);

    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &map[i][j]);

    while (k--) {
        int command;
        scanf("%d", &command);

        int nx = x + dx[command];
        int ny = y + dy[command];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

        x = nx;
        y = ny;
        roll_dice(command);

        if (map[x][y] == 0) {
            map[x][y] = dice[5];
        }
        else {
            dice[5] = map[x][y];
            map[x][y] = 0;
        }

        printf("%d\n", dice[0]);
    }

    return 0;
}
