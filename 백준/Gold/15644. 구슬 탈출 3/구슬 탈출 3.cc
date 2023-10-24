#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

typedef struct {
    int rx, ry, bx, by, ld, moveCount;
    char ds[12];
} R;

char s[11][11];
int n, m;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
char dc[4] = { 'L', 'R', 'U', 'D' };  // 문자 배열로 수정

int c(int d) {
    if (d == 0) return 1;
    if (d == 1) return 0;
    if (d == 2) return 3;
    if (d == 3) return 2;
}

int main() {
    //freopen("input.txt", "rt", stdin);

    queue<R> q;
    int tf = 0;
    int x1, y1, x2, y2, answer = -1;
    char answer_ds[12];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'R') {
                x1 = i; y1 = j;
            }
            if (s[i][j] == 'B') {
                x2 = i; y2 = j;
            }
        }
    }
    q.push({ x1, y1, x2, y2, -1, 1, "" });

    while (!q.empty() && tf == 0) {
        R cur = q.front(); q.pop();

        if (cur.moveCount > 10) break;

        for (int d = 0; d < 4; d++) {
            if (d == cur.ld) continue;

            int nrx = cur.rx, nry = cur.ry, nbx = cur.bx, nby = cur.by;
            bool redGoal = false, blueGoal = false;

            while (true) {
                if (s[nrx + dx[d]][nry + dy[d]] == '#') break;
                if (s[nrx + dx[d]][nry + dy[d]] == 'O') {
                    redGoal = true; break;
                }
                nrx += dx[d]; nry += dy[d];
            }

            while (true) {
                if (s[nbx + dx[d]][nby + dy[d]] == '#') break;
                if (s[nbx + dx[d]][nby + dy[d]] == 'O') {
                    blueGoal = true; break;
                }
                nbx += dx[d]; nby += dy[d];
            }

            if (blueGoal) continue;

            if (redGoal) {
                char newDs[12];
                strcpy(newDs, cur.ds);
                newDs[cur.moveCount - 1] = dc[d];
                newDs[cur.moveCount] = '\0';
                strcpy(answer_ds, newDs);
                answer = cur.moveCount;
                tf = 1;
                break;
            }

            if (nrx == nbx && nry == nby) {
                switch (d) {
                case 0: cur.ry < cur.by ? nby++ : nry++; break;
                case 1: cur.ry > cur.by ? nby-- : nry--; break;
                case 2: cur.rx < cur.bx ? nbx++ : nrx++; break;
                case 3: cur.rx > cur.bx ? nbx-- : nrx--; break;
                }
            }

            char newDs[12];
            strcpy(newDs, cur.ds);
            newDs[cur.moveCount - 1] = dc[d];
            newDs[cur.moveCount] = '\0';

            R temp;
            temp.rx = nrx;
            temp.ry = nry;
            temp.bx = nbx;
            temp.by = nby;
            temp.ld = c(d);
            temp.moveCount = cur.moveCount + 1;
            strcpy(temp.ds, newDs);
            q.push(temp);
           //printf("%d %d | %d %d | %d | %s\n", nrx, nry, nbx, nby, cur.moveCount, newDs);
        }
    }
    printf("%d\n", answer);
    if (answer != -1) printf("%s\n", answer_ds);
    return 0;
}

