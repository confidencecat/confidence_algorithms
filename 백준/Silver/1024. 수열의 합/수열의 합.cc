#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    // freopen("input.txt", "rt", stdin);

    int n, l;

    scanf("%d %d", &n, &l);

    for (int i = l; i <= 100; i++) {
        int temp = n - (i * (i - 1)) / 2;  // N에서 길이 i에 따른 초기 값을 차감
        if (temp % i == 0) {              // temp가 i로 나누어 떨어지는지 확인
            int a1 = temp / i;            // 첫 번째 항 계산
            if (a1 >= 0) {                // 첫 번째 항이 음이 아닌지 확인
                for (int j = 0; j < i; j++) {
                    printf("%d ", a1 + j);  // 수열 출력
                }
                return 0;                   // 성공 시 종료
            }
        }
    }
    printf("-1");  // 조건에 맞는 수열이 없을 경우
    return 0;
}
