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
    if (s[n - 1] == '\n') s[n - 1] = '\0';
    n = strlen(s);

    vector<char> ns;
    bool tf = false;
    for (int i = 0; i < n; i++) {
        if (tf) {
            printf("%c", s[i]);
            if (s[i] == '>') tf = false;
        }
        else {
            if (s[i] == '<') {
                while (!ns.empty()) {
                    printf("%c", ns.back());
                    ns.pop_back();
                }
                tf = true;
                printf("<");
            }
            else if (s[i] == ' ') {
                while (!ns.empty()) {
                    printf("%c", ns.back());
                    ns.pop_back();
                }
                printf(" ");
            }
            else {
                ns.push_back(s[i]);
            }
        }
    }

    while (!ns.empty()) {
        printf("%c", ns.back());
        ns.pop_back();
    }
    return 0;
}
