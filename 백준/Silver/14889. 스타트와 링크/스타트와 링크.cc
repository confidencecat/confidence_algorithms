#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int N;
int S[20][20];
int visited[20];
int min_diff = 1e9;

void f(int idx, int count) {
    if (count == N / 2) {
        int start_team = 0, link_team = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i] && visited[j]) {
                    start_team += S[i][j];
                }
                else if (!visited[i] && !visited[j]) {
                    link_team += S[i][j];
                }
            }
        }
        int diff = abs(start_team - link_team);
        min_diff = MIN(min_diff, diff);
        return;
    }

    for (int i = idx; i < N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            f(i + 1, count + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &S[i][j]);
        }
    }

    f(0, 0);
    printf("%d\n", min_diff);

    return 0;
}
