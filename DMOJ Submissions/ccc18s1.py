n = int(input())
arr = []

for i in range(n):
    arr.append(int(input()))

arr.sort()

out = 2000000001

for i in range(1,n-1):
    l = abs((arr[i]-arr[i-1])/2)
    r = abs((arr[i]-arr[i+1])/2)
    s = l + r
    out = min(out,s)

print(round(out,1))