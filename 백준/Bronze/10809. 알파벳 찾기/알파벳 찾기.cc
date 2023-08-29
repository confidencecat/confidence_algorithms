#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>

int main() {
	int cnt[26] = { 0 , };
	char s[101];
	scanf("%s", s);
	for (int i = 0; i < strlen(s); i++) {
		if (cnt[s[i] - 'a'] == 0) cnt[s[i] - 'a'] = i + 1;
	}

	for (int i = 0; i < 26; i++) {
		if (cnt[i] == 0) printf("-1 ");
		else printf("%d ", cnt[i] - 1);
	}

	return 0;
}