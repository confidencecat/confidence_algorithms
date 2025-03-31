#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    //freopen("input.txt", "rt", stdin);

    int A, B, C, M;
    scanf("%d %d %d %d", &A, &B, &C, &M);

    int fatigue = 0;
    int work_done = 0;

    for (int i = 0; i < 24; i++) {
        if (fatigue + A <= M) {
            fatigue += A;
            work_done += B;
        }
        else {
            fatigue -= C;
            if (fatigue < 0) fatigue = 0;
        }
    }

    printf("%d\n", work_done);
    return 0;

    return 0;
}
