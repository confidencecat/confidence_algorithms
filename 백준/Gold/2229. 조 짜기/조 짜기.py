n = int(input())
a = list(map(int, input().split()))

mx = 0
mn = 0
s = [0] * (n + 1)
for i in range(n):
    mx = a[i]
    mi = a[i]
    for j in  range(i, -1, -1):
        mx = max(mx, a[j])
        mi = min(mi, a[j])
        s[i + 1] = max(s[i + 1], s[j] + mx - mi)
print(s[n])