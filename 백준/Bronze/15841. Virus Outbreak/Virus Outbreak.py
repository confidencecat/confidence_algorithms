fib = [0] * 491
fib[0], fib[1] = 0, 1

for i in range(2, 491):
    fib[i] = fib[i-1] + fib[i-2]

while True:
    hour = int(input())
    if hour == -1:
        break
    print(f"Hour {hour}: {fib[hour]} cow(s) affected")
