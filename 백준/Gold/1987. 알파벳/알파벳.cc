#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

bool ch[28];
int n, m, mx = 0;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
char s[21][21];

void d(int x, int y, int count) {
    if (mx < count) mx = count;
    for (int i = 0; i < 4; i++) {
        int cx = x + dx[i];
        int cy = y + dy[i];
        if (cx >= m || cx < 0 || cy >= n || cy < 0) continue;
        if (ch[s[cy][cx] - 65] == false) {
            ch[s[cy][cx] - 65] = true;
            
            d(cx, cy, count + 1);
            ch[s[cy][cx] - 65] = false;
        }
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    ch[s[0][0] - 65] = true;
    d(0, 0, 1);

    printf("%d\n", mx);
    return 0;
}
