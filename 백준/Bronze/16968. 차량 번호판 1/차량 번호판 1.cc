#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>

char s[5];
int n, dp[5];

int main() {
	//freopen("input.txt", "rt", stdin);
	
	scanf("%s", s);
	n = strlen(s);

	dp[0] = s[0] == 'c' ? 26 : 10;
	for (int i = 1; i < n; i++) {
		if (s[i] == 'c') {
			dp[i] = dp[i - 1] * 26;
			if(s[i - 1] == 'c') dp[i] -= dp[i - 1];
		}
		else {
			dp[i] = dp[i - 1] * 10;
			if (s[i - 1] == 'd') dp[i] -= dp[i - 1];
		}
	}
	printf("%d\n", dp[n - 1]);
	return 0;
}