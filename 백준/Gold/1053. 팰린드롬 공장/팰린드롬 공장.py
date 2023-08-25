from itertools import *

def f(start,end,d):
  for i,j in [(1,0),(0,1),(1,1)]:
    if d[start+i][end-j]==N:
      f(start+i,end-j,d)
    d[start][end] = min(d[start][end],d[start+i][end-j]+int(not(i and j and seq[start]==seq[end])))

def palin():
  if N==1:
    return 0
  d = [[N*int(i<j) for j in range(N)] for i in range(N)]
  f(0,N-1,d)
  return d[0][-1]

seq = [*input()]; N = len(seq)

result = palin()
for i,j in combinations(range(N),2):
  seq[i],seq[j] = seq[j],seq[i]
  result = min(result,palin()+1)
  seq[i],seq[j] = seq[j],seq[i]
print(result)