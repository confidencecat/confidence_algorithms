#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int y, x, d;
} que;

int nn;
que q[100000];
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int mp[22][22], vis[22][22], tgt[100000][3], t, bf = 2, by, bx, rs, fc;

void f(int y, int x) {
    int f, r, qy = y, qx = x, qd = 0, ds = 100000;
    f = -1; r = -1;
    q[++r].y = qy;
    q[r].x = qx;
    q[r].d = qd;
    vis[qy][qx] = 1;
    while (f != r) {
        qy = q[++f].y;
        qx = q[f].x;
        qd = q[f].d;
        for (int i = 0; i < 4; i++) {
            if (qy + dy[i] < 1 || qy + dy[i] > nn || qx + dx[i] < 1 || qx + dx[i] > nn) continue;
            if (qd + 1 > ds) continue;
            if (vis[qy + dy[i]][qx + dx[i]]) continue;
            if (mp[qy + dy[i]][qx + dx[i]] > bf) continue;

            if (mp[qy + dy[i]][qx + dx[i]] != 0 && mp[qy + dy[i]][qx + dx[i]] < bf) {
                tgt[t][0] = qy + dy[i];
                tgt[t][1] = qx + dx[i];
                tgt[t++][2] = qd + 1; ds = qd + 1;
            }
            vis[qy + dy[i]][qx + dx[i]] = 1;
            q[++r].y = qy + dy[i];
            q[r].x = qx + dx[i]; q[r].d = qd + 1;
        }
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d", &nn);
    for (int i = 1; i <= nn; i++) {
        for (int j = 1; j <= nn; j++) {
            scanf("%d", &mp[i][j]);
            if (mp[i][j] == 9) {
                by = i;
                bx = j;
                mp[i][j] = 0;
            }
        }
    }
    while (1) {
        f(by, bx);
        if (t == 0) break;
        else {
            int my = 22, mx = 22;
            for (int i = 0; i < t; i++)
                if (tgt[i][0] < my) my = tgt[i][0];
            for (int i = 0; i < t; i++)
                if (tgt[i][0] == my && tgt[i][1] < mx) mx = tgt[i][1];
            for (int i = 0; i < t; i++)
                if (tgt[i][0] == my && tgt[i][1] == mx) {
                    by = tgt[i][0];
                    bx = tgt[i][1];
                    rs += tgt[i][2];
                    mp[by][bx] = 0;
                    break;
                }
            t = 0;
            fc++;
            if (fc == bf) {
                fc = 0;
                bf++;
            }
        }
        for (int i = 1; i <= nn; i++)
            for (int j = 1; j <= nn; j++)
                vis[i][j] = 0;
    }
    printf("%d\n", rs);
    return 0;
}
