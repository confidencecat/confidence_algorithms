import sys

n = int(sys.stdin.readline())
a = [[0]*2 for _ in range(n)]
for i in range(n):
    s, e = map(int, sys.stdin.readline().split())
    a[i][0] = s
    a[i][1] = e

a.sort(key = lambda x: (x[1], x[0]))
cnt = 1
end_time = a[0][1]
for i in range(1, n):
    if a[i][0] >= end_time:
        cnt += 1
        end_time = a[i][1]
        
print(cnt)