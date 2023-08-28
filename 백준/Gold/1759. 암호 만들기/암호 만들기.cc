#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

char a[16];
int v[16];
int l, c;

void chk() {
    char s[16];
    int vo = 0, id = 0;
 
    for (int i = 0; i < c; i++) {
        if (v[i]) {
            s[id] = a[i];
            id++;
            if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') 
                vo++;
        }
    }
    s[l] = '\0';
    
    if (vo && l - vo >= 2) printf("%s\n", s);
}

int sl(int idx, int cn) {
    if (cn == l) {
        chk();
        return 0;
    }
    if (idx == c) return 0;
 
    v[idx] = 1;
    sl(idx + 1, cn + 1);
 
    v[idx] = 0;
    sl(idx + 1, cn);
 
    return 0;
}
 
int main() {
    scanf("%d %d", &l, &c);
    for (int i = 0; i < c; i++)
        scanf(" %c", &a[i]);
    
    sort(a, a + c);
 
    for (int i = 0; i <= c - l; i++) {
        memset(v, 0, sizeof(v));
        v[i] = 1;
        sl(i + 1, 1);
    }
    return 0;
}
