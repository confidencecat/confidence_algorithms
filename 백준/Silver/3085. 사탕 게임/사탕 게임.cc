#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

int n;
char a[52][52];

int answer = 0;

int dx[2] = { 0, 1 };
int dy[2] = { -1, 0 };

int c(char C) {
    if (C == 'C') return 0;
    if (C == 'P') return 1;
    if (C == 'Z') return 2;
    if (C == 'Y') return 3;
    return -1; // 예외 처리
}

int check() {
    int maxCount = 1;
    for (int i = 1; i <= n; i++) {
        int count = 1;
        for (int j = 2; j <= n; j++) {
            if (a[i][j] == a[i][j - 1]) {
                count++;
            }
            else {
                count = 1;
            }
            maxCount = max(maxCount, count);
        }
    }
    for (int j = 1; j <= n; j++) {
        int count = 1;
        for (int i = 2; i <= n; i++) {
            if (a[i][j] == a[i - 1][j]) {
                count++;
            }
            else {
                count = 1;
            }
            maxCount = max(maxCount, count);
        }
    }
    return maxCount;
}

int main() {
    //freopen("input.txt", "rt", stdin);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf(" %c", &a[i][j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int d = 0; d < 2; d++) {
                int cx = j + dx[d];
                int cy = i + dy[d];
                if (cx <= 0 || cx > n || cy <= 0 || cy > n) continue;

                char change = a[cy][cx];
                a[cy][cx] = a[i][j]; a[i][j] = change;

                answer = max(answer, check());

                change = a[cy][cx];
                a[cy][cx] = a[i][j]; a[i][j] = change;
            }
        }
    }

    printf("%d", answer);
    return 0;
}
