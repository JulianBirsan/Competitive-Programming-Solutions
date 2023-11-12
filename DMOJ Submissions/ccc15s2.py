j = int(input())

a = int(input())

jerseys = []

for i in range(j):
    jer = input()
    if jer == "S":
        jer = 1
    elif jer == "M":
        jer = 2
    else:
        jer = 3

    jerseys.append(jer)

count = 0

for i in range(a):
    req = input().split(" ")
    if req[0] == "S":
        req[0] = 1
    elif req[0] == "M":
        req[0] = 2
    else:
        req[0] = 3
    if jerseys[int(req[1])-1] >= req[0]:
        count += 1
        jerseys[int(req[1])-1] = False

print(count)