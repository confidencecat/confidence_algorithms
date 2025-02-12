#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char s[1001], t[1001];
int sn, tn, r = 0;
bool tf = true;

void re() {
    for (int i = 0; i < r/ 2; i++) {
        int temp = t[i];
        t[i] = t[r - i - 1];
        t[r - i - 1] = temp;
    }
}

int main() {
    scanf("%s %s", &s, &t);
    sn = strlen(s);
    tn = strlen(t);

    for(int i = 0; i < tn - sn + 1; i++){
        r = tn - i;
        if (t[r] == 'B') {
            re();
        }
    }
    for (int i = 0; i < sn; i++) {
        if (s[i] != t[i]) tf = false;
    }

    printf("%d\n", tf ? 1 : 0);

    return 0;
}
