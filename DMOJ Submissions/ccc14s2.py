n = int(input())

a = input().split(" ")
b = input().split(" ")

pair = []

for i in range(n):
    p = [a[i],b[i]]

    pr = p[:]

    pr.reverse()

    if pr not in pair:
        pair.append(p)

if len(pair) == n/2:
    print("good")
else:
    print("bad")