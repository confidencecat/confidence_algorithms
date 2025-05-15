#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int n, m;

char c(int x) {
    if (x < 10) return (x + '0');
    else return (x-10 + 'A');
}

void f(int x) {
    if (x == 1) printf("%d", x);
    else if(x > 1){
        f(x / m);
        printf("%c", c(x % m));
    }
}


int main() {

    scanf("%d %d", &n, &m);
    f(n);
    
    return 0;
}
