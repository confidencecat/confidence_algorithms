#include<stdio.h>
#define l long long
#define fr(A,S,E) for(int A=S;A<=E;A++)
l c[103]={1,},d[103],m,n;int main(){scanf("%d%lld",&n,&m);fr(i,1,n+2)fr(j,0,i-1)c[i]=(c[i]+(c[j]*c[i-j-1]%m))%m;fr(i,1,n){d[i]=(2*c[i+1]+c[i]-c[i+2]+m)%m;fr(j,1,i-1)d[i]=(d[i]+((2*(i-j)+1)*c[j]%m*c[i-j]%m))%m;fr(j,1,i)d[i]=(d[i]+(((c[j-1]*d[i-j])+(d[j-1]*c[i-j]))%m))%m;}fr(i,1,n)printf("%lld ",d[i]);}
