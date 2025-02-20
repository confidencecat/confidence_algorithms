#include <stdio.h>
#define MOD 1000000007

int main(){
    int n;
    scanf("%d", &n);
    
    int a[5000];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    
    int nondec[5000], noninc[5000];
    nondec[n - 1] = n - 1;
    noninc[n - 1] = n - 1;
    for(int i = n - 2; i >= 0; i--){
        if(a[i] <= a[i + 1])
            nondec[i] = nondec[i + 1];
        else
            nondec[i] = i;
        
        if(a[i] >= a[i + 1])
            noninc[i] = noninc[i + 1];
        else
            noninc[i] = i;
    }
    
    long long dp[5001] = {0};
    dp[0] = 1;
    
    for(int i = 0; i < n; i++){
        int r = (nondec[i] > noninc[i]) ? nondec[i] : noninc[i];
        for(int j = i; j <= r; j++){
            dp[j + 1] = (dp[j + 1] + dp[i]) % MOD;
        }
    }
    
    printf("%lld\n", dp[n]);
    return 0;
}
