q = input()
n = int(input())
d = input().split(" ")
p = input().split(" ")

d = [int(x) for x in d]
p = [int(x) for x in p]

if q == "1":
    d.sort()
    p.sort()
elif q == "2":
    d.sort()
    p.sort(reverse=True)

total = 0

for i in range(n):
    if d[i] > p[i]:
        total += d[i]
    else:
        total += p[i]

print(total)