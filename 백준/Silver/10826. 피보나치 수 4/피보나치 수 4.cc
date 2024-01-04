#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 10000  // 최대 자릿수

// 두 큰 수를 더하는 함수
void addLargeNumbers(int result[], int a[], int b[]) {
    int carry = 0;
    for (int i = 0; i < MAX_DIGITS; i++) {
        int sum = a[i] + b[i] + carry;
        result[i] = sum % 10;  // 현재 자리수
        carry = sum / 10;      // 자릿수 올림
    }
}

// 큰 수를 복사하는 함수
void copyNumber(int dest[], int src[]) {
    for (int i = 0; i < MAX_DIGITS; i++) {
        dest[i] = src[i];
    }
}

// 큰 수 출력 함수
void printLargeNumber(int num[]) {
    int start = MAX_DIGITS;
    while (start > 0 && num[start - 1] == 0) {
        start--;  // 앞쪽의 0을 건너뛰기
    }
    if (start == 0) {
        printf("0");  // 모든 자리가 0인 경우
    }
    else {
        for (int i = start - 1; i >= 0; i--) {
            printf("%d", num[i]);
        }
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    int fib1[MAX_DIGITS] = { 0 };  // 첫 번째 수
    int fib2[MAX_DIGITS] = { 0 };  // 두 번째 수
    int result[MAX_DIGITS] = { 0 };  // 결과 저장

    fib1[0] = 1;  // 초기값 설정
    fib2[0] = 1;  // 초기값 설정

    if (n == 0) printf("0\n");
    else if (n <= 2) {
        printf("1\n");  // n이 2 이하인 경우 1 출력
    }
    else {
        for (int i = 3; i <= n; i++) {
            addLargeNumbers(result, fib1, fib2);  // 두 큰 수 더하기
            copyNumber(fib1, fib2);              // 다음 계산을 위해 복사
            copyNumber(fib2, result);            // 다음 계산을 위해 복사
        }
        printLargeNumber(result);  // 결과 출력
    }

    return 0;
}
