#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXL 55

char A_str[MAXL], B_str[MAXL], C_str[MAXL];
int len1, len2, len3;

bool f() {
    static bool dp[MAXL][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;

    for (int p = 0; p < len3; p++) {
        for (int carry = 0; carry <= 1; carry++) {
            if (!dp[p][carry]) continue;

            int idxA = len1 - 1 - p;
            int idxB = len2 - 1 - p;
            int idxC = len3 - 1 - p;
            char chC = C_str[idxC];

            for (int dA = 0; dA <= 9; dA++) {
                if (idxA < 0) {
                    if (dA != 0) continue;
                } else {
                    char chA = A_str[idxA];
                    if (chA == '?') {
                        if (idxA == 0 && len1 > 1 && dA == 0) continue;
                    } else {
                        if (dA != chA - '0') continue;
                    }
                }
                for (int dB = 0; dB <= 9; dB++) {
                    if (idxB < 0) {
                        if (dB != 0) continue;
                    } else {
                        char chB = B_str[idxB];
                        if (chB == '?') {
                            if (idxB == 0 && len2 > 1 && dB == 0) continue;
                        } else {
                            if (dB != chB - '0') continue;
                        }
                    }

                    int sum = dA + dB + carry;
                    int dC = sum % 10;
                    int carry2 = sum / 10;

                    if (chC == '?') {
                        if (idxC == 0 && len3 > 1 && dC == 0) continue;
                    } else {
                        if (dC != chC - '0') continue;
                    }

                    dp[p + 1][carry2] = true;
                }
            }
        }
    }
    return dp[len3][0];
}

int main() {
    
    char expr[101];
    if (scanf("%100s", expr) != 1) return 0;

    int n = strlen(expr), i_plus = -1, i_eq = -1;
    for (int i = 0; i < n; i++) {
        if (expr[i] == '+') i_plus = i;
        else if (expr[i] == '=') i_eq = i;
    }

    len1 = i_plus;
    len2 = i_eq - i_plus - 1;
    len3 = n - i_eq - 1;

    strncpy(A_str, expr, len1);     A_str[len1] = '\0';
    strncpy(B_str, expr + i_plus + 1, len2); B_str[len2] = '\0';
    strncpy(C_str, expr + i_eq + 1, len3);   C_str[len3] = '\0';

    int mx12 = len1 > len2 ? len1 : len2;
    if (len3 < mx12 || len3 > mx12 + 1) {
        printf("-1\n");
        return 0;
    }
    if ((A_str[0] == '0' && len1 > 1) ||
        (B_str[0] == '0' && len2 > 1) ||
        (C_str[0] == '0' && len3 > 1)) {
        printf("-1\n");
        return 0;
    }

    for (int i = 0; i < len3; i++) {
        if (C_str[i] == '?') {
            bool ok = false;
            for (char d = '9'; d >= '0'; d--) {
                if (i == 0 && len3 > 1 && d == '0') continue;
                C_str[i] = d;
                if (f()) { ok = true; break; }
            }
            if (!ok) { printf("-1\n"); return 0; }
        }
    }
    for (int i = 0; i < len1; i++) {
        if (A_str[i] == '?') {
            bool ok = false;
            for (char d = '9'; d >= '0'; d--) {
                if (i == 0 && len1 > 1 && d == '0') continue;
                A_str[i] = d;
                if (f()) { ok = true; break; }
            }
            if (!ok) { printf("-1\n"); return 0; }
        }
    }

    int borrow = 0;
    int B_digits[MAXL] = {0};
    for (int p = 0; p < len3; p++) {
        int iC = len3 - 1 - p;
        int iA = len1 - 1 - p;
        int iB = len2 - 1 - p;
        int dC = C_str[iC] - '0';
        int dA = (iA >= 0 ? A_str[iA] - '0' : 0);
        int v = dC - borrow - dA;
        if (v < 0) { v += 10; borrow = 1; }
        else       { borrow = 0; }
        if (iB >= 0) B_digits[iB] = v;
        else if (v != 0) {
            printf("-1\n");
            return 0;
        }
    }
    if (borrow != 0) {
        printf("-1\n");
        return 0;
    }
    for (int i = 0; i < len2; i++) {
        if (B_str[i] == '?') {
            B_str[i] = '0' + B_digits[i];
        } else if (B_str[i] - '0' != B_digits[i]) {
            printf("-1\n");
            return 0;
        }
    }
    if (B_str[0] == '0' && len2 > 1) {
        printf("-1\n");
        return 0;
    }

    printf("%s+%s=%s\n", A_str, B_str, C_str);
    return 0;
}
