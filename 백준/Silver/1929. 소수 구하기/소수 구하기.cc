#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int arr[1000001]; 


int main(){
	int m, n;
	scanf("%d %d", &m, &n);

	arr[0] = 1;
	arr[1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 2 * i; j < n + 1; j += i) {
			if (arr[j] == 0) {
				arr[j] = 1;
			}
		}
	}

	for (int i = m; i < n + 1; i++) {
		if (arr[i] == 0)
            printf("%d\n", i);
	}

	return 0;
}