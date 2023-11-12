import sys
input = sys.stdin.readline

n = int(input())

names = {}

for i in range(n):
    a = input()
    if a in names:
        names[a] += 1
    else:
        names[a] = 1

for i in range(n-1):
    a = input()

    names[a] -= 1


for i in names.keys():
    if names[i] == 1:
        print(i)
        break