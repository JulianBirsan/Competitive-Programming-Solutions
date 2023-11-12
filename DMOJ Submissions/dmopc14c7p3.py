n = int(input())

a,b = map(int,input().split(" "))

dict = {}

tot = 0

ah = list(map(int,input().split(" ")))

bh = list(map(int,input().split(" ")))

for i in ah:
    dict[i] = [i,0]

for i in bh:
    if i in dict:
        dict[i][1] = i

for i in dict:
    if 0 not in dict[i]:
        tot += 1


print(n-tot)