n = int(input())

col = input().split(" ")

cols = [0,0,0,0,0,0]

for i in col:
    if i == "red":
        cols[0] += 1
    elif i == "orange":
        cols[1] += 1
    elif i == "yellow":
        cols[2] += 1
    elif i == "green":
        cols[3] += 1
    elif i == "blue":
        cols[4] += 1
    else:
        cols[5] += 1

cols.sort()

ind = 1
t = 0

for i in range(5):
    t += cols[i]

if cols[5] <= t:
    t += cols[5]

else:

    while ind < 5:
        cols[ind] -= cols[ind-1]
        ind += 1

    cols[5] -= 2*cols[4]

    t += t + 1

print(t)