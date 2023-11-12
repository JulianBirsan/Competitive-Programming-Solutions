n = int(input())

dict = {}
big = 0
bignum = 0
out = ""

for i in range(n):
    a,b = input().split(" ")
    dict[b] = [a,0]

d = int(input())

for i in range(d):
    num = input()
    dict[num][1] += 1

for i in dict.keys():
    if dict[i][1] > big:
        big = dict[i][1]
        bignum = int(i)
        out = dict[i][0]
    elif dict[i][1] == big:
        if int(i) < bignum:
            bignum = int(i)
            big = dict[i][1]
            out = dict[i][0]

print(out)