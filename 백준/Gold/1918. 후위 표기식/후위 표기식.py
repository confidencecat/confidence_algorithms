def p(n):
    if n in ['(', ')']:
        return 0
    elif n in ['+', '-']:
        return 1
    elif n in ['*', '/']:
        return 2

c = input()
a = []

for i in c:
    if i.isalnum():
        print(i, end='')
    elif i in ['+', '-', '*', '/']:
        while a and p(i) <= p(a[-1]):
            print(a.pop(), end='')
        a.append(i)
    elif i == '(':
        a.append(i)
    elif i == ')':
        k = a.pop()
        while k != '(':
            print(k, end='')
            k = a.pop()

while a:
    print(a.pop(), end='')
