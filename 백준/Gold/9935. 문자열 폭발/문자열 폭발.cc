#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 1000001
char str[MAX_LEN], bomb[MAX_LEN];
char result[MAX_LEN];
int str_len, bomb_len, result_len = 0;
bool found;

int main() {
    scanf("%s", str);
    scanf("%s", bomb);

    str_len = strlen(str);
    bomb_len = strlen(bomb);

    for (int i = 0; i < str_len; i++) {
        result[result_len++] = str[i];

        if (result_len >= bomb_len && result[result_len - bomb_len] == bomb[0]) {
            found = true;
            for (int j = 0; j < bomb_len; j++) {
                if (result[result_len - bomb_len + j] != bomb[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                result_len -= bomb_len;
            }
        }
    }

    if (result_len == 0) {
        printf("FRULA\n");
    }
    else {
        result[result_len] = '\0';
        printf("%s\n", result);
    }

    return 0;
}

