n,d = map(int,input().split(" "))

intervals = list(map(int,input().split(" ")))

arr = []

d = abs(d)

for i in intervals:
    if d // i * i == d:
        arr.append(d//i)

if len(arr) == 0:
    print("This is not the best time for a trip.")
else:
    arr.sort()
    print(arr[0])