#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n;
long long a[5001], ansa, ansb, ansc, mi = 3000000003;

int com(const void* first, const void* second) {
    return *(long long int*)first - *(long long int*)second;
}

int main() {
    //freopen("input.txt", "rt", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    qsort(a, n, sizeof(long long int), com);
    /*for (int i = 0; i < n; i++) printf("%lld  ", a[i]);
    printf("\n");*/
    
    //처음에는 두포인터로 양 끝 값을 줄이면서 가운데 값들을 이분탐색을 통해 찾을려고 했었음.
    //하지만 그렇게 하면 0에 가장 가까워지는 경우의 수를 지나치는 경우가 생김
    //그래서 아래와 같은 방법을 사용함
    
    for (int i = 0; i < n - 2; i++) {
        int s = i + 1, e = n - 1;
        while (s < e) {
            long long int sum = a[i] + a[s] + a[e];

            if (abs(sum) < abs(mi)) {
                ansa = a[i]; ansb = a[s]; ansc = a[e];
                mi = sum;
            }

            if (sum > 0) e--;
            else if (sum < 0) s++;
            else {
                printf("%lld %lld %lld", ansa, ansb, ansc);
                return 0;
            }
        }
    }
    printf("%lld %lld %lld\n", ansa, ansb, ansc);
    return 0;
}

