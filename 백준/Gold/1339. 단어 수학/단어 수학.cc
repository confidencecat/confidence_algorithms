#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef long long int ll;

int n, mx = 0, len[11];
char s[11][11];
ll a[26][2];
int b[26];
ll answer = 0;
int num = 9;

int com(const void* A, const void* B) {
    ll* a = (ll*)A;
    ll* b = (ll*)B;
    return b[0] - a[0];
}

int main() {
    //freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        len[i] = strlen(s[i]);
        if (len[i] > mx) mx = len[i];

        for (int j = 0; j < len[i]; j++) {
            int index = s[i][len[i] - j - 1] - 'A';
            a[index][0] += (ll)pow(10, j);
            a[index][1] = index;
        }
    }

    qsort(a, 26, sizeof(a[0]), com);

    for (int i = 0; i < 26; i++) b[i] = -1;

    for (int i = 0; i < 26; i++) {
        if (a[i][0] > 0) {
            b[a[i][1]] = num--;
        }
    }

    for (int i = 0; i < n; i++) {
        ll val = 0;
        for (int j = 0; j < len[i]; j++) {
            val = val * 10 + b[s[i][j] - 'A'];
        }
        answer += val;
    }

    printf("%lld\n", answer);
    return 0;
}
