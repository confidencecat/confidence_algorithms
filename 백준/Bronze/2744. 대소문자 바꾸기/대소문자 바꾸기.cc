#include <stdio.h>
#include <ctype.h>

int main() {
    char word[101];

    scanf("%s", word);

    for (int i = 0; word[i] != '\0'; i++) {
        if (islower(word[i])) {
            word[i] = toupper(word[i]);
        } else if (isupper(word[i])) {
            word[i] = tolower(word[i]);
        }
    }

    printf("%s\n", word);

    return 0;
}
