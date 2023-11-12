board = []

for i in range(8):
    board.append([False,False,False,False,False,False,False,False])

first = list(map(int,input().split(" ")))
first[0] -= 1
first[1] -= 1

end = list(map(int,input().split(" ")))
end[0] -= 1
end[1] -= 1

q = ["a"]
q2 = []

count = 0

board[0][0] = True

def bfs(s,e):
    global count
    q.remove(q[0])

    for x in range(8):
        for y in range(8):
            if (abs(x-s[0]) == 1 and abs(y-s[1])) == 2 or (abs(x-s[0]) == 2 and abs(y-s[1]) == 1) and not board[x][y]:
                if x == end[0] and y == end[1]:
                    return True
                else:
                    q2.append([x,y])
                    board[x][y] = True

    if len(q) == 0:
        count += 1

        for i in q2:
            q.append(i)

    return bfs(q[0],e)


bfs(first,end)

if end == first:
    print(0)

else:

    print(count + 1)