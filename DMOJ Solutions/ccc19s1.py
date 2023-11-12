s = input()

arr = [["1","2"],["3","4"]]

for x in s:
    if x == "H":
        temp = arr[0][0]
        temp2 = arr[0][1]
        arr[0][0] = arr[1][0]
        arr[1][0] = temp
        arr[0][1] = arr[1][1]
        arr[1][1] = temp2

    else:
        temp = arr[0][0]
        temp2 = arr[1][0]
        arr[0][0] = arr[0][1]
        arr[0][1] = temp
        arr[1][0] = arr [1][1]
        arr[1][1] = temp2

print(arr[0][0] + " " + arr[0][1])
print(arr[1][0] + " " + arr[1][1])