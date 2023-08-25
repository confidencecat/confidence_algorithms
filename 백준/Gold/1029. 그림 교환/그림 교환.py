import sys
input = sys.stdin.readline

def solution(n, arr):
    M = [[[0] * 10 for j in range(1 << n)] for i in range(n)]

    def dfs(artist, path, price):
        if M[artist][path][price] != 0:
            return M[artist][path][price]

        count = 0 
        for nextA in range(1, n):
            if arr[artist][nextA] < price or path & (1 << nextA) > 0: 
                continue
            count = max(count, 1 + dfs(nextA, path | (1 << nextA), arr[artist][nextA]))
        M[artist][path][price] = count

        return count

    return 1 + dfs(0, 1, 0) 

if __name__ == '__main__':
    n = int(input())
    arr = []
    for i in range(n):
        arr.append([int(j) for j in input().strip()])
    result = solution(n, arr)
    print(result)