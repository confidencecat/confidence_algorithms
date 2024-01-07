#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

char s[100001];

int main() {
    //freopen("input.txt", "rt", stdin);
    fgets(s, sizeof(s), stdin);
    int n = strlen(s);
    if (s[n - 1] == '\n') s[n - 1] = '\0'; // 개행 문자 제거
    n = strlen(s); // 개행 문자를 제거한 후의 길이 재계산

    vector<char> ns;
    bool tf = false;
    for (int i = 0; i < n; i++) {
        if (tf) {
            // 태그 내부인 경우 즉시 출력
            printf("%c", s[i]);
            if (s[i] == '>') tf = false;
        } else {
            if (s[i] == '<') {
                // 태그 시작 전 단어 뒤집어 출력
                while (!ns.empty()) {
                    printf("%c", ns.back());
                    ns.pop_back();
                }
                tf = true;
                printf("<");
            } else if (s[i] == ' ') {
                // 단어 뒤집어 출력 후 공백 출력
                while (!ns.empty()) {
                    printf("%c", ns.back());
                    ns.pop_back();
                }
                printf(" ");
            } else {
                // 태그 및 공백이 아닌 경우 스택에 추가
                ns.push_back(s[i]);
            }
        }
    }

    // 마지막 단어 뒤집어 출력
    while (!ns.empty()) {
        printf("%c", ns.back());
        ns.pop_back();
    }
    return 0;
}
