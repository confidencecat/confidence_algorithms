import sys
input = sys.stdin.readline

n, m = map(int, input().split())
h = set()
s = set()

for _ in range(n):
    a = input().strip()
    h.add(a)

for _ in range(m):
    a = input().strip()
    s.add(a)

ans = sorted(list(h & s))

print(len(ans), *ans, sep="\n")