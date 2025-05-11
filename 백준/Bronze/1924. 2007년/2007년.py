m = [0,31,28,31,30,31,30,31,31,30,31,30,31]
w = ["SUN","MON","TUE","WED","THU","FRI","SAT"]
x, y = map(int, input().split())
s = sum(m[1:x]) + y
print(w[s % 7])
