#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
    //freopen("input.txt", "rt", stdin);
    int A, B, C, X, Y;
    scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);

    int cost1 = A * X + B * Y;

    int cost2 = 2 * C * (X > Y ? X : Y);

    int minXY = X < Y ? X : Y;
    int cost3 = C * 2 * minXY + A * (X - minXY) + B * (Y - minXY);

    int minCost = cost1 < cost2 ? (cost1 < cost3 ? cost1 : cost3) : (cost2 < cost3 ? cost2 : cost3);

    printf("%d\n", minCost);

    return 0;
}
