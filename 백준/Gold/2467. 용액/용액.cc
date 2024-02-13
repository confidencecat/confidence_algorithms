#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define abs(a) a < 0 ? -1 * a : a

int n, start, end, mid;
long long int  arr[100001], sum, ans = 2000000001, ans1, ans2;

int main() {
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);

	start = 0;
	end = n - 1;

	while (start < end) {
		sum = arr[start] + arr[end];
		if (sum == 0) {
			ans1 = arr[start];
			ans2 = arr[end];
			break;
		}
		if ((abs(sum)) < ans) {
			ans = abs(sum);
			ans1 = arr[start];
			ans2 = arr[end];
		}
		
		if (sum < 0) start++;
		else end--;
	}

	printf("%lld %lld\n", ans1, ans2);
	return 0;
}