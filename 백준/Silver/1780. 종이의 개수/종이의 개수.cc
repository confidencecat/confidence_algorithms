#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int a[2188][2188];
int count[3];

void f(int x, int y, int n) {
    int start = a[y][x];
    bool isUniform = true;

    for (int i = y; i < y + n; i++) {
        for (int j = x; j < x + n; j++) {
            if (a[i][j] != start) {
                isUniform = false; 
                break;  
            }
        }
        if (!isUniform) {
            break;
        }
    }

    if (isUniform) {
        count[start + 1]++;
    }
    else { 
        int nextSize = n / 3;
        for (int dy = 0; dy < 3; dy++) {
            for (int dx = 0; dx < 3; dx++) {
                f(x + dx * nextSize, y + dy * nextSize, nextSize);
            }
        }
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    f(0, 0, n);
    for (int i = 0; i < 3; i++) {
        printf("%d\n", count[i]);
    }
    return 0;
}
