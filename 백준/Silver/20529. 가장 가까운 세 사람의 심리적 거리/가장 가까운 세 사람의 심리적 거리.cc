#include <stdio.h>
#include <string.h>

int dist(const char *a, const char *b) {
    int d = 0;
    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i]) {
            d += 1;
        }
    }
    return d;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        char mbti[100000][5];
        for (int j = 0; j < n; j++) {
            scanf("%s", mbti[j]);
        }
        if (n > 32) {
            printf("0\n");
        } else {
            int minDist = 100;
            for (int x = 0; x < n - 2; x++) {
                for (int y = x + 1; y < n - 1; y++) {
                    for (int z = y + 1; z < n; z++) {
                        int d = dist(mbti[x], mbti[y]) + dist(mbti[y], mbti[z]) + dist(mbti[x], mbti[z]);
                        if (d < minDist) {
                            minDist = d;
                        }
                    }
                }
            }
            printf("%d\n", minDist);
        }
    }

    return 0;
}
