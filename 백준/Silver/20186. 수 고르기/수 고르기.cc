#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<utility>
#include <stdlib.h>
using namespace std;


typedef struct Ac {
    int e, m;
} ac;

int com1(const void* first, const void* second) {
    ac* f = (ac*)first;
    ac* s = (ac*)second;
    return s->e > f->e;
}

int com2(const void* first, const void* second) {
    ac* f = (ac*)first;
    ac* s = (ac*)second;
    return s->m < f->m;
}

int n, k, sum = 0;
ac a[5001];
ac b[5001];

int main() {
    //freopen("input.txt", "rt", stdin);

    

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].e);
        a[i].m = i;
    }

    qsort(a, n, sizeof(ac), com1);

    for (int i = 0; i < k; i++) {
        b[i].e = a[i].e;
        b[i].m = a[i].m;
        //printf("(%d %d)  ", a[i].e, a[i].m);
    }
    //printf("\n");


    qsort(b, k, sizeof(ac), com2);
    for (int i = 0; i < k; i++) {
        //printf("(%d %d)  ", b[i].e, b[i].m);
        sum += b[i].e - i;
    }
    printf("%d\n", sum);
    return 0;
}