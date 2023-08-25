N = int(input())
mapp = []
mapp.append((1,1,1,1))
for i in range(1,N+1):
    a,b,c = map(int, input().split())
    mapp.append((i,a,b,c))
 
dp = [0]*(N+1)
mapp.sort(key = lambda x: x[3])
 
for i in range(1,N+1):
    for j in range(0,i):
        if mapp[i][1]>mapp[j][1]:
            dp[i] = max(dp[i], dp[j]+mapp[i][2])
            
max_height = max(dp)
 
index = N
history = []
 
while index!=0:
    if dp[index]==max_height:
        history.append(mapp[index][0])
        max_height-=mapp[index][2]
    index-=1
    
print(len(history))
history.reverse()
for i in history:
    print(i)