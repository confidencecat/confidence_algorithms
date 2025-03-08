#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int s;
    int e;
} Flower;

int cmp(const void* a, const void* b) {
    Flower* f1 = (Flower*)a;
    Flower* f2 = (Flower*)b;
    if (f1->s == f2->s) return f2->e - f1->e;
    return f1->s - f2->s;
}

int main() {
    int n;
    scanf("%d", &n);
    Flower f[100001];
    int cnt = 0;
    int month[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
    for (int i = 0; i < n; i++) {
        int sm, sd, em, ed;
        scanf("%d %d %d %d", &sm, &sd, &em, &ed);
        int start = month[sm - 1] + sd;
        int end = month[em - 1] + ed - 1;
        if (end < 60 || start > 334) continue;
        if (start < 60) start = 60;
        if (end > 334) end = 334;
        f[cnt].s = start;
        f[cnt].e = end;
        cnt++;
    }
    qsort(f, cnt, sizeof(Flower), cmp);
    int current = 60, ans = 0, idx = 0, max_end = 0;
    while (current <= 334) {
        int flag = 0;
        while (idx < cnt && f[idx].s <= current) {
            if (f[idx].e > max_end) {
                max_end = f[idx].e;
                flag = 1;
            }
            idx++;
        }
        if (!flag) break;
        ans++;
        current = max_end + 1;
    }
    if (current <= 334) printf("0");
    else printf("%d", ans);
    return 0;
}
