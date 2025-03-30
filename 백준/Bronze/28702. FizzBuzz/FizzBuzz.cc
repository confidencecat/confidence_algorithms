#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char s[3][10];
int next = -1;
int num(char fs[]) {
    int m = strlen(fs), ans = 0;
    for (int i = 0; i < m; i++) ans = ans * 10 + (fs[i] - 48);
    return ans;
}

int main() {
    for (int i = 0; i < 3; i++) {
        scanf("%s", s[i]);
        if (next == -1 && s[i][0] <= '9' && s[i][0] >= '0') {
            next = num(s[i]) + (3 - i);
        }
    }
    if (next % 3 == 0 && next % 5 == 0) printf("FizzBuzz");
    else if (next % 3 == 0 && next % 5 != 0) printf("Fizz");
    else if (next % 3 != 0 && next % 5 == 0) printf("Buzz");
    else printf("%d", next);

    return 0;
}
