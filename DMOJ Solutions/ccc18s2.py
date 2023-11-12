n = int(input())

y = n-1

table = []


for i in range(n):
    row = list((map(int,input().split(" "))))
    table.append(row)



def rotate(arr):

    rc = 0
    cc = 0

    copy = []


    for i in range(n):
        temp = ["" for j in range(n)]
        copy.append(temp)

    for i in range(n):
        for j in range(n-1):
            if arr[i][j] < arr[i][j+1]:
                rc += 1

    for j in range(n):
        for i in range(n-1):
            if arr[i][j] < arr[i+1][j]:
                cc += 1

    if rc == (n-1)*n and cc == (n-1)*n:
        return arr

    
    for i in range(n):
        for j in range(n):
            copy[j][y - i] = arr[i][j]

    return rotate(copy)

out = rotate(table)

for i in range(n):
    for j in range(n):
        if j == n-1:
            print(out[i][j])
        else:
            print(out[i][j],end=" ")