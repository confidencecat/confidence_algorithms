import sys
input=sys.stdin.readline

def f(l, r):
    if r<l:
        return
    global n
    global ans
    m=(l+r)//2
    t=0
    for i in li:
        t+=i//m
    if t>=n:
        ans=m
        f(m+1, r)
    else:
        f(l, m-1)

k, n = map(int, input().split())
li=[0]*k
for i in range(k):
    li[i]=int(input())
s = max(li)

ans=0
f(0, s*2)
print(ans)