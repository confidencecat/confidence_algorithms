int Euclidean(int a, int b){
  if(b == 0) return a;
  return Euclidean(b, a % b);
}
