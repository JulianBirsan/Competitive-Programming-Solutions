grid = []
x = False
o = False

for i in range(3):
    row = list(input())
    grid.append(row)
    if "X" not in row:
        o = True
    elif "O" not in row:
        x = True

for i in range(3):
    if grid[0][i] == grid[1][i] == grid[2][i]:
        if grid[0][i] == "X":
            x = True
        else:
            o = True

if grid[0][0] == grid[1][1] == grid[2][2]:
    if grid[0][0] =="X":
        x = True
    else:
        o = True

if grid[0][2] == grid[1][1] == grid[2][0]:
    if grid[1][1] == "X":
        x = True
    else:
        o = True

if x and o:
    print("Error, redo")
elif x:
    print("Timothy")
elif o:
    print("Griffy")
else:
    print("Tie")