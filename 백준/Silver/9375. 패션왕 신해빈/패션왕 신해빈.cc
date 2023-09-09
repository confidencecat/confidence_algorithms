#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

int main(){
    int t,n;
    map<string,int>::iterator iter;
    string a,b;
    int ans;

    scanf("%d",&t);

    while(t--){
        map<string,int> m;

        scanf("%d",&n);

        for(int i=0;i<n;i++){
            cin >> a >> b;

            m[b]++;
        }

        ans = 1;

        for(iter=m.begin();iter!=m.end();iter++)
            ans *= (iter->second+1);

        printf("%d\n",ans-1);
    }

    return 0;
}