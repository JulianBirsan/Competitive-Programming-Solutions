table = []
next = []
dir = "d"

for i in range(50):
    next.append(i+1)
    next.append(i+1)

for i in range(10):
    temp = []
    for j in range(10):
        temp.append("")
    table.append(temp)


x = int(input())
y = int(input())

table[4][4] = x

pos = [4,4]

for i in range(x+1,y+1):
    if next[0] == 0:
        if dir == "d":
            dir = "r"
        elif dir == "r":
            dir = "u"
        elif dir == "u":
            dir = "l"
        else:
            dir = "d"

        next.remove(next[0])


    next[0] -= 1

    if dir == "d":
        pos[0] += 1
    elif dir == "r":
        pos[1] += 1
    elif dir == "u":
        pos[0] -= 1
    else:
        pos[1] -= 1

    table[pos[0]][pos[1]] = i

rem = []

for i in table:
    count = 0
    for j in i:
        if j == "":
            count += 1
    if count == 10:
        rem.append(i)

for i in rem:
    table.remove(i)

for i in range(len(table)):
    for j in range(10):
        if table[i][j] == "":
            if i == len(table)-1:
                table[i][j] = "x"
            elif table[i+1][j] == "":
                table[i][j] = "x"

for i in table:
    for j in i:
        if j == "x":
            i.remove(j)

output = ""

for i in table:
    string = ""
    for j in i:
        if j != "x":
            string += str(j) + " "
    output += string + "\n"

print(output.rstrip())