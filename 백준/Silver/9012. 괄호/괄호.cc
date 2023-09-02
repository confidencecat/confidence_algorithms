#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int n, i, j, m;
	scanf("%d", &n);
	char str[51];
	i = 0;
	while (i < n) {
		scanf("%s", str);
		j = 0;
		m = 0;
		while (j < strlen(str)) {
			if (str[j] == '(') {
				m++;
			}
			else {
				m--;
			}
			if (m < 0) {
				printf("NO\n");
				break;
			}
			j++;
		}
		if (m == 0)
			printf("YES\n");
		else if (m > 0)
			printf("NO\n");
		i++;
	}
	return 0;
}
