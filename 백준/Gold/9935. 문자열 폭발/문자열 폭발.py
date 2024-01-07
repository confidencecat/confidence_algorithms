import sys

a = sys.stdin.readline().rstrip()
b = sys.stdin.readline().rstrip()

stack = []
n = len(b)

for i in range(len(a)):
    stack.append(a[i])
    if ''.join(stack[-n:]) == b:
        for _ in range(n):
            stack.pop()

if stack:
    print(''.join(stack))
else:
    print('FRULA')