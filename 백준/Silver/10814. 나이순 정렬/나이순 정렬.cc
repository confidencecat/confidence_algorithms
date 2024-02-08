#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char arr[200][10000];

int main() {
    //freopen("input.txt", "rt", stdin);
    int n, age;
    char name[101];

    for (int i = 0; i < 200; i++) {
        arr[i][0] = '\0';
    }

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %s", &age, name);
        char temp[200];
        sprintf(temp, "%d %s\n", age, name);
        strcat(arr[age - 1], temp);
    }

    for (int i = 0; i < 200; i++) {
        if (arr[i][0] != '\0') {
            printf("%s", arr[i]);
        }
    }

    return 0;
}
