#include <stdio.h>
long long int n, i = 1;
int main() {
    scanf("%lld", &n);
    for (long long int s = 0; i <= 2147483648LL && (s += i) <= n; i++);
    printf("%lld\n", i - 1);
    return 0;
}
