#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define INF 1000000001
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int n, m, seg_min[262145], seg_max[262145], start_index = 1;
int a, b;
int st, en, ans_min, ans_max;

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d %d", &n, &m);

    while (start_index < n) start_index <<= 1;

    for (int i = start_index; i < start_index + n; i++) {
        scanf("%d", &seg_min[i]);
        seg_max[i] = seg_min[i];
    }

    for (int i = start_index + n; i < start_index * 2; i++) {
        seg_min[i] = INF;
        seg_max[i] = -INF;
    }


    for (int i = start_index - 1; i > 0; i--) {
        seg_min[i] = min(seg_min[i * 2], seg_min[i * 2 + 1]);
        seg_max[i] = max(seg_max[i * 2], seg_max[i * 2 + 1]);
    }


    /*for (int i = 1; i < start_index*2; i++) {
        printf("%3d ", seg_min[i] == INF ? -1 : seg_min[i]);
    }
    printf("\n");
    for (int i = 1; i < start_index*2; i++) {
        printf("%3d ", seg_max[i] == -INF ? -1 : seg_max[i]);
    }*/

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        st = a + start_index - 1;
        en = b + start_index - 1;

        ans_min = INF;
        ans_max = -INF;

        while (st <= en) {
            if (st % 2 == 1) {
                ans_min = min(ans_min, seg_min[st]);
                ans_max = max(ans_max, seg_max[st]);
                st++;
            }
            if (st % 2 == 0) {
                ans_min = min(ans_min, seg_min[en]);
                ans_max = max(ans_max, seg_max[en]);
                en--;
            }
            st /= 2;
            en /= 2;
        }
        printf("%d %d\n", ans_min, ans_max);

    }

    return 0;
}