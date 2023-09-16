#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100000
#define TRUE 1
#define FALSE 0

typedef struct {
    int k;
} e;

typedef struct {
    e h[MAX_ELEMENT];
    int s;
} h;

void ini(h* he)
{
    he->s = 0;
}

void ins(h* he, e it)
{
    int i;
    i = ++(he->s);
    while ((i != 1) && (abs(it.k) <= abs(he->h[i / 2].k))) {
        if (abs(it.k) == abs(he->h[i / 2].k) && it.k > he->h[i / 2].k)
            break;
        he->h[i] = he->h[i / 2];
        i /= 2;
    }
    he->h[i] = it;
}

e del(h* he)
{
    int p, c;
    e it, te;

    if (!he->s) {
        it.k = 0;
        return it;
    }
    it = he->h[1];
    te = he->h[(he->s)--];
    p = 1;
    c = 2;
    while (c <= he->s) {
        if ((c < he->s) &&
            abs(he->h[c].k) > abs(he->h[c + 1].k))
            c++;
        else if ((c < he->s) && abs(he->h[c].k) == abs(he->h[c + 1].k) &&
            (he->h[c].k) > he->h[c + 1].k)
            c++;
        if (abs(te.k) < abs(he->h[c].k)) break;
        else if (abs(te.k) == abs(he->h[c].k) &&
            te.k < he->h[c].k)
            break;
        he->h[p] = he->h[c];
        p = c;
        c *= 2;
    }
    he->h[p] = te;
    return it;
}

int main()
{
    h he;
    e it;
    int n, i;
    int inp;

    ini(&he);
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &inp);
        if (inp > 0 || inp < 0) {
            it.k = inp;
            ins(&he, it);
        }
        else
            printf("%d\n", del(&he).k);
    }
}
