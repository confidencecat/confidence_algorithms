#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _r {
    int s, e;
}r;

int com(const void* first, const void* second) {
    r* ff = (r*)first;
    r* ss = (r*)second;
    if (ff->e > ss->e) {
        return 1;
    }
    else if (ff->e < ss->e) {
        return -1;
    }
    else {
        if (ff->s > ss->s) {
            return 1;
        }
        else if (ff->s < ss->s) {
            return -1;
        }
        else {
            return 0;
        }
    }
}

int n, ans = 1, end;
r a[100001];

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i].s, &a[i].e);
    }

    qsort(a, n, sizeof(r), com);

    end = a[0].e;
    for (int i = 1; i < n; i++) {
        if (a[i].s >= end) {
            ans++;
            end = a[i].e;
        }
    }
    printf("%d\n", ans);


    return 0;
}

