#include <cstdio>
#include <cstring>
#include <list>
using namespace std;

char str[600000];

int main() {
    list<char> l;
    list<char>::iterator cursor;
    int N;
    int length;

    scanf("%s", str);
    scanf("%d", &N);

    length = strlen(str);

    for (int i = 0; i < length; i++)
        l.push_back(str[i]);

    cursor = l.end();

    for (int i = 0; i < N; i++) {
        char edit;
        scanf(" %c", &edit);

        switch (edit) {
        case 'L':
            if (cursor == l.begin())
                continue;
            else
                cursor--;

            break;

        case 'D':
            if (cursor == l.end())
                continue;
            else
                cursor++;

            break;

        case 'B':
            if (cursor == l.begin())
                continue;
            else {
                cursor--;
                cursor = l.erase(cursor);
            }

            break;

        case 'P':
            char c;
            scanf(" %c", &c);
            l.insert(cursor, c);

            break;
        }
    }
    while (!l.empty()) {
        printf("%c", l.front());
        l.pop_front();
    }

    return 0;
}