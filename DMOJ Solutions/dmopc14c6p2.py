n = int(input())

t = int(input().split(" ")[0])
min = t
max = t

for i in range(n-2):
    p,m = map(int,input().split(" "))
    min -= m
    if i == 0:
        max -= m
    elif t - m < max:
        max -= max-(t - m)

    t += p - m

if min < 0:
    print(0)
else:
    print(min)

if max < 0:
    print(0)
else:
    print(max)