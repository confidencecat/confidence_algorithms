#include <stdio.h>
using namespace std;

int n, c = 0;
int x[16]; 
bool r[16], md[32], nd[32];

void f(int col) {
    if (col == n) {
        c++;
        return;
    }
    for (int row = 0; row < n; row++) {
        if (!r[row] && !md[row-col+n] && !nd[row+col]) {
            x[col] = row;
            r[row] = md[row-col+n] = nd[row+col] = true;
            f(col + 1);
            r[row] = md[row-col+n] = nd[row+col] = false; 
        }
    }
}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d", &n);
    f(0);
    printf("%d\n", c);
    return 0;
}
