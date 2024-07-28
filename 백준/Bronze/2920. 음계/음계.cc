#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int arr[8], as = 0, ds = 0;
    for (int i = 0; i < 8; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 4; i++) {
        if (arr[i] == i + 1 && arr[i] + arr[7 - i] == 9) {
            as++;
        }
        else if (arr[7 - i] == i + 1 && arr[i] + arr[7 - i] == 9) {
            ds++;
        }
    }

    if (as == 4)
        printf("ascending");
    else if (ds == 4)
        printf("descending");
    else
        printf("mixed");

}