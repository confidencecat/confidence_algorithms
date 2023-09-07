import sys
input = sys.stdin.readline

n, m = map(int, input().split())
ans = {}

for _ in range(n):
    a, b = input().split()
    ans[a] = b

for _ in range(m):
    print(ans[input().rstrip()])