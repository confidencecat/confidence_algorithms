#include <stdio.h>
#include <string.h>

int n, a[27];
char s[101];

int main(){
    scanf("%s", s);
    n = strlen(s);
    for(int i = 0; i < n; i++) a[s[i] - 'a']++;
    for(int i =0; i < 26; i++) printf("%d ", a[i]);
    
    return 0;
}