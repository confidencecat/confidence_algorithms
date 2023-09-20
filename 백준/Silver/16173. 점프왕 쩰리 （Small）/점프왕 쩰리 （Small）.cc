#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<queue>
using namespace std;

int a[4][4], v[4][4];
int n;

bool f() {
    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    v[0][0] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        
        if (a[x][y] == -1) return true;

        q.pop();

        int jc = a[x][y];
        
        if (x + jc < n && v[x + jc][y] == 0) {
            q.push({ x + jc, y });
            v[x + jc][y] = 1;
        }
        if (y + jc < n && v[x][y + jc] == 0) {
            q.push({ x, y + jc });
            v[x][y + jc] = 1;
        }
    }
    return false;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("%s\n", f() ? "HaruHaru" : "Hing");
    return 0;
}
