#include <stdio.h>
#define mx(a, b) ((a) < (b) ? (b) : (a))
#define as(a) ((a) < 0 ? -(a) : (a))

int main(){
    int a, b, c;
    while(scanf("%d %d %d", &a, &b, &c) != EOF){
        printf("%d\n", mx(as(a - b), as(c - b))-1);
    }
    return 0;
}