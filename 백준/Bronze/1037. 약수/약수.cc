#include <stdio.h>
#include <stdlib.h>

int com(const void* A, const void *B){
  return *(int*)A - *(int*)B;
}

int main() {
  int n, a[51];
  scanf("%d", &n);

  for (int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }


  qsort(a, n, sizeof(int), com);



  if(n % 2 == 0) printf("%d\n", a[n/2] * a[n / 2 - 1]);
  else printf("%d\n", a[n/2] * a[n/2]);
  
  return 0;
}