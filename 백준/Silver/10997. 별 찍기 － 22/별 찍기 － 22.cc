#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define fr(s, e) for(int i = s; i <= e; i++)

int n;
char a[400][398];

void f(int t, int sx, int ex, int sy, int ey) {
    if (t < n) {
        fr(sx, ex) a[ey][i] = '*';
        fr(sy, ex) a[sy][i] = '*';

        fr(sy, ey) a[i][ex] = '*';
        fr(sy, ey - 2) a[i][sy] = '*';

        f(t + 1, sx + 2, ex - 2, sy + 2, ey - 2);
    }
}


int main() {
    //freopen("input.txt", "rt", stdin);
    int x, y;
    scanf("%d", &n);
    if (n == 1) printf("*\n");
    else {
        x = (n - 1) * 4;//397
        y = (n * 3) + n - 2;//399
        for (int i = 0; i <= x; i++) {
            a[0][i] = '*';
        }
        for (int i = 1; i <= y; i++) {
            a[i][0] = '*';
        }
        
        f(1, 0, x, 2, y);

        for (int i = 0; i <= y; i++) {
            for (int j = 0; j <= x; j++) {
                if (i == 1 && j == 1) break;
                printf("%c", a[i][j] ? a[i][j] : ' ');
            }
            printf("\n");
        }
    }
    
    return 0;
}
