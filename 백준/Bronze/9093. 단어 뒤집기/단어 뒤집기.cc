#include <stdio.h>
#include <string.h>

int main() {
  int t;
  scanf("%d", &t);
  getchar();
  while(t--){
    char s[1001], c[1001];
    int n, cn = 0;
    fgets(s, sizeof(s), stdin);
    n = strlen(s);
    if(s[n-1] == '\n') {
        s[n-1] = '\0';
        n--;
    }
    for(int i = 0; i < n; i++){
      if(s[i] != ' '){
        c[cn++] = s[i];
      }
      else{
        for(int j = cn - 1; j >= 0; j--){
          printf("%c", c[j]);
        }
        cn = 0;
        printf(" ");
      }
    }
    for(int j = cn - 1; j >= 0; j--){
      printf("%c", c[j]);
    }
    cn = 0;
    printf("\n");
  }
  return 0;
}
