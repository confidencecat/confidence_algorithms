#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<queue>
using namespace std;

typedef struct {
    int rx, ry, bx, by, ld, moveCount;
} R;

char s[11][11];
int n, m;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main() {
    //freopen("input.txt", "rt", stdin);

    queue<R> q;
    int tf = 0;
    int x1, y1, x2, y2;
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
    q.push({ x1, y1, x2, y2, -1, 1 });

    while (!q.empty()) {
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
            q.push({ nrx, nry, nbx, nby, d, cur.moveCount + 1 });
        }
    }
    printf("%d\n", tf);
    return 0;
}
