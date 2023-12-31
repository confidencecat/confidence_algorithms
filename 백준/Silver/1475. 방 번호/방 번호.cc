#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#define max(a, b) a > b ? a : b

int number[10], ans;
char s[8];

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%s", s);
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        if (s[i] - 48 == 6 || s[i] - 48 == 9) {
            if (number[6] < number[9]) {
                number[6]++;
                ans = max(ans, number[6]);
            }
            else {
                number[9]++;
                ans = max(ans, number[9]);
            }

        }
        else {
            number[s[i] - 48]++;
            ans = max(ans, number[s[i] - 48]);
        }
        
    }
    printf("%d\n", ans);
    return 0;
}
