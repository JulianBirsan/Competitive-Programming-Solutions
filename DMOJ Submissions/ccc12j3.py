k = int(input())

for i in range(3):
    if i == 0:
        for m in range(k):
            row = ["" for a in range(k*3)]
            for b in row:
                if row.index(b) < k or row.index(b) > k * 2 -1:
                    row.insert(row.index(b), "*")
                    row.remove(b)
                else:
                    row.insert(row.index(b), "x")
                    row.remove(b)
            count = 0
            for r in row:
                if count == k*3-1:
                    print(r)
                else:
                    print(r, end="")
                count += 1
    elif i == 1:
        for m in range(k):
            row = ["" for a in range(k*3)]
            for b in row:
                if row.index(b) < k:
                    row.insert(row.index(b), " ")
                    row.remove(b)
                else:
                    row.insert(row.index(b), "x")
                    row.remove(b)
            count = 0
            for r in row:
                if count == k * 3 - 1:
                    print(r)
                else:
                    print(r, end="")
                count += 1
    else:
        for m in range(k):
            row = ["" for a in range(k*3)]
            for b in row:
                if row.index(b) < k or row.index(b) > k * 2 - 1:
                    row.insert(row.index(b), "*")
                    row.remove(b)
                else:
                    row.insert(row.index(b), " ")
                    row.remove(b)
            count = 0
            for r in row:
                if count == k * 3 - 1:
                    print(r)
                else:
                    print(r, end="")
                count += 1