from collections import Counter
import sys
#sys.stdin = open("input.txt", "r")

def statistics(a):
    a.sort()

    n = Counter(a).most_common(2)

    print(round(sum(a) / len(a)))
    print(a[len(a) // 2])

    if len(n) > 1:
        if n[0][1] == n[1][1]:
            print(n[1][0])
        else:
            print(n[0][0])
    else:
        print(n[0][0])
    print(max(a) - min(a))


if __name__ == "__main__":
    numbers = []
    for _ in range(int(sys.stdin.readline())):
        num = int(sys.stdin.readline())
        numbers.append(num)

    statistics(a=numbers)