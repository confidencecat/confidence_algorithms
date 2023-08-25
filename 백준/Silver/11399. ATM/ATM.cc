#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	//freopen("input.txt", "rt", stdin);
	int n, m = 0, answer = 0;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);//입력
	}
	sort(a.begin(), a.end());//정렬
	for (int i = 0; i < n; i++) {
		m += a[i];//i + 1번째 사람이 기다리는 시간
		answer += m;//총 기다리는 시간
	}
	printf("%d", answer);
	return 0;
}