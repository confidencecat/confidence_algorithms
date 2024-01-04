import sys
input = sys.stdin.readline

n = int(input().strip())
numbers = list(map(int, input().split()))
m = int(input().strip())
check = list(map(int, input().split()))

numbers.sort()

def binary_search(start, end, target):
    if start > end:
        return print(0)
    
    mid = (start + end) // 2
    
    if target == numbers[mid]:
        return print(1)
    elif target < numbers[mid]:
        binary_search(start, mid-1, target)
    elif target > numbers[mid]:
        binary_search(mid+1, end, target)


for e in check:
    binary_search(0, len(numbers) - 1, e)