#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ans[200000];
int s[100000], top = -1;

int main() {
    int n;
    scanf("%d", &n);

    int* a = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int m = 1;
    int b = 0, rb = 0;
    while (1) {
        if (top == -1 || s[top] < a[b]) {
            s[++top] = m++;
            ans[rb++] = '+';
        }
        else if (s[top] == a[b]) {
            top--;
            ans[rb++] = '-';
            b++;
        }
        else {
            printf("NO\n");
            return 0;
        }
        if (rb == n * 2) break;
    }

    for (int i = 0; i < rb; i++)
        printf("%c\n", ans[i]);

    return 0;
}