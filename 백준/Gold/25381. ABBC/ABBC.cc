#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

int n, ab = 0, ans = 0;
char s[300002];
bool ch[300002];

int main() {
    //freopen("input.txt", "rt", stdin);
    
    scanf("%s", s);
    n = strlen(s);
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            q.push(i);
        }
        else if(s[i] == 'C' && !q.empty()) {
            ch[q.front()] = true;
            q.pop();
            ans++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') ab++;
        else if(s[i] == 'B' && ab != 0 && ch[i] == false) {
            ans++;
            ab--;
            ch[i] = true;
        }
    }

    printf("%d\n", ans);

    return 0;
}

