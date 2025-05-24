N = int(input())
graph = [[*map(int,input().split())] for _ in range(N)]
DP = [[1e9]*N for i in range(N)]
DP[0][0] = 0
for start in range(1,N):
  for end in range(start):
    DP[start][end] = min(DP[start][end],graph[start][start-1]+DP[start-1][end])
    DP[start][start-1] = min(DP[start][start-1],graph[start][end]+DP[start-1][end])
print(min(DP[-1]))