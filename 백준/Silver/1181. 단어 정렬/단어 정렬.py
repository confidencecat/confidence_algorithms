n = int(input())
a = set()

for _ in range(n):
    b = input()
    a.add(b)

a = sorted(a, key=lambda x: (len(x), x))

for word in a:
    print(word)
