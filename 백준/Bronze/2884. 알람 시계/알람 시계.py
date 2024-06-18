a, b = map(int, input().split())

if b >= 45:
    print(a, b - 45)
else:
    print(23 if a == 0 else (a - 1), 60 + (b - 45))