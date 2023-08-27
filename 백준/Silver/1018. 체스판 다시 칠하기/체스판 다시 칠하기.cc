#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	//freopen("input.txt", "rt", stdin);
    char arr[50][51];
    int a, b;

    scanf("%d %d", &a, &b);
    for (int i = 0; i < a; i++)
        scanf("%s", arr[i]);

    int minChanges = 2500;

    for (int x = 0; x <= a - 8; x++) {
        for (int y = 0; y <= b - 8; y++) {
            int startW = 0, startB = 0;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if ((i + j) % 2 == 0) {
                        if (arr[x + i][y + j] != 'W') startW++;
                        if (arr[x + i][y + j] != 'B') startB++;
                    }
                    else {
                        if (arr[x + i][y + j] != 'B') startW++;
                        if (arr[x + i][y + j] != 'W') startB++;
                    }
                }
            }
            int changes = startW < startB ? startW : startB;
            if (changes < minChanges) minChanges = changes;
        }
    }
    printf("%d", minChanges);


	return 0;
}