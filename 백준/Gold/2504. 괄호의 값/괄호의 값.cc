#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

int n;
char s[34];

static int evaluate(char pr, int& idx) {
    int sum = 0;

    while (idx <= n + 1) {
        idx++;
        if (s[idx] == pr) {
            return sum == 0 ? 1 : sum;
        }
        if (s[idx] == '(') {
            sum += evaluate(')', idx) * 2;
        }
        else if (s[idx] == '[') {
            sum += evaluate(']', idx) * 3;
        }
        else {
            return 0; // 잘못된 괄호일 경우 0 반환
        }
    }
    return 0;
}

int main() {

    scanf("%s", s);
    n = strlen(s);

    stack<char> st;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '[') {
            st.push(s[i]);
        }
        else {
            if (st.empty()) {
                printf("0");
                return 0;
            }
            if ((s[i] == ')' && st.top() != '(') || (s[i] == ']' && st.top() != '[')) {
                printf("0");
                return 0;
            }
            st.pop();
        }
    }

    if (!st.empty()) {
        printf("0");
        return 0;
    }

    // 문자열 앞뒤에 구분자 추가
    for (int i = n; i >= 1; i--) s[i] = s[i - 1];
    s[0] = '{'; s[n + 1] = '}'; s[n + 2] = '\0';

    int idx = 0;
    int result = evaluate('}', idx);
    printf("%d", result);

    return 0;
}
