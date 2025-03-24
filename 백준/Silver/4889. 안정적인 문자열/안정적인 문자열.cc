#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stack>

int main() {
    char s[2001];
    int caseNum = 1;

    while (1) {
        scanf("%s", s);
        if (s[0] == '-') break;

        int len = strlen(s), cnt = 0;
        std::stack<char> stk;

        for (int i = 0; i < len; i++) {
            if (s[i] == '{') {
                stk.push('{');
            }
            else {
                if (!stk.empty()) {
                    stk.pop();
                }
                else {
                    cnt++;
                    stk.push('{');
                }
            }
        }

        cnt += stk.size() / 2;
        printf("%d. %d\n", caseNum++, cnt);
    }

    return 0;
}
