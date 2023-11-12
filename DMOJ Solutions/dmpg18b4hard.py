n,m,x = map(int, input().split(" "))

nums = input().split(" ")
nums = [int(o) for o in nums]

dens = input().split(" ")
dens = [int(o) for o in dens]

close = []

for i in dens:
    c = 0
    check = False
    avg = []
    for j in nums:
        if i < j:
            check = True
            break
        else:
            avg.append(j/i)

    for y in avg:
        c += y

    if check:
        close.append([-1,-1])
    else:
        if c / len(avg) < 0.5:
            close.append([-1,-1])
        else:
            c = abs(x - c / len(avg))
            close.append([c,i])

close.sort()

output = "Shimnanigans have failed"
closeness = -1

for i in close:

    if closeness >= 0:
        if i[0] == closeness:
            if i[1] > output:
                output = i[1]
        else:
            break

    elif i[0] >= 0:
        output = i[1]
        closeness = i[0]

print(output)