#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char s[12];

int main() {
    //freopen("input.txt", "rt", stdin);

    while (1) {
        scanf("%s", s);
        if (s[0] == 'e') break;

        int x = 0, o = 0, ccx = 0, cco = 0, rrx = 0, rro = 0, ddx = 0, ddo = 0;
        for (int i = 0; i < 3; i++) {
            int cx = 0, co = 0, rx = 0, ro = 0;
            for (int j = 0; j < 3; j++) {
                if (s[i * 3 + j] == 'X') { cx++; x++; }
                if (s[i * 3 + j] == 'O') { co++; o++; }
                if (s[j * 3 + i] == 'X') { rx++; }
                if (s[j * 3 + i] == 'O') { ro++; }
            }
            ccx += (cx == 3);
            cco += (co == 3);
            rrx += (rx == 3);
            rro += (ro == 3);
        }
        if (s[0] == 'X' && s[4] == 'X' && s[8] == 'X') ddx++;
        if (s[2] == 'X' && s[4] == 'X' && s[6] == 'X') ddx++;
        if (s[0] == 'O' && s[4] == 'O' && s[8] == 'O') ddo++;
        if (s[2] == 'O' && s[4] == 'O' && s[6] == 'O') ddo++;

        if (o > x || x - o > 1) {
            printf("invalid\n");
            continue;
        }

        if ((ddx + ccx + rrx > 0) && (ddo + cco + rro > 0)) {
            printf("invalid\n");
            continue;
        }

        if ((ddx + ccx + rrx > 0) && (x != o + 1)) {
            printf("invalid\n");
            continue;
        }
        if ((ddo + cco + rro > 0) && (x != o)) {
            printf("invalid\n");
            continue;
        }

        if ((ddx + ccx + rrx + ddo + cco + rro == 0) && (x + o < 9)) {
            printf("invalid\n");
            continue;
        }

        printf("valid\n");
    }

    return 0;
}
