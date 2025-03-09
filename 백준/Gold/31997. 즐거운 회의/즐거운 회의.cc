#include <stdint.h>
#include <unistd.h>
#define FIX __attribute__((__optimize__("-fno-tree-loop-distribute-patterns")))
FIX char*M(char*a,int b,size_t c){for(size_t i=0;i<c;i++)a[i]=b;return a;}
FIX char*C(char*a,char*b,size_t c){for(size_t i=0;i<c;i++)a[i]=b[i];return a;}
#define WRITER_BUF 32768
typedef struct{char b[WRITER_BUF];int k;}S;S*O;
void F(){write(1,O->b,O->k);O->k=0;}
void L(const char*a,int b){int i=0;while(i<b){if(O->k==WRITER_BUF)F();int r=b-i,s=WRITER_BUF-O->k,p=r<s?r:s;for(int j=0;j<p;j++)O->b[O->k+j]=a[i+j];O->k+=p;i+=p;}}
void I(int64_t v){char a[32];int p=32,s=(v<0);uint64_t u=v;if(s)u=-u;do{a[--p]=u%10+'0';u/=10;}while(u);if(s)a[--p]='-';if(O->k+32-p>WRITER_BUF)F();for(int j=p;j<32;j++)O->b[O->k+j-p]=a[j];O->k+=32-p;}
[[noreturn]] void H(){F();_exit(0);}
#define READER_BUF 32768
typedef struct{char b[READER_BUF];int p,e;}T;T*Rr;
void P(){Rr->p=0;Rr->e=read(0,Rr->b,READER_BUF);if(Rr->e==0)H();}
void Q(){for(;;){for(int i=Rr->p;i<Rr->e;i++)if(Rr->b[i]>' '){Rr->p=i;return;}P();}}
int64_t J(){Q();if(Rr->p==Rr->e)P();int s=Rr->b[Rr->p]=='-';Rr->p+=s;uint64_t u=0;for(;;){for(int i=Rr->p;i<Rr->e;i++){if(Rr->b[i]<'0'||Rr->b[i]>'9'){Rr->p=i;return s?-u:u;}else u=Rr->b[i]-'0'+u*10;}P();}}
int X(int a,int b){return a>b?a:b;}
int Y(int a,int b){return a<b?a:b;}
int main(){S s;s.k=0;O=&s;T t;t.p=t.e=0;Rr=&t;int32_t n=J(),m=J(),d=J();int32_t A[200000],B[200000];for(int i=0;i<n;i++){A[i]=J();B[i]=J();}int32_t C[200001];for(int i=0;i<d;i++)C[i]=0;for(int i=0;i<m;i++){int a=J(),b=J(),p=a-1,q=b-1,r=X(A[p],A[q]),u=Y(B[p],B[q]);if(r<u){C[r]++;C[u]--;}}int32_t z=0;for(int i=0;i<d;i++){z+=C[i];I(z);L("\n",1);}H();}
